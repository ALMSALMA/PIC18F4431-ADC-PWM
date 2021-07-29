/**
  CCP2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    ccp2.c

  @Summary
    This is the generated driver implementation file for the CCP2 driver using MPLAB® Code Configurator

  @Description
    This source file provides implementations for driver APIs for CCP2.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.25.2
        Device            :  PIC18F26K20
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.34
        MPLAB             :  MPLAB X v2.35 or v3.00
 */

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */

/**
  Section: Included Files
 */

#include <xc.h>
#include "pwm2.h"

/**
  Section: Macro Declarations
 */

#define PWM2_INITIALIZE_DUTY_VALUE    499

/**
  Section: PWM Module APIs
 */

void PWM2_Initialize(void) {
    // Set the PWM to the options selected in the MPLAB® Code Configurator

    // DC2B 48; CCP2M PWM; 
    CCP2CON = 0x3C;

    // CCPR2L 124; 
    CCPR2L = 0x7C;

    // CCPR2H 0x0; 
    CCPR2H = 0x00;

}

void PWM2_LoadDutyValue(uint16_t dutyValue) {
    // Writing to 8 MSBs of pwm duty cycle in CCPRL register
    CCPR2L = ((dutyValue & 0x03FC) >> 2);

    // Writing to 2 LSBs of pwm duty cycle in CCPCON register
    CCP2CON = (CCP2CON & 0xCF) | ((dutyValue & 0x0003) << 4);
}
/**
 End of File
 */

