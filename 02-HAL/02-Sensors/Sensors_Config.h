#ifndef SENSORS_CONFIG_H
#define SENSORS_CONFIG_H
#include "../../01-MCAL/01-DIO/DIO_Interface.h"

/* TODO: Define the Ports and Pins for your specific sensor layout */
#define LEAK_PORT   DIO_u8_PORTB
#define LEAK1_PIN   DIO_u8_PIN1
#define LEAK2_PIN   DIO_u8_PIN2
#define FLOW_PIN    DIO_u8_PIN0 /* Typically T1 pin for flow pulse counting */

#define WATER_LEVEL_ADC_CH 0

#endif
