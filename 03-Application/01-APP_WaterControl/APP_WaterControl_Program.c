#include "APP_WaterControl_Interface.h"
#include "APP_WaterControl_Config.h"
#include "../../02-HAL/02-Sensors/Sensors_Interface.h"
#include "../../02-HAL/03-Actuators/Actuators_Interface.h"
#include "../../02-HAL/01-LCD/LCD_Interface.h"
#include "../../01-MCAL/01-DIO/DIO_Interface.h"
#include "../../01-MCAL/02-ADC/ADC_Interface.h"
#include "../../01-MCAL/03-TIMER/TIMER_Interface.h"
#include "../../01-MCAL/04-GPI/GPI_Interface.h"
#include "../../01-MCAL/05-EXTI/EXTI_Interface.h"

volatile u8 G_u8EmergencyFault = 0;

void APP_voidEmergencyStopISR(void) {
    /* TODO:
       1. Set G_u8EmergencyFault flag to 1.
       2. Immediately turn OFF the Pump.
       3. Immediately CLOSE the Valve.
       4. Immediately turn ON the Alarm.
    */
}

void APP_voidSystemInit(void) {
    /* TODO: 
       1. Initialize MCAL (ADC, TIMER0, TIMER1, ICU, GPI).
       2. Configure EXTI0 (External Interrupt 0) to trigger on FALLING_EDGE for emergency stop.
       3. Pass APP_voidEmergencyStopISR to EXTI0 CallBack.
       4. Enable Global Interrupts (GPI).
       5. Initialize HAL (Sensors, Actuators, LCD).
       6. Display an initial welcome message on the LCD (e.g., "Smart Water Sys").
    */
}

u8 APP_u8CheckLeaks(void) {
    /* TODO:
       Return 1 if LeakZone1 OR LeakZone2 detects water, OR if G_u8EmergencyFault == 1.
       Else, return 0.
    */
    return 0;
}

void APP_voidControlWaterLevel(u8 Copy_u8CurrentLevel) {
    /* TODO: Implement rule-based control using WATER_LEVEL_LOW and WATER_LEVEL_HIGH */
}

void APP_voidUpdateUI(u8 Copy_u8CurrentLevel, u8 Copy_u8LeakStatus) {
    /* TODO: 
       1. Clear the LCD.
       2. If leak detected, print "FAULT/LEAK DET!".
       3. Else, print the current water level percentage.
    */
}
