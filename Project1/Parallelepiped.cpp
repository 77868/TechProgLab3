#include "Parallelepiped.h"

Parallelepiped::Parallelepiped()
{
	system("cls");
	std::cout << "Введите значение высоты:" << std::endl;
	std::cin >>height;
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
Parallelepiped::Parallelepiped(std::ifstream& in)
{
	in >> height;
	in >> base;
}
Parallelepiped::~Parallelepiped(){}

void Parallelepiped::save(std::ofstream& out)
{
	out << PARALLELEPIPED<<std::endl<<height<< std::endl << base << std::endl;
}

double Parallelepiped::volume()
{
	return base * height;
}
void Parallelepiped::showData()
{
	std::cout << "Фигура: Параллелепипед"<<std::endl<<"Высота: " << height << std::endl << "Площадь основания: " << base << std::endl;
}
void Parallelepiped::edit()
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

