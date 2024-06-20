
/*
 * Module: Temperature Sensor
 *
 * Description:source file for the LM35 Temperature Sensor driver
 */


#include "LM35.h"
#include "ADC.h"

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(CHANNEL_ID);



	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value*MAX_TEMPERATURE*REF_VOLT_VALUE)/(MAXIMUM_VALUE*MAX_VOLT_VALUE));

	return temp_value;
}


