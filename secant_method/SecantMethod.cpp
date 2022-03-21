#define _USE_MATH_DEFINES      // this is required for using constants like M_PI from cmath library
 
#include <cmath>
#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;


// function whose roots are to be found f(x)
double Function(double x)
{
	return(pow(x,6)-x-1);
	//return(sin(x));
}


// In secant method we have to enter two guesses,x1: first guess,x2: second guess,error: as we decrease the error, accuracy increases
void SecantMethod(double x1, double x2, double error)
{
	ofstream file;
	file.open ("SecantMethod.txt");
	int N_max = 1000;  // maximum number of steps
	double X[N_max];   // array that contains progress with each step
	double err[N_max]; // array that will contain error at 
	int N = 0;         //number of steps
	X[0] = x1;
	X[1] = x2;
	for(int i = 1; i < N_max; i++)
	{
		X[i+1] = X[i] - (Function(X[i])*((X[i]-X[i-1])/(Function(X[i]) - Function(X[i-1]))));
		err[i] = abs((X[i+1] - X[i])/X[i]);
		if(err[i] < error)
		{
			break;
		}
		N++;
		file << fixed << setprecision(8) << double(X[i]) << " " << 0 <<endl;
		file << " " << endl;
		file << " " << endl;
	}
	cout << N << endl;
	file.close();
}

int main()
{
	SecantMethod(-0.5,-2,0.0000000001);
	return 0;
}