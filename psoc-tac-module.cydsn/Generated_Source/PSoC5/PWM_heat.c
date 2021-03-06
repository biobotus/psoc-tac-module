/*******************************************************************************
* File Name: PWM_heat.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "PWM_heat.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 PWM_heat__PORT == 15 && ((PWM_heat__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: PWM_heat_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void PWM_heat_Write(uint8 value) 
{
    uint8 staticBits = (PWM_heat_DR & (uint8)(~PWM_heat_MASK));
    PWM_heat_DR = staticBits | ((uint8)(value << PWM_heat_SHIFT) & PWM_heat_MASK);
}


/*******************************************************************************
* Function Name: PWM_heat_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  PWM_heat_DM_STRONG     Strong Drive 
*  PWM_heat_DM_OD_HI      Open Drain, Drives High 
*  PWM_heat_DM_OD_LO      Open Drain, Drives Low 
*  PWM_heat_DM_RES_UP     Resistive Pull Up 
*  PWM_heat_DM_RES_DWN    Resistive Pull Down 
*  PWM_heat_DM_RES_UPDWN  Resistive Pull Up/Down 
*  PWM_heat_DM_DIG_HIZ    High Impedance Digital 
*  PWM_heat_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void PWM_heat_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(PWM_heat_0, mode);
}


/*******************************************************************************
* Function Name: PWM_heat_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro PWM_heat_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PWM_heat_Read(void) 
{
    return (PWM_heat_PS & PWM_heat_MASK) >> PWM_heat_SHIFT;
}


/*******************************************************************************
* Function Name: PWM_heat_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 PWM_heat_ReadDataReg(void) 
{
    return (PWM_heat_DR & PWM_heat_MASK) >> PWM_heat_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PWM_heat_INTSTAT) 

    /*******************************************************************************
    * Function Name: PWM_heat_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 PWM_heat_ClearInterrupt(void) 
    {
        return (PWM_heat_INTSTAT & PWM_heat_MASK) >> PWM_heat_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
