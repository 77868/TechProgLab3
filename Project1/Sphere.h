#ifndef SPHERE_H
#define SPHERE_H

#include "Polyhedron.h"

#define SPHERE 4

class Sphere :public Polyhedron
{
public:
	double volume()override;
	void showData()override;
	void save(std::ofstream& out)override;
	void edit()override;

	Sphere(std::ifstream& in);
	Sphere();
	~Sphere();

private:
	double radius;
};

#endif