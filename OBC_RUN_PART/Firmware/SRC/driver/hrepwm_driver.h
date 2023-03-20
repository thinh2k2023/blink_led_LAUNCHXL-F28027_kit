/*
 * hrepwm_driver.h
 *
 *  Created on: 20 Mar 2023
 *      Author: admin
 */

#ifndef SRC_DRIVER_HREPWM_DRIVER_H_
#define SRC_DRIVER_HREPWM_DRIVER_H_

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

void Init_epwm1(void);
void Init_epwm2(void);
void Init_epwm3(void);
void Init_epwm4(void);

#define INV_PERIOD              1000
#define INV_DEAD_TIME           30

/* AC RLY */
#define ACRLY_PERIOD            50000       /* EPWM4_freq = 1kHz(1ms) */

#endif /* SRC_DRIVER_HREPWM_DRIVER_H_ */
