https://people/sc/fsu.edu/~jburkardt/f_src/f90_calls_c++/f90_calls_c++.html


F90_CALLS_C++
FORTRAN90 Program Calls C++ Function

F90_CALLS_C++ is a directory which demonstrates how a FORTRAN90 program can call a C++ function in a way that is "guaranteed" to work; in other words, the procedure follows rules laid down by the FORTRAN standard, and does not depend on any special or peculiar features of the FORTRAN and C++ compilers used to compile the programs.

Some reference books discuss this topic by showing little isolated pieces of code, which do not form a real program, and cannot actually be compiled or used. Since EVERYTHING has to be correctly written and working properly together to make this delicate operation happen, it is very important to have an entire calculation in mind, and to be able to examine the full FORTRAN and C++ source code, as well as the compile and load statements used.

The KRONROD example presented here involves a FORTRAN90 main program and a library of 4 C++ functions. For comparison, you can also look at a directory where the same calculation is done with the main program and library routines written in the same language. Simply go to the KRONROD directory for the language you are interested in.

The C++ functions used here are quite simple, and essentially are really C functions. In fact, this same example is available with the functions written explicitly in C. The differences between that C example and this C++ version are simply

    the functions are written in C++, and invoke C++ libraries and IO.
    the compile statement for the functions uses the C++ compiler;
    the load statement must explicitly request the standard C++ library;

This example does not show how to pass data that needs to have the form of a structure. It also does not deal with classes.

A FORTRAN90 program, subroutine, or function that will call a C++ function might try using the ISO C binding module. This was actually introduced as part of FORTRAN 2003, but your compiler may be willing to let your FORTRAN90 program access it. (If not, you might consider moving to FORTRAN 2003!). The ISO C bindings are made available by the statement:

        use iso_c_binding
      

You can also use fussier versions of this statement, such as

        use, intrinsic :: iso_c_binding
      

or

        use, intrinsic :: iso_c_binding, only : C_CHAR, C_NULL_CHAR
      

(Thanks to Alan Richardson for pointing out that the ISO C bindings were only added to the language in the 2003 definition of FORTRAN!)

Then you need to define an interface to the C++ function, which might read:

  interface
    subroutine kronrod ( n, eps, x, w1, w2 ) bind ( c )
      use iso_c_binding
      integer ( c_int ), VALUE :: n
      real ( c_double ), VALUE :: eps
      real ( c_double ) :: x(*)
      real ( c_double ) :: w1(*)
      real ( c_double ) :: w2(*)
    end subroutine kronrod
  end interface
      

Finally, to guarantee that FORTRAN and C++ agree on data types, you should declare any FORTRAN90 variables that will be passed through the C interface with statements like:

  integer ( c_int ), parameter :: n = 3
  real ( c_double ) eps
  real ( c_double ) x(n+1)
  real ( c_double ) w1(n+1)
  real ( c_double ) w2(n+1)
      

A special requirement when C++ is involved is that the extern "C" qualifier be used with all the function names that must be "visible" to the FORTRAN90 program. For this example, we simple declare all the C++ functions this way:

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
      

Licensing:

The computer code and data files described and made available on this web page are distributed under the GNU LGPL license.
Related Data and Programs:

C_CALLS_F77, C programs which call a FORTRAN77 subroutine.

C_CALLS_F90, C programs which call a FORTRAN90 subroutine.

C++_CALLS_F77, C++ programs which call a FORTRAN77 subroutine.

C++_CALLS_F90, C++ programs which call a FORTRAN90 subroutine.

F77_CALLS_C, FORTRAN77 programs which call a C function.

F77_CALLS_C++, FORTRAN77 programs which call a C++ function.

F90_CALLS_C, FORTRAN90 programs which call C to carry out an auxillary calculation.

F90_CALLS_MATLAB, FORTRAN90 programs which call MATLAB to carry out an auxillary calculation.

KRONROD, a C++ library which can compute a Gauss and Gauss-Kronrod pair of quadrature rules of arbitrary order, by Robert Piessens, Maria Branders.

MATLAB_CALLS_C, MATLAB programs which call a C function using the MEX facility;

MATLAB_CALLS_F77, MATLAB programs which call a FORTRAN77 function, using MATLAB's MEX facility.

MIXED, C programs which call a function written in another programming language.

MIXED,, C++ programs which call a function written in another programming language.

MIXED, FORTRAN77 programs which call a function written in another programming language.

MIXED, is a directory of FORTRAN90 programs which call a function written in another programming language.
Reference:

    The gfortran team,
    Using GNU Fortran,
    The Free Software Foundation, 2010.
    Fritz Keinert,
    Mathematics Department,
    Iowa State University,
    Calling FORTRAN Subroutines from Fortran, C and C++.
    Michael Metcalf,
    Fortran95/2003 Explained,
    Oxford, 2004,
    ISBN: 0198526938,
    LC: QA76.73.F235.M48.
    Yang Wang, Raghurama Reddy, Roberto Gomez, Junwoo Lim, Sergiu Sanielevici, Jaideep Ray, James Sutherland, Jackie Chen,
    A General Approach to Creating Fortran Interface for C++ Application Libraries,
    Current Trends in High Performance Computing and its Applications, pages 145-154,
    edited by Wu Zhang, Zhangxin Chen, Roland Glowinski, Weiqin Tong,
    Springer, 2005,
    ISBN13: 978-3540257851,
    LC: QA76.88.I5663.

Source Code:

The KRONROD example involves a FORTRAN90 main program which calls directly the C++ functions "kronrod" and "timestamp".

    kronrod_prb.f90, the main program;
    kronrod.cpp, the library routines;
    kronrod.hpp, an include file;
    kronrod_output.txt, the output file.

You can go up one level to the FORTRAN90 source codes.
Last revised on 18 July 2012. 

/** COMPILING INSTRUCTIONS **/
1) g++ -c -o kronrod.o kronrod.cpp
2) gfortran -c -o kronrod_prb.o kronrod_prb.f90
3) gfortran kronrod.o kronrod_prb.o -o KRONROD -lstdc++

NOTE: conversely, if the main statement is in c++ and the roles were reversed, then you can link with
$g++ krondrod.o kronrod_prb.o -o KRONROD -lgfortran
