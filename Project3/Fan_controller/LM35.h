
/*
 * Module: Temperature Sensor
 *
 * Description:header file for the LM35 Temperature Sensor driver
 */

#ifndef LM35_H_
#define LM35_H_

#include "std_types.h"

/*Definitions*/
#define CHANNEL_ID         2
#define MAX_VOLT_VALUE     1.5
#define MAX_TEMPERATURE    150

/*function prototype*/

/* Function responsible for calculate the temperature from the ADC digital value.*/
uint8 LM35_getTemperature(void);

#endif /* LM35_H_ */
