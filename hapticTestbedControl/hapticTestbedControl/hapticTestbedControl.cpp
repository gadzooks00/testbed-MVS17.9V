// hapticTestbedControl.cpp : This file send messages using the MAXON motor controller EPOS
// library to the EPOS controllers and measures forces/torques from the NI DAQ simultatneously.
// Hardware used with this program include: 2 custom MAXON motors, 2 EPOS4 24/1.5 CAN Motor
// controllers, 2 Nano 25 ATI Force/Torque Sensors, and 1 NI DAQ for the force sensors.
// Author(s): Zane Zook (gadzooks@rice.edu)

#include "pch.h"
#include <iostream>
#include "Definitions.h"

void initiateControllers(HANDLE &keyHandleA, HANDLE &keyHandleB, DWORD &errorCode)
{
	char* deviceName = (char*)"EPOS4";
	char* protocalStackName = (char*)"MAXON SERIAL V2";
	char* interfaceName = (char*)"USB";
	char* portNameA = (char*)"USB1";
	char* portNameB = (char*)"USB0";
	

	keyHandleA = VCS_OpenDevice(deviceName, protocalStackName, interfaceName, portNameA, &errorCode);
	if (keyHandleA > 0)
	{
		VCS_CloseDevice(keyHandleA, &errorCode);
	}
	keyHandleB = VCS_OpenDevice(deviceName, protocalStackName, interfaceName, portNameB, &errorCode);
	if (keyHandleB > 0)
	{
		VCS_CloseDevice(keyHandleB, &errorCode);
	}

	std::cout << "Hello, Motor Controller ";
	std::cout << keyHandleA;
	std::cout << " and Motor Controller ";
	std::cout << keyHandleB;
	std::cout << " have been opened!\n";
}

int main()
{
	HANDLE keyHandleA = 0;
	HANDLE keyHandleB = 0;
	DWORD errorCode = 0;
	initiateControllers(keyHandleA, keyHandleB, errorCode);
}