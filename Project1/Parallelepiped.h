
#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H

#include "Polyhedron.h"

#define PARALLELEPIPED 1

class Parallelepiped: public Polyhedron
{
public:

	double volume()override;
	void showData()override;
	void save(std::ofstream& out)override;
	void edit()override;

	Parallelepiped(std::ifstream& in);
	Parallelepiped();
	~Parallelepiped();

private:
	double height, base;
};
#endif 
