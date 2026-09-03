#include "../00-LIB/STD_TYPES.h"
#include "../00-LIB/BIT_MATH.h"

#include "GPI_Interface.h"
#include "GPI_Private.h"
#include "GPI_Config.h"

void GPI_voidInit   (void)
{
	#if GPI_u8_MODE == GPI_u8_ENABLE
		SET_BIT(GPI_u8_SREG,GPI_u8_INTERRUPT_ENABLE_BIT);
    #else
		CLR_BIT(GPI_u8_SREG,GPI_u8_INTERRUPT_ENABLE_BIT);
    #endif
}

void GPI_voidEnable (void)
{
	SET_BIT(GPI_u8_SREG,GPI_u8_INTERRUPT_ENABLE_BIT);
}

void GPI_voidDisable(void)
{
	CLR_BIT(GPI_u8_SREG,GPI_u8_INTERRUPT_ENABLE_BIT);
}
