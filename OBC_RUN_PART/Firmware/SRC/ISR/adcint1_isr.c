/************************************************************************/
/* PROGRAM      : YZ-028-OBC                                            */
/* FILE         : adcint1_isr.c                                         */
/* DESCRIPTION  :                                                       */
/* CPU GROUP    : TMS32F280041                                          */
/* DATE         : 2020/1/15                                             */
/* Copyright    :                                                       */
/************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "adcint1_isr.h"

extern uint32_t EPwm1TimerIntCount;

__interrupt void
adcbint1_isr(void)
{
    EPwm1TimerIntCount++;
    GpioDataRegs.GPASET.bit.GPIO0 = 1;

    //
    // Clear INT flag for this timer
    //
    EPwm1Regs.ETCLR.bit.INT = 1;

    //
    // Acknowledge this interrupt to receive more interrupts from group 3
    //
    PieCtrlRegs.PIEACK.bit.ACK3 = 1; /*system clear flag group 3 interrupt */
    GpioDataRegs.GPACLEAR.bit.GPIO0 = 1;
}

/***********************************************************************************************************************
End of file
***********************************************************************************************************************/
