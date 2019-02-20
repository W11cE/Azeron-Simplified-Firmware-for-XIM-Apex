#include "RefreshChecker.h"

#define ARRAY_LENGHT(type ,array)	(sizeof(array) / sizeof(type))

#define BUTTON_T1_P1	26	//1
#define BUTTON_T2_P1	22	//2
#define BUTTON_T3_P1	27	//3
#define BUTTON_T4_P1	4	//4
#define BUTTON_T5_P1	11	//5
#define BUTTON_T1_P2	25	//6
#define BUTTON_T2_P2	21	//7
#define BUTTON_T3_P2	0	//8
#define BUTTON_T4_P2	5	//9
#define BUTTON_T1_P3	24	//10
#define BUTTON_T2_P3	20	//11
#define BUTTON_T3_P3	1	//12
#define BUTTON_T4_P3	8	//13
#define BUTTON_T1_P4	23	//14
#define BUTTON_T2_P4	19	//15
#define BUTTON_T3_P4	2	//16
#define BUTTON_T4_P4	9	//17
#define BUTTON_T3_P5	3	//18
#define BUTTON_T4_P5	10	//19
#define BUTTON_THUMB_3	38	//20 , Button above the thumbstick.
#define BUTTON_THUMB_1	18	//21 , Button on the thumbstick.
#define BUTTON_THUMB_2	12	//22 , Button next to the thumbstick.

const int DigitalButtons[] = {
	 BUTTON_T1_P1,
	 BUTTON_T2_P1,
	 BUTTON_T3_P1,
	 BUTTON_T4_P1,
	 BUTTON_T5_P1,
	 BUTTON_T1_P2,
	 BUTTON_T2_P2,
	 BUTTON_T3_P2,
	 BUTTON_T4_P2,
	 BUTTON_T1_P3,
	 BUTTON_T2_P3,
	 BUTTON_T3_P3,
	 BUTTON_T4_P3,
	 BUTTON_T1_P4,
	 BUTTON_T2_P4,
	 BUTTON_T3_P4,
	 BUTTON_T4_P4,
	 BUTTON_T3_P5,
	 BUTTON_T4_P5,
	 BUTTON_THUMB_3,
	 BUTTON_THUMB_1,
	 BUTTON_THUMB_2
};

#define SWITCH_1		14
#define SWITCH_2		13

#define X_AXIS			40
#define Y_AXIS			39
#define POT				41

#define LED_1			16
#define LED_2			15
#define LED_TEENSY		6

RefreshChecker Check = RefreshChecker(27);

void setup()
{
	Joystick.useManualSend(true);
	Joystick.hat(-1);
	Joystick.slider(512);
	Joystick.sliderLeft(0);
	Joystick.sliderRight(0);
	Joystick.Z(512);
	Joystick.Zrotate(512);

	for (int i = 0; i < ARRAY_LENGHT(int, DigitalButtons); i++)
	{
		pinMode(DigitalButtons[i], INPUT_PULLUP);
	}
	pinMode(SWITCH_1, INPUT_PULLUP);
	pinMode(SWITCH_2, INPUT_PULLUP);

	pinMode(LED_1, OUTPUT);
	pinMode(LED_2, OUTPUT);
	pinMode(LED_TEENSY, OUTPUT);

	analogWrite(LED_1, 1);
	analogWrite(LED_2, 0);
	digitalWrite(LED_TEENSY, 0);
}

void loop()
{
	for (int i = 0; i < ARRAY_LENGHT(int, DigitalButtons); i++)
	{
		Joystick.button(i + 1, Check.PassNew(i, !digitalReadFast(DigitalButtons[i])));
	}

	auto axisX = map(analogRead(X_AXIS), 1023, 0, 1023, 0);
	axisX = constrain(axisX, 0, 1023);
	auto axisY = map(analogRead(Y_AXIS), 0, 1023, 1023, 0);
	axisY = constrain(axisY, 0, 1023);

	Joystick.X(Check.PassNew(ARRAY_LENGHT(int, DigitalButtons) + 1, axisX));
	Joystick.Y(Check.PassNew(ARRAY_LENGHT(int, DigitalButtons) + 2, axisY));

	if (Check.HasNewData())
	{
		Joystick.send_now();
	}
}