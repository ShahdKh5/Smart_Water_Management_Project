#include "../../01-MCAL/00-LIB/STD_TYPES.h"
#include "../../01-MCAL/01-DIO/DIO_Interface.h"
#include "../../01-MCAL/02-ADC/ADC_Interface.h"
#include "../../01-MCAL/03-TIMER/TIMER_Interface.h"
#include "Sensors_Config.h"
#include "Sensors_Interface.h"

void SENSORS_voidInit(void) {
    /* TODO: Set directions for LEAK1_PIN, LEAK2_PIN, and FLOW_PIN as inputs using DIO */
}

u8 SENSORS_u8LeakZone1_Read(void) {
    /* TODO: Read the value of LEAK1_PIN and return it */
    return 0;
}

u8 SENSORS_u8LeakZone2_Read(void) {
    /* TODO: Read the value of LEAK2_PIN and return it */
    return 0;
}

u8 SENSORS_u8ReadWaterLevel(void) {
    /* TODO: 
       1. Read synchronous ADC result using WATER_LEVEL_ADC_CH.
       2. Convert the 10-bit raw ADC value (0-1023) to a percentage (0-100%).
       3. Return the calculated percentage.
    */
    return 0;
}

u16 SENSORS_u16ReadFlowRate(void) {
    /* TODO: Read and return the captured count from the ICU (Input Capture Unit) */
    return 0;
}
