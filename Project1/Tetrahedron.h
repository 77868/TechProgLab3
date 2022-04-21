#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include "Polyhedron.h"

#define TETRAHEDRON 3

class Tetrahedron :public Polyhedron
{
public:
	double volume()override;
	void showData()override;
	void save(std::ofstream& out)override;
	void edit()override;

	Tetrahedron(std::ifstream& in);
	Tetrahedron();
	~Tetrahedron();

private:
	double height, base;
};

#endif