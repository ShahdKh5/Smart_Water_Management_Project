#ifndef APP_WATERCONTROL_INTERFACE_H
#define APP_WATERCONTROL_INTERFACE_H
#include "../../01-MCAL/00-LIB/STD_TYPES.h"

typedef enum {
    MODE_AUTO,
    MODE_MANUAL,
    MODE_SAFETY_FAULT
} SystemMode_t;

void APP_voidSystemInit(void);
u8 APP_u8CheckLeaks(void);
void APP_voidControlWaterLevel(u8 Copy_u8CurrentLevel);
void APP_voidUpdateUI(u8 Copy_u8CurrentLevel, u8 Copy_u8LeakStatus);
void APP_voidEmergencyStopISR(void); 

#endif
