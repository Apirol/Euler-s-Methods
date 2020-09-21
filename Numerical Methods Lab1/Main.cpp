#include <iostream>
#include <vector>
#include <math.h>

std::vector <double> x;
std::vector <double> u;
std::vector <double> y;
std::vector <double> approximation;

double step;
void Solve();
void Input();
void ClearVectors();


int main()
{
	Input();
	Solve();
	ClearVectors();
	step /= 2;
	Solve();
	ClearVectors();
	step /= 2;
	Solve();
}


void Input()
{
	setlocale(LC_CTYPE, "Rus");
	double firstX;
	double firstU;

	std::cout << "¬ведите x: ";
	std::cin >> firstX;
	x.push_back(firstX);

	std::cout << "¬ведите u: ";
	std::cin >> firstU;
	u.push_back(firstU);

	std::cout << "¬ведите шаг: ";
	std::cin >> step;

	y.push_back(firstX);
	approximation.push_back(0);
}


void Solve()
{
	int numberOfSteps = (1 / step) + 1;
	for (int i = 1;  i <  numberOfSteps; i += 1)
	{
		x.push_back(x[i - 1] + step);
		y.push_back(x[i] * x[i]);
		u.push_back(u[i - 1] + step * ((u[i - 1] / x[i - 1]) + x[i - 1]));
		approximation.push_back(abs(u[i] - y[i]));
	}
}


void ClearVectors()
{
	x.clear();
	y.clear();
	u.clear();
	approximation.clear();
}


void Output()
{
/*	int sizeOfVectors = x.size();

	for (int i = 0; i < sizeOfVectors; i++)
	{
		x[i]
	}*/
}