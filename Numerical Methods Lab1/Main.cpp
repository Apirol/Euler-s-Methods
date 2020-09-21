#include <iostream>
#include <vector>


std::vector <double> x;
std::vector <double> u;
std::vector <double> y;
std::vector <double> approximation;

double step;
void Solve();
void Input();


int main()
{
	Solve();
	step /= 2;
	Solve();
	step /= 2;
	Solve();
}


void Solve()
{
	Input();
	for (int i = 1;  i < 1 / step; i += 1)
	{
		x.push_back(x[i - 1] + step);
		y.push_back(x[i] * x[i]);
		u[i] = u[i - 1] + step * ((u[i - 1] / x[i - 1]) + x[i - 1]);
		approximation[i] = u[i] - y[i];
	}
}


void Input()
{
	setlocale(LC_CTYPE, "Rus");
	double firstX;
	std::cout << "¬ведите x ";
	std::cin >> firstX;
	x.push_back(firstX);
	double firstU;
	std::cout << "¬ведите u ";
	std::cin >> firstU;
	u.push_back(firstU);
	std::cout << "¬ведите h ";
	std::cin >> step;
	y.push_back(firstX);
}