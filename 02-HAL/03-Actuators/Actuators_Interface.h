#ifndef ACTUATORS_INTERFACE_H
#define ACTUATORS_INTERFACE_H
#include "../../01-MCAL/00-LIB/STD_TYPES.h"

void ACTUATORS_voidInit(void);
void ACTUATORS_voidPumpON(void);
void ACTUATORS_voidPumpOFF(void);
void ACTUATORS_voidValveCLOSE(void);
void ACTUATORS_voidAlarmON(void);
void ACTUATORS_voidAlarmOFF(void);

#endif
