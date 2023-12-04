
#include "Libraries.h"


int main()
{
	//y = a * exp(-b * x);
	vector<double>x = { 60,70,80,90,100,110,120 };
	vector<double>y = { 0.0148,0.0124,0.0102,0.0085,0.0071,0.0059,0.0051 };
	const int N = 7;
	

	vector<double>y1;
	logarifm(y,y1,N);//ln(y)=ln(a) - b * x;
	
	const int m = 1;
	vector<int>I(m + 1);
	vector<double>POWERX(2 * m);
	vector<vector<double>>SUMX(m + 1,vector<double>(m+1));
	vector<double>PRAW(m + 1);
	POWERX_(m, POWERX, N, x);
	SUMX_(m, N, SUMX, POWERX,I);
	PRAW_(m, N, y1,x, PRAW);
	vector<double>c = gauss(SUMX, PRAW, m + 1);
	double S2 = 0;
	double s = SIGMA(S2, N, y1, m, x, c);
	
	cout << "a: " << exp(c[0]) << "\nb: " << c[1] * (-1) << endl << "sigma: " << setprecision(5) << s << endl;

	cout << "x" << setw(10) << "f(x)" << setw(10) << "q(x)"<< setw(10) << "i" << endl;
	for (int i = 0; i < m+1; i++) {
		cout << x[i] << setw(10) << y[i] << setw(10) <<PRAW[i] << setw(10) << I[i] << endl;
	}
	for (int i =  m+1; i < N; i++) {
		cout << x[i] << setw(10) << y[i] << endl;
	}

	vector<double>checking(N);

	cout << "checking the correct work: " << endl;
	for (int i = 0; i < N; i++) {
		checking[i] = 0.0433673 * exp(-0.0180141 * x[i]);
		cout << "y"<< i << ": " << checking[i] << endl;
	}
	
}
