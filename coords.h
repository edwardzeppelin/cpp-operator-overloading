#ifndef COORDS_H
#define COORDS_H

#include <iostream>

class coords {
private:
	int x;
	int y;
	int z;

public:
	~coords();

	coords(int x1, int y1, int z1);

	explicit coords();

	void printcoords();

	coords operator ! () { return coords (-x,-y,-z); }

    int getx() { return x; }
    int gety() { return y; }
    int getz() { return z; }

    coords& operator++(); //prefix
    coords operator++(int); //postfix

    coords& operator--(); //prefix
    coords operator--(int); //postfix

    friend std::ostream& operator<<(std::ostream& out, const coords& v);

};

#endif