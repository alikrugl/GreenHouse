// Цю програму створив Круглєня Олександр Сергійович з групи К-11
#include <iostream>
#include "GreenHouse.h"

using namespace std;

//дiї з теплицею
void Commands()
{
	cout << "Commands: " << endl
		<< "	1 - opens a window" << endl
		<< "	2 - closes a window" << endl
		<< "	3 - turns on a heater" << endl
		<< "	4 - turns off a heater" << endl
		<< "	5 - run process" << endl
		<< "	6 - stops the programm" << endl;
}

void Action(bool execute, Greenhouse* greenhouse)
{
	while (execute)
	{
		char command;
		cin >> command;
		switch (command)
		{
		case ('1'):
		{
			if (greenhouse->openWindow()) cout << "window opened!" << endl;
			else { cout << "window NOT opened!" << endl; }
			cout << greenhouse->operator string() << endl;
			Commands();
			execute = true;
			break;
		}
		case ('2'):
		{
			if (greenhouse->closeWindow()) cout << "window closed!" << endl;
			else { cout << "window NOT closed!" << endl; }
			cout << greenhouse->operator string() << endl;
			Commands();
			execute = true;
			break;
		}
		case ('3'):
		{
			if (greenhouse->turnOnHeater()) cout << "heater activated!" << endl;
			else { cout << "heater NOT activated!" << endl; }
			cout << greenhouse->operator string() << endl;
			Commands();
			execute = true;
			break;
		}
		case ('4'):
		{
			if (greenhouse->turnOffHeater()) cout << "heater stoped!" << endl;
			else { cout << "heater NOT stoped!" << endl; }
			cout << greenhouse->operator string() << endl;
			Commands();
			execute = true;
			break;
		}
		case ('5'):
		{
			if (greenhouse->executeProcess()) cout << "action completed" << endl;
			else { cout << "action NOT completed!" << endl; }
			cout << greenhouse->operator string() << endl;
			Commands();
			execute = true;
			break;
		}
		case ('6'):
		{
			cout << "model stopped!" << endl;
			cout << greenhouse->operator string() << endl;
			execute = false;
			break;
		}
		default:
		{
			cout << "You entered wrong command!Try again." << endl;
			Commands();
			execute = true;
			break;
		}
		}
	}
}



void RunGreenhouse(Greenhouse* greenhouse)
{
	bool execute = true;
	while (execute)
	{
		Action(execute, greenhouse);
	}

}
void Model(Greenhouse*& greenhouse)
{
	cout << "Choose the model of Greenhouse" << endl;
	cout << "1 - first model" << endl;
	cout << "2 - second model" << endl;
	int version;
	cin >> version;
	if (version == 1)
	{
		greenhouse = new Greenhouse_1();
		Commands();
		RunGreenhouse(greenhouse);
	}
	else	if (version == 2)
	{
		greenhouse = new Greenhouse_2();
		Commands();
		RunGreenhouse(greenhouse);
	}
	else
	{
		cout << "Wrong input" << endl;
	}
	delete greenhouse;
}

int main()
{
	Greenhouse* greenhouse;
	Model(greenhouse);
	system("pause");
	return 0;
}