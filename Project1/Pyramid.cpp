#include "Pyramid.h"

Pyramid::Pyramid()
{
	system("cls");
	std::cout << "������� �������� ������:" << std::endl;
	std::cin >> height;
	while (!std::cin.good() || height < 0)
	{
		std::cout << "������� ����������� ��������. ���������� ��� ���." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> height;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	system("cls");
	std::cout << "������� �������� ������� ���������:" << std::endl;
	std::cin >> base;
	while (!std::cin.good() || base < 0)
	{
		std::cout << "������� ����������� ��������. ���������� ��� ���." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> base;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
Pyramid::Pyramid(std::ifstream& in)
{
	in >> height;
	in >> base;
}
Pyramid::~Pyramid() {}

void Pyramid::save(std::ofstream& out)
{
	out << PYRAMID<< std::endl << height << std::endl << base << std::endl;
}

double Pyramid::volume()
{
	return (base * height)/3;
}
void Pyramid::showData()
{
	std::cout << "������: ��������" << std::endl << "������: " << height << std::endl << "������� ���������: " << base << std::endl;
}
void Pyramid::edit()
{
	system("cls");
	std::cout << "1 - �������� ������\n2 - �������� ������� ���������" << std::endl;
	int choise;
	std::cin >> choise;
	while (!std::cin.good() || choise < 1 || choise > 2)
	{
		std::cout << "������� ����������� ��������. ���������� ��� ���." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> choise;
	}
	switch (choise)
	{
	case 1:
		system("cls");
		std::cout << "������� �������� ������:" << std::endl;
		std::cin >> height;
		while (!std::cin.good() || height < 0)
		{
			std::cout << "������� ����������� ��������. ���������� ��� ���." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> height;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		break;
	case 2:
		system("cls");
		std::cout << "������� �������� ������� ���������:" << std::endl;
		std::cin >> base;
		while (!std::cin.good() || base < 0)
		{
			std::cout << "������� ����������� ��������. ���������� ��� ���." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> base;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		break;
	}
}