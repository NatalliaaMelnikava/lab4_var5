#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;
void logarifm(const vector<double>&, vector<double>&,const int);
vector<double> gauss(vector<vector<double>>&, vector<double>&, int);
void POWERX_(int, vector<double>&, int, const vector<double>&);
void SUMX_(int, int, vector<vector<double>>&, vector<double>&,vector<int>&);
void PRAW_(int, int, const vector<double>&, const vector<double>&, vector<double>&);
double SIGMA(double, int, const vector<double>&, int, const vector<double>&, vector<double>&);