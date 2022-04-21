#ifndef POLYHEDRON_H
#define POLYHEDRON_H
#include <iostream>
#include <fstream>

class Polyhedron
{
public:
	virtual double volume() = 0;
	virtual void showData() = 0;
	virtual void save(std::ofstream& out) = 0;
	virtual void edit() = 0;
	
	virtual ~Polyhedron();
private:
};
#endif