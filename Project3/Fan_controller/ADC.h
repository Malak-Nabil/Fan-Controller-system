/*
 * Module: ADC
 *
 * Description: header file for the ATmega16 ADC driver
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
/*definitions*/
#define MAXIMUM_VALUE    1023
#define REF_VOLT_VALUE   2.56

typedef enum {
    AREF,AVCC,RESERVED,INTERNAL /*vref turned off,5v,reserved,2.56v*/
} ADC_ReferenceVoltage;

typedef enum {
	ADC_PRESCALER_2_1,ADC_PRESCALER_2_2  ,ADC_PRESCALER_4  , ADC_PRESCALER_8,ADC_PRESCALER_16,ADC_PRESCALER_32,ADC_PRESCALER_64,ADC_PRESCALER_128
} ADC_Prescaler;

typedef struct {
    ADC_ReferenceVoltage ref_volt;
    ADC_Prescaler prescaler;
} ADC_ConfigType;

/*functions prototype*/
void ADC_init(const ADC_ConfigType * Config_Ptr);

uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
