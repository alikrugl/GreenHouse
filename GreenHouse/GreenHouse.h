// �� �������� ������� ������� ��������� ��������� � ����� �-11

#pragma once
#include <string>

class Greenhouse
{
public:
	// ����������� ����� �������� ���� �������� �� ��������
	Greenhouse();

	virtual ~Greenhouse() = default;

	Greenhouse(const Greenhouse&) = default;
	Greenhouse& operator = (const Greenhouse&) = default;
	Greenhouse(Greenhouse&&) = default;
	Greenhouse& operator = (Greenhouse&&) = default;

	// ������, �� ���������� �������� ��������� �����
	bool getState();
	int getWindows();
	int getOpenWindows();
	int getHeaters();
	int getActiveHeaters();
	double getHumidity();
	double getTemperature();

	operator std::string()const;// ������� ��� �������

	virtual std::string Version()const;// ����� � ������ ����� �������

	// �����, ���� ������� ����
	bool openWindow();

	// �����, ���� ������� ����
	bool closeWindow();

	// �����, ���� ����� �������
	bool turnOnHeater();

	// �����, ���� ������ �������
	bool turnOffHeater();

	// ����������� �������� � ����������� �������� �� ������ � �������
	virtual bool executeProcess();

	// ��������� �������� ���� ������� ����� �������� �� ��������
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