#ifndef PYRAMID_H
#define PYRAMID_H

#include "Polyhedron.h"

#define PYRAMID 2

class Pyramid: public Polyhedron
{
public:
	double volume()override;
	void showData()override;
	void save(std::ofstream& out)override;
	void edit()override;

	Pyramid();
	Pyramid(std::ifstream& in);
	~Pyramid();

private:
	double height, base;
};

#endif
