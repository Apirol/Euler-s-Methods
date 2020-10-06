#include <math.h>
#include <fstream>
#include <limits>
#include "ExpEulerMethod.h"



int main()
{
	Input();
	std::string fileNameForStep = "C:/Users/redut/source/repos/Numerical Methods Lab1/Data/FullStep.txt";

	Solve();
	Output(fileNameForStep);
	ClearVectors();

	step /= 2;
	fileNameForStep = "C:/Users/redut/source/repos/Numerical Methods Lab1/Data/HalfStep.txt";
	InitFirstElements();
	Solve();
	Output(fileNameForStep);
	ClearVectors();

	step /= 2;
	fileNameForStep = "C:/Users/redut/source/repos/Numerical Methods Lab1/Data/QuaterStep.txt";
	InitFirstElements();
	Solve();
	Output(fileNameForStep);
	ClearVectors();

	return 0;
}


void Input()
{
	setlocale(LC_CTYPE, "Rus");

	std::cout << "������� x: ";
	std::cin >> x0;
	x.push_back(x0);

	std::cout << "������� u: ";
	std::cin >> u0;
	u.push_back(u0);

	std::cout << "������� ���: ";
	std::cin >> step;



	y.push_back(x0);
	approximation.push_back(0);
}


void Solve()
{
	int numberOfSteps = (1 / step) + 1;
	for (int i = 1; i < numberOfSteps; i += 1)
	{
		x.push_back(x[i - 1] + step);
		y.push_back(x[i] * x[i]);
		u.push_back(u[i - 1] + step * ((u[i - 1] / x[i - 1]) + x[i - 1]));
		approximation.push_back(abs(u[i] - y[i]));
	}
}


void Output(std::string filename)
{
	std::fstream file(filename);
	std::cout << file.is_open();
	file.precision(7);

	file << "n" << "\t" << "x" << "\t" << "u" << "\t" << "y" << "\t" << "u - y" << std::endl;

	int sizeOfVectors = x.size();
	for (int i = 0; i < sizeOfVectors; i++) {
		file << i << "\t" << x[i] << "\t" << u[i] << "\t" << y[i] << "\t" << approximation[i] << std::endl;
	}
}


void ClearVectors()
{
	x.clear();
	y.clear();
	u.clear();
	approximation.clear();
}


void InitFirstElements()
{
	x.push_back(x0);
	y.push_back(x0);
	u.push_back(u0);
	approximation.push_back(0);
}