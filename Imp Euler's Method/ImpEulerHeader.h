#pragma once
#include <iostream>
#include <vector>


double step;
double gamma;
double x0;
double u0;


std::vector <double> x;
std::vector <double> u;
std::vector <double> y;
std::vector <double> approximation;


void Solve();
void Input();
void ClearVectors();
void Output(std::string filename);
void InitFirstElements();
