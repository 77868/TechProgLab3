#include "Tetrahedron.h"

Tetrahedron::Tetrahedron()
{
	system("cls");
	std::cout << "Введите значение высоты:" << std::endl;
	std::cin >> height;
	while (!std::cin.good() || height < 0)
	{
		std::cout << "Введено некоректное значение. Попробуйте ещё раз." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> height;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	system("cls");
	std::cout << "Введите значение площади основания:" << std::endl;
	std::cin >> base;
	while (!std::cin.good() || base < 0)
	{
		std::cout << "Введено некоректное значение. Попробуйте ещё раз." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> base;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
Tetrahedron::Tetrahedron(std::ifstream& in)
{
	in >> height;
	in >> base;
}
Tetrahedron::~Tetrahedron() {}

void Tetrahedron::save(std::ofstream& out)
{
	out << TETRAHEDRON << std::endl << height << std::endl << base << std::endl;
}

double Tetrahedron::volume()
{
	return (base * height)/3.0;
}
void Tetrahedron::showData()
{
	std::cout << "Фигура: Тетраэдр" << std::endl << "Высота: " << height << std::endl << "Площадь основания: " << base << std::endl;
}
void Tetrahedron::edit()
{
	system("cls");
	std::cout << "1 - изменить высоту\n2 - изменить площадь основания" << std::endl;
	int choise;
	std::cin >> choise;
	while (!std::cin.good() || choise < 1 || choise > 2)
	{
		std::cout << "Введено некоректное значение. Попробуйте ещё раз." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> choise;
	}
	switch (choise)
	{
	case 1:
		system("cls");
		std::cout << "Введите значение высоты:" << std::endl;
		std::cin >> height;
		while (!std::cin.good() || height < 0)
		{
			std::cout << "Введено некоректное значение. Попробуйте ещё раз." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> height;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		break;
	case 2:
		system("cls");
		std::cout << "Введите значение площади основания:" << std::endl;
		std::cin >> base;
		while (!std::cin.good() || base < 0)
		{
			std::cout << "Введено некоректное значение. Попробуйте ещё раз." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> base;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		break;
	}
}

