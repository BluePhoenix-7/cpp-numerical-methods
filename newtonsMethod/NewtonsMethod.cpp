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

// this is derivative of the function, as the form of the function is knowm the derivative can be found
double Dfunction(double x)
{
	return(6*pow(x,5)-1);
	//return(cos(x));
}

// In newton raphson we have to enter the first guess,x: first guess,error: as we decrease the error, accuracy increases
void NewtonRaphson(double x, double error)
{
	ofstream file;
	file.open ("NewtonRaphson.txt");
	int N_max = 1000; // maximum number of steps
	double X[N_max];   // array that contains progress with each step
	double err[N_max]; // array that will contain error at 
	int N = 0;         //number of steps
	X[0] = x;
	for(int i = 0; i < N_max; i++)
	{
		X[i+1] = X[i] - (Function(X[i])/Dfunction(X[i]));
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
	NewtonRaphson(-2,0.0000000001);
	return 0;
}