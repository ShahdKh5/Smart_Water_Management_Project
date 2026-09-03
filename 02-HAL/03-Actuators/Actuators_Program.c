#include "../../01-MCAL/00-LIB/STD_TYPES.h"
#include "../../01-MCAL/01-DIO/DIO_Interface.h"
#include "Actuators_Config.h"
#include "Actuators_Interface.h"

void ACTUATORS_voidInit(void) {
    /* TODO: 
       1. Set PUMP, VALVE, and ALARM pins as OUTPUT.
       2. Initialize their values to LOW (Off state).
    */
}

void ACTUATORS_voidPumpON(void) {
    /* TODO: Set PUMP_PIN to HIGH */
}

void ACTUATORS_voidPumpOFF(void) {
    /* TODO: Set PUMP_PIN to LOW */
}

void ACTUATORS_voidValveCLOSE(void) {
    /* TODO: Set VALVE_PIN to HIGH (Assuming HIGH closes it) */
}

void ACTUATORS_voidAlarmON(void) {
    /* TODO: Set ALARM_PIN to HIGH */
}

void ACTUATORS_voidAlarmOFF(void) {
    /* TODO: Set ALARM_PIN to LOW */
}
