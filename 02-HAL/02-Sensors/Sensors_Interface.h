#ifndef SENSORS_INTERFACE_H
#define SENSORS_INTERFACE_H
#include "../../01-MCAL/00-LIB/STD_TYPES.h"

/* Initialize all sensor pins */
void SENSORS_voidInit(void);

/* Read Leak Zones: Return 1 if water detected, else 0 */
u8 SENSORS_u8LeakZone1_Read(void);
u8 SENSORS_u8LeakZone2_Read(void);

/* Read Water Level: Return mapped percentage (0 to 100%) */
u8 SENSORS_u8ReadWaterLevel(void);

/* Read Flow Rate */
u16 SENSORS_u16ReadFlowRate(void);

#endif
