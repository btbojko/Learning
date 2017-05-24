//============================================================================
// Name        : ARKTAT.cpp
// Author      : btbojko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <include/ARKTAT.h>
////#include <src/material/test_function.cpp>
////#include <include/material/test_function.h>
//
//using namespace std;
//using namespace ARKTAT;
//
//int main(void) {
//	Box* box1= new Box();
////	Box* box1 = new Box();
////	box1 -> setLength(2.);
//	box1 -> setLength(2.);
//    box1 -> setHeight(3.);
//    box1 -> setDepth(4.);
//
//    double volume = 0.;
//
//	cout << "Hello World!" << endl;
//
//	volume = box1 -> getVolume();
//	cout << "I created a box with a volume of : " << volume << endl;
//
//	delete box1;
//
//	return 0;
//}
/* cvpendulum.c -- pendulum demo
 * dbindel, Apr 2009.
 *
 * Adapted from  demo/cvode/serial/cdenx.c
 * by Scott Cohen, Alan Hindmarsh, and Radu Serban.
 *
 * For more info, see CVODE web page:
 *   https://computation.llnl.gov/casc/sundials/main.html
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cvode/cvode.h>
#include <nvector/nvector_serial.h>
#include <cvode/cvode_dense.h>
#include <sundials/sundials_dense.h>
#include <sundials/sundials_types.h>
static int f(realtype t, N_Vector y, N_Vector ydot, void *f_data)
{
	realtype theta = NV_Ith_S(y,0);
	realtype omega = NV_Ith_S(y,1);
	realtype omegap = -sin(theta);
	NV_Ith_S(ydot,0) = omega;
	NV_Ith_S(ydot,1) = omegap;
	return 0;
}
int main(int argc, char** argv)
{
	int N = 200;
	realtype T0 = 0;
	realtype Tfinal = 10;
	realtype theta0 = atof(argv[1]);
	realtype reltol = 1e-6;
	realtype abstol = 1e-8;
	realtype t;
	int flag, k;
	N_Vector y = NULL;
	void* cvode_mem = NULL;
	/* Create serial vector of length NEQ for I.C. */
	y = N_VNew_Serial(2);
	NV_Ith_S(y,0) = theta0;
	NV_Ith_S(y,1) = 0;
	/* Set up solver */
	cvode_mem = CVodeCreate(CV_ADAMS, CV_FUNCTIONAL);
	if (cvode_mem == 0) {
		fprintf(stderr, "Error in CVodeMalloc: could not allocate\n");
		return -1;
	}
	/* Call CVodeMalloc to initialize the integrator memory */
	//~ flag = CVodeMalloc(cvode_mem, f, T0, y, CV_SS, reltol, &abstol);
	flag = CVodeInit(cvode_mem, f, T0, y);
	if (flag < 0) {
		fprintf(stderr, "Error in CVodeMalloc: %d\n", flag);
		return -1;
	}
	/* Set the CVODE tolerances */
	flag = CVodeSStolerances(cvode_mem, reltol, abstol);
	if (flag < 0) {
		fprintf(stderr, "Error in CVodeSStolerances: %d\n", flag);
		return -1;
	}
	/* In loop, call CVode, print results, and test for error. */
	for (k = 1; k < N; ++k) {
		realtype tout = k*Tfinal/N;
		if (CVode(cvode_mem, tout, y, &t, CV_NORMAL) < 0) {
			fprintf(stderr, "Error in CVode: %d\n", flag);
			return -1;
		}
		std::cout << t <<"\t" << NV_Ith_S(y,0) << "\t" << NV_Ith_S(y,1) << std::endl;
//		printf("%g %.16e %.16e\n", t, NV_Ith_S(y,0), NV_Ith_S(y,1));
	}
	N_VDestroy_Serial(y);     /* Free y vector */
	CVodeFree(&cvode_mem);    /* Free integrator memory */
	return(0);
}
