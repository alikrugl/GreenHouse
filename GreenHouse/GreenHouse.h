// Цю програму створив Круглєня Олександр Сергійович з групи К-11

#pragma once
#include <string>

class Greenhouse
{
public:
	// конструктор класа ініціалізує змінні відповідно до завдання
	Greenhouse();

	virtual ~Greenhouse() = default;

	Greenhouse(const Greenhouse&) = default;
	Greenhouse& operator = (const Greenhouse&) = default;
	Greenhouse(Greenhouse&&) = default;
	Greenhouse& operator = (Greenhouse&&) = default;

	// методи, які повертають елементи параметри класу
	bool getState();
	int getWindows();
	int getOpenWindows();
	int getHeaters();
	int getActiveHeaters();
	double getHumidity();
	double getTemperature();

	operator std::string()const;// повертає дані теплиці

	virtual std::string Version()const;// рядок з назвою моделі теплиці

	// метод, який відкриває вікно
	bool openWindow();

	// метод, який зачиняє вікно
	bool closeWindow();

	// метод, який вмикає обігрівач
	bool turnOnHeater();

	// метод, який вимикає обігрівач
	bool turnOffHeater();

	// розраховуємо вологість і температуру відповідно до формул в завданні
	virtual bool executeProcess();

	// проводимо перевірку умов зупинки моделі відповідно до завдання
	void checkState();

};

class Greenhouse_1 : public Greenhouse
{
public:
	Greenhouse_1();
	bool executeProcess_1();
	void checkState_1();
	std::string Version() const;
};



class Greenhouse_2 : public Greenhouse
{
public:
	Greenhouse_2();
	bool executeProcess_2();
	std::string Version() const;
};
