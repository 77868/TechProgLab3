#include "Sphere.h"
#include <cmath>

Sphere::Sphere()
{
	system("cls");
	std::cout << "Введите значение радиуса:" << std::endl;
	std::cin >> radius;
	while (!std::cin.good() || radius < 0)
	{
		std::cout << "Введено некоректное значение. Попробуйте ещё раз." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> radius;
	}
}
Sphere::Sphere(std::ifstream& in)
{
	in >> radius;
}
Sphere::~Sphere() {}

void Sphere::save(std::ofstream& out)
{
	out << SPHERE << std::endl << radius << std::endl;
}

double Sphere::volume()
{
	return (4 * radius * radius * radius * acos(-1)) / 3.0;
}
void Sphere::showData()
{
	std::cout << "Фигура: Сфера" << std::endl << "Радиус: " << radius << std::endl;
}
void Sphere::edit()
{
	
		system("cls");
		std::cout << "Введите значение радиуса:" << std::endl;
		std::cin >> radius;
		while (!std::cin.good() || radius < 0)
		{
			std::cout << "Введено некоректное значение. Попробуйте ещё раз." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> radius;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

