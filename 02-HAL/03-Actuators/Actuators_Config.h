#ifndef ACTUATORS_CONFIG_H
#define ACTUATORS_CONFIG_H
#include "../../01-MCAL/01-DIO/DIO_Interface.h"

/* TODO: Define the correct Ports and Pins for your actuators */
#define PUMP_PORT   DIO_u8_PORTB
#define PUMP_PIN    DIO_u8_PIN4

#define VALVE_PORT  DIO_u8_PORTB
#define VALVE_PIN   DIO_u8_PIN5

#define ALARM_PORT  DIO_u8_PORTB
#define ALARM_PIN   DIO_u8_PIN6

#endif
