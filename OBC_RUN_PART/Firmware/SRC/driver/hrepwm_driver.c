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


/* LLC EPWM configure */
void
Init_epwm2(void)
{
   /*
    * AUTHER:
    * UNIT-ID: 0
    * DESCRIPTION: This function initializes controller.
    * ARGUMENT: nothing
    * RETURN: nothing
    * NOTE:
    */

    /* timming */
    EPwm2Regs.TBPRD = INV_PERIOD;                               /* Period */
    EPwm2Regs.CMPA.half.CMPA = 500;                  /* Set 50% fixed duty for EPWM1A */
    EPwm2Regs.CMPB = 500;                  /* Set 50% fixed duty for EPWM1A */
    EPwm2Regs.TBPHS.half.TBPHS = 0;                                      /* Set Phase register to zero */
    EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV1;                               /* TBCLK = SYSCLKOUT / (HSPCLKDIV Ã¦Â²Â»Ã¨â€?��â‚¬ CLKDIV) */
    EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;
    EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;                          /* Count down mode */
    EPwm2Regs.TBCTL.bit.PHSEN = TB_DISABLE;                             /* Master module */
    EPwm2Regs.TBCTL.bit.PRDLD = TB_SHADOW;
    EPwm2Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO;                         /* Sync down-stream module */
    EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm2Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_PRD;                        /* load on CTR=Zero */
    EPwm2Regs.CMPCTL.bit.LOADBMODE = CC_CTR_PRD;                        /* load on CTR=Zero */
    EPwm2Regs.AQCTLA.bit.CAU = AQ_CLEAR;                                    /* set actions for EPWM1A */
    EPwm2Regs.AQCTLA.bit.CBD = AQ_SET;
    EPwm2Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;                      /* enable Dead-band module */
    EPwm2Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;                           /* Active Hi complementary */
    EPwm2Regs.DBFED = INV_DEAD_TIME;                              /* FED = 10 TBCLKs initially */
    EPwm2Regs.DBRED = INV_DEAD_TIME;                              /* RED = 10 TBCLKs initially */

    EPwm2Regs.TZCTL.bit.TZA = TZ_FORCE_LO;                              /* force EPWMxA to a low state(trip action on EPWMxA) */
    EPwm2Regs.TZCTL.bit.TZB = TZ_FORCE_LO;                              /* force EPWMxB to a low state(trip action on EPWMxB) */
    EPwm2Regs.TZSEL.bit.OSHT1 = TZ_ENABLE;                              /* Enable TZ2(one-shot trip) */
    EPwm2Regs.TZFRC.bit.OST = 1;

    EPwm2Regs.TZEINT.bit.CBC = 1;
    EPwm2Regs.TZSEL.bit.CBC1 = 1;
    /* configure start of ADC(TBD) */


    /* configure start of ADC(TBD) */
    /* Use epwm1 to trigger SOCs of ADC */
    EPwm2Regs.ETSEL.bit.SOCAEN = 1;                                     /* Enable SOC on A group */
    EPwm2Regs.ETSEL.bit.SOCASEL = ET_CTR_PRD;                           /* Enable event time-base counter equal to period */
    EPwm2Regs.ETPS.bit.SOCAPRD = ET_1ST;                                /* Generate pulse on 2nd event */

    EPwm2Regs.ETSEL.bit.SOCBEN = 1;                                     /* Enable SOC on B group */
    EPwm2Regs.ETSEL.bit.SOCBSEL = ET_CTR_ZERO;                          /* Enable event time-base counter equal to zero */
    EPwm2Regs.ETPS.bit.SOCBPRD = ET_1ST;                                /* Generate pulse on 2nd event */
}


void
Init_epwm3(void)
{
    /*
     * AUTHER:
     * UNIT-ID: 0
     * DESCRIPTION: This function initializes controller.
     * ARGUMENT: nothing
     * RETURN: nothing
     * NOTE:
     */

     /* timming */
     EPwm3Regs.TBPRD = INV_PERIOD;                               /* Period */
     EPwm3Regs.CMPA.half.CMPA = 500;                  /* Set 50% fixed duty for EPWM1A */
     EPwm3Regs.CMPB = 500;                  /* Set 50% fixed duty for EPWM1A */
     EPwm2Regs.TBPHS.half.TBPHS = 0;                                      /* Set Phase register to zero */
     EPwm3Regs.TBCTL.bit.CLKDIV = TB_DIV1;                               /* TBCLK = SYSCLKOUT / (HSPCLKDIV Ã¦Â²Â»Ã¨â€?��â‚¬ CLKDIV) */
     EPwm3Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;
     EPwm3Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;                          /* Count down mode */
     EPwm3Regs.TBCTL.bit.PHSEN = TB_DISABLE;                             /* Master module */
     EPwm3Regs.TBCTL.bit.PRDLD = TB_SHADOW;
     EPwm3Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO;                         /* Sync down-stream module */
     EPwm3Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
     EPwm3Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
     EPwm3Regs.CMPCTL.bit.LOADAMODE = CC_CTR_PRD;                        /* load on CTR=Zero */
     EPwm3Regs.CMPCTL.bit.LOADBMODE = CC_CTR_PRD;                        /* load on CTR=Zero */
     EPwm3Regs.AQCTLA.bit.CAU = AQ_SET;                                    /* set actions for EPWM1A */
     EPwm3Regs.AQCTLA.bit.CBD = AQ_CLEAR;
     EPwm3Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;                      /* enable Dead-band module */
     EPwm3Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;                           /* Active Hi complementary */
     EPwm2Regs.DBFED = INV_DEAD_TIME;                              /* FED = 10 TBCLKs initially */
     EPwm2Regs.DBRED = INV_DEAD_TIME;                              /* RED = 70 TBCLKs initially */

     EPwm3Regs.TZCTL.bit.TZA = TZ_FORCE_LO;                              /* force EPWMxA to a low state(trip action on EPWMxA) */
     EPwm3Regs.TZCTL.bit.TZB = TZ_FORCE_LO;                              /* force EPWMxB to a low state(trip action on EPWMxB) */
     EPwm3Regs.TZSEL.bit.OSHT1 = TZ_ENABLE;                              /* Enable TZ2(one-shot trip) */
     EPwm3Regs.TZFRC.bit.OST = 1;
}


/* ACrelay EPWM configure */
void Init_epwm4(void)
{
   /*
    * AUTHER:
    * UNIT-ID: 0
    * DESCRIPTION: This function initializes controller.
    * ARGUMENT: nothing
    * RETURN: nothing
    * NOTE:
    */

    /* timming */
    EPwm4Regs.TBPRD = ACRLY_PERIOD;                                     /* Period */
    EPwm4Regs.CMPA.half.CMPA = 0;                                        /* set min duty for phase 1 */
    EPwm4Regs.CMPB = ACRLY_PERIOD;                             /* set min duty for phase 2 */
    EPwm4Regs.TBPHS.half.TBPHS = 0;                                      /* Set Phase register to zero */
    EPwm4Regs.TBCTL.bit.CLKDIV = TB_DIV1;                               /* TBCLK = SYSCLKOUT / (HSPCLKDIV CLKDIV) */
    EPwm4Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;
    EPwm4Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;                      /* Count updown mode */
    EPwm4Regs.TBCTL.bit.PHSEN = TB_DISABLE;                             /* Master module */
    EPwm4Regs.TBCTL.bit.PRDLD = TB_SHADOW;
    EPwm4Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO;                         /* Sync down-stream module */
    EPwm4Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm4Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm4Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;                       /* load on CTR=Zero */
    EPwm4Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;                       /* load on CTR=Zero */
    EPwm4Regs.AQCTLB.bit.CBU = AQ_SET;
    EPwm4Regs.AQCTLB.bit.CBD = AQ_CLEAR;
    EPwm4Regs.DBCTL.bit.OUT_MODE = DB_DISABLE;                          /* enable Dead-band module */

    /* Use epwm4 to trigger SOCs of ADC */
    EPwm4Regs.ETSEL.bit.SOCBEN = 1;                                     /* Enable SOC on B group */
    EPwm4Regs.ETSEL.bit.SOCBSEL = ET_CTR_PRD;
    EPwm4Regs.ETPS.bit.SOCBPRD = ET_1ST;
}
