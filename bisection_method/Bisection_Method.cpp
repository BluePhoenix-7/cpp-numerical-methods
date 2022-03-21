#define _USE_MATH_DEFINES      //this is required for using constants like M_PI from cmath library
 
#include <cmath>
#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;


//function whose roots are to be found f(x)
double Function(double x)
{
	return double(sin(x));
}

//function that contains the main algorithm: xl(left boundary), xr(right boundary), eta(accuracy), delta(sifference in f(x) in consecutive steps)
void BisectionMethod(double xl, double xr, double eta, double delta)
{	
	int N = 1;
	ofstream file;
	file.open ("BisectionMethod.txt");
	double xm = (xl+xr)/2;
	while(abs(Function(xm))>eta)
	{
		N++;
		if(abs(xl-xr)<delta)
		{
			break;	
		}
		if((Function(xm)<0 && Function(xl)<0) || (Function(xm)>0 && Function(xl)>0))
		{
			xl = xm;
		}else
		{
			xr = xm;
		}
		xm = (xl+xr)/2;
		file << fixed << setprecision(8) << double(xm) << " " << 0 <<endl;
		file << " " << endl;
		file << " " << endl;
	}
	cout << N << endl;
	file.close();
}

int main()
{
 	BisectionMethod(M_PI/2, 7*M_PI/4, 0.0000001 , 0.0000001);
 	return 0;
}