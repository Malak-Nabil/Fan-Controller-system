#include"ADC.h"
#include"DC_MOTOR.h"
#include"PWM.h"
#include"LCD.h"
#include"LM35.h"

int main(void) {
	uint8 temp;
	ADC_ConfigType adcConfig;
	adcConfig.ref_volt = INTERNAL;  // Set the reference voltage to INTERNAL
	adcConfig.prescaler = ADC_PRESCALER_8;  // Set the prescaler

	// Initialize the ADC with the configuration
	ADC_init(&adcConfig);
	DcMotor_Init();
	LCD_init();


	while (1) {
		temp= LM35_getTemperature();
		if (temp < 30) {
			DcMotor_Rotate(OFF, OFF_SPEED);
			display_stringRowColumn(0, 0, "Fan is OFF");
			display_stringRowColumn(1,0,"Temperature=");
			intger_To_String(temp);
		} else if (temp >= 30 && temp < 60) {
			DcMotor_Rotate(CW, 25);
			display_stringRowColumn(0, 0, "Fan is ON ");
			display_stringRowColumn(1,0,"Temperature=");
			intger_To_String(temp);
		} else if (temp >= 60 && temp < 90) {
			DcMotor_Rotate(CW, 50);
			display_stringRowColumn(0, 0, "Fan is ON ");
			display_stringRowColumn(1,0,"Temperature=");
			intger_To_String(temp);
		} else if (temp >= 90 && temp < 120) {
			DcMotor_Rotate(CW, 75);
			display_stringRowColumn(0, 0, "Fan is ON ");
			display_stringRowColumn(1,0,"Temperature=");
			intger_To_String(temp);
			display_string(" ");
		} else if (temp >= 120) {
			DcMotor_Rotate(CW, FULL_SPEED);
			display_stringRowColumn(0, 0, "Fan is ON");
			display_stringRowColumn(1,0,"Temperature=");
			intger_To_String(temp);
			display_string(" ");
		}
	}
	return 0;
}

