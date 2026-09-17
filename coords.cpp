#include "coords.h"

using namespace std;

coords::~coords() {}

void coords::printcoords()
{
	cout << "X: " << x << "\tY: " << y << "\tZ: " << z << endl;
}

coords::coords(int x1, int y1, int z1) {
	x = x1;
	y = y1;
	z = z1;
}

coords::coords() {
	x = 10;
	y = 10;
	z = 10;
}

ostream& operator<< (std::ostream& out, const coords& v) {
	out << v.x;
	return out;
}

coords& coords::operator++() {
	int mincoord = min({ x, y, z });
	x += mincoord;
	y += mincoord;
	z += mincoord;
	return *this;
}

coords coords::operator++(int) {
	coords tmp(x, y, z);
	char coordinate;
	int number;
	cout << "Choose coordinate: " << endl;
	cin >> coordinate;

	if (coordinate == 'x') {
		cout << "Print a number: " << endl;
		cin >> number;
		x += number;
		return tmp;
	}

	if (coordinate == 'y') {
		cout << "Print a number: " << endl;
		cin >> number;
		y += number;
		return tmp;
	}

	if (coordinate == 'z') {
		cout << "Print a number: " << endl;
		cin >> number;
		z += number;
		return tmp;
	}
}

coords& coords::operator--() {
	int maxcoord = max({ x, y, z });
	x -= maxcoord;
	y -= maxcoord;
	z -= maxcoord;
	return *this;
}

coords coords::operator--(int) {
	coords tmp(x, y, z);
	char coordinate;
	int number;
	cout << "Choose coordinate: " << endl;
	cin >> coordinate;

	if (coordinate == 'x') {
		cout << "Print a number: " << endl;
		cin >> number;
		x -= number;
		return tmp;
	}

	if (coordinate == 'y') {
		cout << "Print a number: " << endl;
		cin >> number;
		y -= number;
		return tmp;
	}

	if (coordinate == 'z') {
		cout << "Print a number: " << endl;
		cin >> number;
		z -= number;
		return tmp;
	}
}

