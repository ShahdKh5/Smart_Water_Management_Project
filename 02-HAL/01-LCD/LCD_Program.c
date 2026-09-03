/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <util/delay.h>
#include "../../01-MCAL/00-LIB/STD_TYPES.h"
#include "../../01-MCAL/00-LIB/BIT_MATH.h"

#include "../../01-MCAL/01-DIO/DIO_Interface.h"

#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Config.h"

void LCD_voidInit(void)
{
	//Configure the direction of all CONTROL pins is o/p
	DIO_voidSetPinDirection(LCD_u8_CTRL_PORT,LCD_u8_RSPIN,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(LCD_u8_CTRL_PORT,LCD_u8_RWPIN,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(LCD_u8_CTRL_PORT,LCD_u8_EPIN,DIO_u8_OUTPUT);

	//Configure the direction of data port
	DIO_voidSetPortDirection(LCD_u8_DATA_PORT,0xff);
	/*LCD Initialization*/
	_delay_ms(30);
	/*Fn Set*/
	LCD_voidSendInstruction(0b00111100);
	_delay_ms(2);
	/*Display ON/OFF*/
	LCD_voidSendInstruction(0b00001100);
	_delay_ms(2);
	/*Clear Display*/
	LCD_voidSendInstruction(0b00000001);
	_delay_ms(2);
	/*Entry Mode Set*/
	LCD_voidSendInstruction(0b00000110);
	_delay_ms(2);
}

void LCD_voidSendInstruction(u8 Copy_u8instruction)
{
	//RS = 0 (Command), RW = 0 (Write), E = 1 (Enable)
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RSPIN,DIO_u8_LOW);
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RWPIN,DIO_u8_LOW);
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_EPIN,DIO_u8_HIGH);

	//001,DL(8-bit data),N(2-lines),F(5*10 dots)
	DIO_voidSetPortValue(LCD_u8_DATA_PORT,Copy_u8instruction);

	//E (1 then 0 --> falling edge)
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_EPIN,DIO_u8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_EPIN,DIO_u8_LOW);
}

void LCD_voidWriteChar(u8 Copy_u8Data)
{
	//RS = 0 (Data), RW = 0 (Write), E = 1 (Enable)
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RSPIN,DIO_u8_HIGH);
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RWPIN,DIO_u8_LOW);
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_EPIN,DIO_u8_HIGH);

	//001,DL(8-bit data),N(2-lines),F(5*10 dots)
	DIO_voidSetPortValue(LCD_u8_DATA_PORT,Copy_u8Data);

	//E (1 then 0 --> falling edge)
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_EPIN,DIO_u8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_u8_CTRL_PORT,LCD_u8_EPIN,DIO_u8_LOW);
}

void LCD_voidWriteString(u8 *Copy_u8String, u8 Copy_u8Size)
{
	//String is an array of characters
	for(u8 i=0; i<Copy_u8Size; i++)
	{
		LCD_voidWriteChar(Copy_u8String[i]);	//Write a char on each iteration
	}
}

void LCD_voidGotoXY(u8 Copy_u8Row, u8 Copy_u8Column)
{
	if( (Copy_u8Row == 1) && (Copy_u8Column < 16) )		
	{
		LCD_voidSendInstruction(0x80 + Copy_u8Column);	
	}
	else if( (Copy_u8Row == 2) && (Copy_u8Column < 16) )
	{
		LCD_voidSendInstruction(0xC0 + Copy_u8Column);	
	}
	else
	{
		//Do Nothing
	}
}

void LCD_voidClearDisplay(void)
{
	LCD_voidSendInstruction(0b00000001);	//sending Instruction to clear the whole display
}

void LCD_voidWriteSpecialChar(u8 *Copy_u8Pattern, u8 Copy_u8PatternNumber ,u8 Copy_u8Row, u8 Copy_u8Column)
{
	u8 Local_u8Adress=(Copy_u8PatternNumber*8);
	LCD_voidSendInstruction(Local_u8Adress+64);

	for (u8 i=0 ;i<8 ;i++)
	{
		LCD_voidWriteChar(Copy_u8Pattern[i]);
	}
	LCD_voidGotoXY(Copy_u8Row ,Copy_u8Column );
	LCD_voidWriteChar(Copy_u8PatternNumber); 
}
