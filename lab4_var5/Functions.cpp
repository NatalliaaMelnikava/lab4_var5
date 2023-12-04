#include "Libraries.h"

void logarifm(const vector<double>&y,vector<double>&y1,const int N) {
	
	for (int i = 0; i < N; i++) {
		y1.push_back(log(y[i]));
	}
}



void POWERX_(int m, vector<double>&POWERX,int n,const vector<double>&x) {
	for (int k = 0; k < 2 * m; k++) {
		POWERX[k] = 0;
		for (int i = 0; i < n; i++) {
			POWERX[k] += pow(x[i], k + 1);
		}
	}
 }

void SUMX_(int m, int n,vector<vector<double>>&SUMX,vector<double>&POWERX,vector<int>&I) {
	for (int l = 0; l < m + 1; l++) {
		for (int j = 0; j < m + 1; j++) {
			if (j + l) {
				SUMX[l][j] = POWERX[l + j - 1];
			}
			else {
				SUMX[l][j] = n;
			}
		}
		I[l] = l + 1;
	}
}

void PRAW_(int m, int n, const vector<double>&y,const vector<double> &x, vector<double>& PRAW) {
	for (int l = 0; l < m+1; l++) {
		PRAW[l] = 0;
		for (int i = 0; i < n; i++) {
			PRAW[l] += y[i] * pow(x[i], l);//k1 = l - 1
		}
	}
}

double SIGMA(double S2,int N,const vector<double>&y,int m,const vector<double>&x,vector<double>&a) {
	
	for (int i = 0; i < N; i++)
	{
		double sum = y[i];
		for (int j = 0; j < m + 1; j++)
		{
			sum -= a[j] * pow(x[i], j);
		}
		S2 += pow(sum, 2);
	}
	S2 /= N - m - 1;
	double sigma = sqrt(S2);
	return sigma;
}