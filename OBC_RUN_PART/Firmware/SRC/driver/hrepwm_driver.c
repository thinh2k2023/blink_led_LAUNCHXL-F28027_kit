/************************************************************************/
/* PROGRAM      : YZ-028-OBC                                            */
/* FILE         : hrepwm_driver.c                                       */
/* DESCRIPTION  : for obc_run_part                                                      */
/* CPU GROUP    : TMS32F280041                                          */
/* DATE         : 2020/1/15                                             */
/* Copyright    :                                                       */
/************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/

#include "hrepwm_driver.h"



void
Init_epwm1()
{

        EPwm1Regs.TBPRD = 2500;                                         /* Period */

        EPwm1Regs.TBPHS.half.TBPHS = 0;                                      /* Set Phase register to zero */
        EPwm1Regs.CMPA.half.CMPA = 370;                                        /* Set fixed CMPA EPWM1A for ISR*/
        EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;                               /* TBCLK = SYSCLKOUT / (HSPCLKDIV Ã¦Â²Â»Ã¨â€?��â‚¬ CLKDIV) */
        EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;
        EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;                      /* Count updown mode */
        EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;                             /* Master module */
        EPwm1Regs.TBCTL.bit.PRDLD = TB_SHADOW;
        EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO;                         /* Sync down-stream module */
        EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
        EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
        EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;                       /* load on CTR=Zero */
        EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;                       /* load on CTR=Zero */
        EPwm1Regs.DBCTL.bit.OUT_MODE = DB_DISABLE;                          /* enable Dead-band module */

        /* configure ISR 40KHz */

        EPwm1Regs.ETSEL.bit.INTEN = 1;  /* enable EPWM1 INT */
//        EPwm1Regs.ETSEL.bit.INTSEL = 1; /* Enable event time-base counter equal to zero. (TBCTR = 0x00) */
        EPwm1Regs.ETSEL.bit.INTSEL = 4;/*  Enable event time-base counter equal to CMPA when the timer is incrementing or CMPC when the timer is incrementing */

    //    EPwm1Regs.ETPS.bit.INTPSSEL = 0;

        EPwm1Regs.ETPS.bit.INTPRD = ET_1ST; /* 1> to 3 cycle EPWM */

//    #if 0
//        /* configure start of ADC(TBD) */
//        /* Use epwm1 to trigger SOCs of ADC */
//        EPwm1Regs.ETSEL.bit.SOCAEN = 1;                                     /* Enable SOC on A group */
//        EPwm1Regs.ETSEL.bit.SOCASEL = ET_CTR_ZERO;                         /* Select SOC from from CPMB on downcount */
//        EPwm1Regs.ETPS.bit.SOCAPRD = ET_1ST;                                /* Generate pulse on 2nd event */
//    #endif
}
