#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <util/delay.h>
#include "01-MCAL/00-LIB/STD_TYPES.h"
#include "03-Application/01-APP_WaterControl/APP_WaterControl_Interface.h"
#include "02-HAL/02-Sensors/Sensors_Interface.h"
#include "02-HAL/03-Actuators/Actuators_Interface.h"

int main(void) {
    /* TODO:
       1. Call APP_voidSystemInit().
       2. Add a brief delay for the welcome message to be visible.
       3. Initialize currentMode, currentLevel, and leakStatus variables.
       
       4. Start the Super Loop (while(1)):
          a. Read Water Level.
          b. Check Leak Status.
          c. If leakStatus == 1, update currentMode to FAULT and explicitly ensure actuators are OFF/Alarm ON (safety redundancy).
          d. Else if mode == AUTO, turn Alarm OFF and run APP_voidControlWaterLevel().
          e. Update the UI with the latest readings.
          f. Add a small loop delay (e.g., 500ms) for UI stability.
    */
    return 0;
}
