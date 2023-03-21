
//
// Included Files
//
#include "common.h"     // Device Headerfile and Examples Include File

#include "hrepwm_driver.h"

#include "adcint1_isr.h"

#include "cpu_timer_driver.h"

//
// Function Prototypes
//

//normal function
void gpio_init();
static void main_loop_1ms(void);
void InitPie(void);
void InitIsr(void);

//
// Globals variable
//
uint32_t  EPwm1TimerIntCount;


void main(void)
{


    gpio_init();

    //
    // WARNING: Always ensure you call memcpy before running any functions from
    // RAM InitSysCtrl includes a call to a RAM based function and without a
    // call to memcpy first, the processor will go "into the weeds"
    //
#ifdef _FLASH
    memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);
#endif

    static uint8_t cnt_200us_mwait = 0;
    //init system control
    InitSysCtrl();

    //init interrupt
    InitPie();
    InitIsr();

    //intit epwm1
    Init_epwm1();    // epwm is used for interrupt timer function
    Init_epwm2();    //create pwm pulse gpio2
    Init_epwm3();       //create pwm pulse gpio3
    Init_epwm4();   //create pwm pulse gpio4

    //init timer
    InitTimer();

    EPwm1TimerIntCount = 0;


    while( 1U )
    {
        /* 100us cycle */
        if (CpuTimer0Regs.TCR.bit.TIF == 1U)
        {
            CpuTimer0Regs.TCR.bit.TIF = 1U;

            /* clear timer0 flag            */

//            Uart_tx_rx();                                       /* UART communication control */


            if(cnt_200us_mwait >= 1)  //x2
            {
                cnt_200us_mwait = 0;                            /* Clear */
//                /* 200us cycle */
//                update_monitor_events_200us();                  /* Fail detection  */
//                port_input_polling();                           /* Input port polling process */
//                ServiceDog();                                   /* Reset internal watchdog timer */

                main_loop_1ms();                                /* 1ms period processing  */

                //test 100us

            }
            else
            {
                cnt_200us_mwait ++;
            }
        }
    }
}


void
gpio_init()
{

    EALLOW;
    //gpio

    //gpio 0 - output
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;

    //gpio 5 - output
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO5 = 1;

    //epwm
    //EPWM3 -> gpio2
    GpioCtrlRegs.GPADIR.bit.GPIO2 = 0;  //set direction is output
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;// epwm2 active
    //EPWM3 -> gpio3
    GpioCtrlRegs.GPADIR.bit.GPIO3 = 0;  //set direction is output
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;// epwm3 active
    //EPWM3 -> gpio4
    GpioCtrlRegs.GPADIR.bit.GPIO4 = 0;  //set direction is output
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;// epwm3 active
    EDIS;
}


//
// adcbint1_isr - Interrupt routines uses in this example
//

void
InitPie(void)
{
    /*
    * AUTHER:
    * UNIT-ID: 0001
    * DESCRIPTION: This function initializes controller.
    * ARGUMENT: nothing
    * RETURN: nothing
    * NOTE:
    */
    DINT;
    InitPieCtrl();
//    Disable CPU interrupts and clear all CPU interrupt flags:
    IER = 0x0000;
    IFR = 0x0000;
    InitPieVectTable();

    EALLOW;
    // PieVectTable.ADCB1_INT = &adcbint1_isr;
    PieVectTable.EPWM1_INT = &adcbint1_isr;
    EDIS;
}

void
InitIsr(void)
{
    /*
    * AUTHER:
    * UNIT-ID: 0002
    * DESCRIPTION: This function initializes controller.
    * ARGUMENT: nothing
    * RETURN: nothing
    * NOTE:
    */
    // PieCtrlRegs.PIEIER1.bit.INTx2 = 1;
    // IER |= M_INT1;
    PieCtrlRegs.PIEIER3.bit.INTx1 = 1; /* - PWM1 ISR */
    IER |= M_INT3; /* */
    EINT; /* Enable Global interrupt INTM */
    ERTM; /* Enable Global realtime interrupt DBGM */
}

static void main_loop_1ms(void)
{
    /*
    * AUTHER:
    * UNIT-ID: 0004
    * DESCRIPTION: This function is 1ms period processing.
    * ARGUMENT: nothing
    * RETURN: nothing
    * NOTE:
    */

    static uint8_t cnt_200us_main = 0;
    static uint8_t cnt_1ms_main = 0;
    /* 1ms period processing  */
    switch(cnt_200us_main)
    {
        case 0u:
            GpioDataRegs.GPATOGGLE.bit.GPIO5 = 1;
//            receivedata_ecan();                             /* CAN receive process */
//            port_in();                                          /* Input port processing  */
//            update_adc_average_value_1ms();                 /* set current AD value for average process */

            break;

        case 1u:
            if(cnt_1ms_main == 8)
            {
//                adc_average_process_10ms();                 /* AD average process 10ms */
            }
            else if(cnt_1ms_main >= 9)
            {
//                phy_value_convert_ctrl_10ms();              /* AD conversion process 10ms */
            }
            else{}

            break;

        case 2u:
//            update_monitor_events_1ms_1();                      /* Fail 1 detection  */

            break;

        case 3u:
//            update_monitor_events_1ms_2();                      /* Fail 2 detection  */
//            update_monitor_events_1ms_3();                      /* Fail 3 detection  */

            break;

        case 4u:
//            state_machine();                                    /* State transition  */
//            port_out();                                         /* Port output processing  */
//            tx_can_send();                                      /* CAN transmit process  */
////            InitGpioDir();                                     /* Port resetting  *//* bug function!!!  */

            break;

        default:
            cnt_200us_main = 0u;
            break;
    }

    ++cnt_200us_main;
    if(cnt_200us_main >= 5u)
    {
        cnt_200us_main = 0u;

        /* 10ms cycle counter */
        ++cnt_1ms_main;
        if(cnt_1ms_main >= 10u)
        {
            cnt_1ms_main = 0u;
        }
    }
}

//
// End of File
//

