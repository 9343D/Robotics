#pragma config(UART_Usage, UART1, uartUserControl, baudRate4800, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Motor,  port1,            ,             tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,            ,             tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,            ,             tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,           ,             tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

float maxspinnerspeed = 80;

int dewine(int x)
{
	if(x > -20 && x < 20) return 0;
	return x;
}

int clamp(int x, int min, int max)
{
	if(x < min) return min;
	if(x > max) return max;
	return x;
}

task main()
{
	int spinnerspeed = 0;

	while(true)
	{
		// 6 8
		// 7 9

		motor[port6] =  dewine(vexRT[Ch3]) + dewine(vexRT[Ch4]) + dewine(vexRT[Ch1]);
		motor[port7] =  dewine(vexRT[Ch3]) - dewine(vexRT[Ch4]) + dewine(vexRT[Ch1]);
		motor[port8] = -dewine(vexRT[Ch3]) + dewine(vexRT[Ch4]) + dewine(vexRT[Ch1]);
		motor[port9] = -dewine(vexRT[Ch3]) - dewine(vexRT[Ch4]) + dewine(vexRT[Ch1]);

		if(vexRT[Btn6U]) {
			spinnerspeed = clamp(spinnerspeed + 1, -maxspinnerspeed, maxspinnerspeed);
		} else {
			if(spinnerspeed > 0) spinnerspeed = clamp(spinnerspeed - 1, -maxspinnerspeed, maxspinnerspeed);
			if(spinnerspeed < 0) spinnerspeed = clamp(spinnerspeed + 1, -maxspinnerspeed, maxspinnerspeed);
		}

		motor[port2] = floor(spinnerspeed);
		motor[port3] = floor(spinnerspeed);
		motor[port4] = floor(spinnerspeed);
		motor[port5] = floor(spinnerspeed);

		// Lift
		if(vexRT[Btn8U]) {
			motor[port10] =  127;
		} else if(vexRT[Btn8D]) {
			motor[port10] = -127;
		} else {
			motor[port10] =  0;
		}

		// Conveyor
		if(vexRT[Btn5U]) {
			motor[port1] =  127;
		} else if(vexRT[Btn5D]) {
			motor[port1] = -127;
		} else {
			motor[port1] =  0;
		}
	}
}