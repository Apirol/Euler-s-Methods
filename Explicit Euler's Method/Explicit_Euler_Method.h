#pragma once
#include <iostream>
#include <vector>


class Explicit_Euler_Method
{
public:
	double step;
	double x0;
	double u0;

	std::vector <double> x;
	std::vector <double> u;
	std::vector <double> y;
	std::vector <double> approximation;
};

