//###########################################################################
//
// FILE:    Example_2802xGpioToggle.c
//
// TITLE:   f2802x Device GPIO toggle test program.
//
// ASSUMPTIONS:
//
//    This program requires the f2802x header files.
//
//    ALL OF THE I/O'S TOGGLE IN THIS PROGRAM.  MAKE SURE
//    THIS WILL NOT DAMAGE YOUR HARDWARE BEFORE RUNNING THIS
//    EXAMPLE.
//
//    Monitor desired pins on an oscilloscope.
//
//    As supplied, this project is configured for "boot to SARAM"
//    operation.  The 2802x Boot Mode table is shown below.
//    For information on configuring the boot mode of an eZdsp,
//    please refer to the documentation included with the eZdsp,
//
//    $Boot_Table
//    While an emulator is connected to your device, the TRSTn pin = 1,
//    which sets the device into EMU_BOOT boot mode. In this mode, the
//    peripheral boot modes are as follows:
//
//      Boot Mode:   EMU_KEY        EMU_BMODE
//                   (0xD00)         (0xD01)
//      ---------------------------------------
//      Wait         !=0x55AA        X
//      I/O          0x55AA          0x0000
//      SCI          0x55AA          0x0001
//      Wait         0x55AA          0x0002
//      Get_Mode     0x55AA          0x0003
//      SPI          0x55AA          0x0004
//      I2C          0x55AA          0x0005
//      OTP          0x55AA          0x0006
//      Wait         0x55AA          0x0007
//      Wait         0x55AA          0x0008
//      SARAM        0x55AA          0x000A   <-- "Boot to SARAM"
//      Flash        0x55AA          0x000B
//      Wait         0x55AA          Other
//
//   Write EMU_KEY to 0xD00 and EMU_BMODE to 0xD01 via the debugger
//   according to the Boot Mode Table above. Build/Load project,
//   Reset the device, and Run example
//
//   $End_Boot_Table
//
//
// DESCRIPTION:
//
//     Three different examples are included. Select the example
//     (data, set/clear or toggle) to execute before compiling using
//     the #define statements found at the top of the code.
//
//
//     Toggle all of the GPIO PORT pins
//
//    The pins can be observed using Oscilloscope.
//
//
//###########################################################################
// $TI Release:  $
// $Release Date:  $
// $Copyright:
// Copyright (C) 2009-2022 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
//
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the
//   distribution.
//
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//###########################################################################

//
// Included Files
//
#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File

//
// Defines that select the example to compile in.  Only one example should be
// set as 1 the rest should be set as 0.
//

//
// Function Prototypes
//
void delay_loop(void);
void Gpio_select(void);
void Gpio_example1(void);
void Gpio_example2(void);
void Gpio_example3(void);

void main(void)
{

    InitSysCtrl();
    Gpio_select();
    DINT;
    InitPieCtrl();
    InitPieVectTable();
    Gpio_example1();

}

//
// Gpio_example1 - Toggle I/Os using DATA registers
//
void
Gpio_example1(void)
{
    for(;;)
    {
        GpioDataRegs.GPADAT.all    =0xAAAAAAAA;
        GpioDataRegs.GPBDAT.all    =0x0000000A;

//        delay_loop();
        DELAY_US(50000);

        GpioDataRegs.GPADAT.all    =0x55555555;
        GpioDataRegs.GPBDAT.all    =0x00000005;
        DELAY_US(50000);
//        delay_loop();
    }
}
//
// Gpio_select-
//
void
Gpio_select(void)
{
    EALLOW;
    GpioCtrlRegs.GPAMUX1.all = 0x00000000;  // All GPIO
    GpioCtrlRegs.GPAMUX2.all = 0x00000000;  // All GPIO
    GpioCtrlRegs.GPAMUX1.all = 0x00000000;  // All GPIO
    GpioCtrlRegs.GPADIR.all = 0xFFFFFFFF;   // All outputs
    GpioCtrlRegs.GPBDIR.all = 0x0000000F;   // All outputs
    EDIS;
}

//
// End of File
//

