
//
// Included Files
//
#include "common.h"     // Device Headerfile and Examples Include File

#include "hrepwm_driver.h"

#include "adcint1_isr.h"

//
// Function Prototypes
//

//normal function
void gpio_init();
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

    //init system control
    InitSysCtrl();

    //init interrupt
    InitPie();
    InitIsr();

    //intit epwm1
    Init_epwm1();    // epwm is used for interrupt timer function

    EPwm1TimerIntCount = 0;


    for(;;)
    {

//        cpu_rate = SYSCLKOUT;
//        GpioDataRegs.GPATOGGLE.bit.GPIO0 = 1;

//        if (EPwm1TimerIntCount == 54657)
//        {
//            GpioDataRegs.GPATOGGLE.bit.GPIO0 = 1;
//        }
//        __asm("          NOP");
//            GpioDataRegs.GPATOGGLE.bit.GPIO0 = 1;
//            DELAY_US(1000000);
    }
}


void
gpio_init()
{
    EALLOW;
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;
    //EPWM1 -> myEPWM1 Pinmux
//    GpioCtrlRegs.GPAMUX1.all = 0;// gpio 15 to gpio 0 a;; general purpouse I/O
//    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;// epwm active
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
//
// End of File
//

