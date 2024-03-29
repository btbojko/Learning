
#ifndef KRONROD_H_
#define KRONROD_H_

# include <cstdlib>
# include <iostream>
# include <cmath>
# include <ctime>

extern "C" 
{
  void abwe1 ( int n, int m, double eps, double coef2, bool even, double b[], 
    double *x, double *w );
  void abwe2 ( int n, int m, double eps, double coef2, bool even, double b[], 
    double *x, double *w1, double *w2 );
  void kronrod ( int n, double eps, double x[], double w1[], double w2[] );
  double r8_abs ( double x );
  void timestamp ( );
}

#endif /* KRONROD_H_ */
