// �� �������� ������� ������� ��������� ��������� � ����� �-11
#include <iostream>
#include "GreenHouse.h"
#include <cmath>

using namespace std;

bool* State = new bool; // ������� ���� ����� FALSE - ��������, TRUE - ������
int* Windows = new int; //�������� ������� ����
int* OpenWindows = new int; // ����� �������� ���� � �����
int* Heaters = new int; //�������� ����� ��������� � �����
int* ActiveHeaters = new int; // ����� �������� ������������
double* Humidity = new double; //������� �������� 
double* Temperature = new double; //������� �����������

Greenhouse::Greenhouse()
{
	*State = true;
	*Windows = 1;
	*OpenWindows = 0;
	*Heaters = 4;
	*ActiveHeaters = 0;
	*Humidity = 37.2;
	*Temperature = 17.7;
}


bool Greenhouse::getState()
{
	return *State;
}

int Greenhouse::getWindows()
{
	return *Windows;
}

int Greenhouse::getOpenWindows()
{
	return *OpenWindows;
}

int Greenhouse::getHeaters()
{
	return *Heaters;
}

int Greenhouse::getActiveHeaters()
{
	return *ActiveHeaters;
}

double Greenhouse::getHumidity()
{
	return *Humidity;
}

double Greenhouse::getTemperature()
{
	return *Temperature;
}

bool Greenhouse::openWindow()
{
	bool success;
	if (*OpenWindows < *Windows) //���� ����� �������� ���� ����� ���������� ����� ����, �� ��������� ���� � ��������� TRUE
	{
		*OpenWindows = *OpenWindows + 1;
		success = true;
	}
	else success = false;
	return success;
}

bool Greenhouse::closeWindow()
{
	bool success;
	if (*OpenWindows > 0)  // ���� ����� �������� ���� ����� ����, �� ��������� ���� � ��������� TRUE
	{
		*OpenWindows = *OpenWindows - 1;
		success = true;
	}
	else success = false;
	return success;
}

bool Greenhouse::turnOnHeater()
{
	bool success;
	if (*ActiveHeaters < *Heaters)  // ���� ����� �������� ��������� ����� ���������� ����� ���������, �� ������� ������� � ��������� TRUE
	{
		*ActiveHeaters = *ActiveHeaters + 1;
		success = true;
	}
	else success = false;
	return success;
}

bool Greenhouse::turnOffHeater()
{
	bool success;
	if (*ActiveHeaters > 0)  // ���� ����� �������� ��������� ����� ����, �� �������� � ��������� TRU�
	{
		*ActiveHeaters = *ActiveHeaters - 1;
		success = true;
	}
	else success = false;
	return success;
}

bool Greenhouse::executeProcess()
{
	bool success = true;
	double t_old = *Temperature;
	double h_old = *Humidity;

	*Temperature = t_old - 1 * 1.1 - *OpenWindows * 1.1 + *ActiveHeaters * 1.7 + h_old * 0.01 * 1.5;

	if (t_old > 14)
	{
		*Humidity = h_old - (*OpenWindows - *ActiveHeaters) * 4.2;
	}
	else *Humidity = h_old + (*OpenWindows + *ActiveHeaters) * 5.0;

	return success;
}


Greenhouse_1::Greenhouse_1()
{
	*State = true;
	*Windows = 1;
	*OpenWindows = 0;
	*Heaters = 4;
	*ActiveHeaters = 0;
	*Humidity = 37.2;
	*Temperature = 17.7;
}

bool Greenhouse_1::executeProcess_1()
{
	bool success = true;
	double t_old = *Temperature;
	double h_old = *Humidity;

	*Temperature = t_old - 1 * 1.1 - *OpenWindows * 1.1 + *ActiveHeaters * 1.7 + h_old * 0.01 * 1.5;

	if (t_old > 14)
	{
		*Humidity = h_old - (*OpenWindows - *ActiveHeaters) * 4.2;
	}
	else *Humidity = h_old + (*OpenWindows + *ActiveHeaters) * 5.0;

	return success;
}


std::string Greenhouse_1::Version() const
{
	return "FIRST model of greenhouse!";
}

void Greenhouse_1::checkState_1()
{
	if ((*Temperature < 3.3) || (*Temperature > (31.5 + *Humidity * 1.0 * 0.01)) || (*Humidity < 5.6) || (*Humidity > 84.2))
	{
		*State = false;
	}
	else *State = true;
}
Greenhouse::operator std::string()const
{
	cout << "Current state: " << endl;
	if (*State) cout << "   Working" << endl;
	else cout << "   Stopped";
	string s = "   " + Version() + '\n'
		+ "   Open Windows : " + to_string(*OpenWindows) + '\n'
		+ "   Active Heaters :" + to_string(*ActiveHeaters) + '\n'
		+ "   Temperature :" + to_string(*Temperature) + '\n'
		+ "   Humidity :" + to_string(*Humidity) + '\n';
	return s;
}

std::string Greenhouse::Version() const
{
	return std::string();
}

Greenhouse_2::Greenhouse_2()
{
	*State = true;
	*Windows = 5;
	*OpenWindows = 0;
	*Heaters = 4;
	*ActiveHeaters = 0;
	*Humidity = 46.6;
	*Temperature = 18.6;
}

bool Greenhouse_2::executeProcess_2()
{
	bool success = true;
	double t_old = *Temperature;
	double h_old = *Humidity;

	*Temperature = t_old - 5 * 0.65 - pow(*OpenWindows, 2 * 1.0) + *ActiveHeaters * 1.6 - h_old * 0.01 * 1.2;

	if (t_old > 12)
	{
		*Humidity = h_old + 3.4 * log10(*OpenWindows - *ActiveHeaters);
	}
	else *Humidity = h_old - (*OpenWindows - *ActiveHeaters) * 4.3;

	return success;
}

std::string Greenhouse_2::Version() const
{
	return "SECOND model of greenhouse!";
}
