// paquetes C  
#include <math.h> 
#include <stdio.h>
#include <errno.h>
#include<stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

//#include "mkl_vsl.h"
//#include "mkl_vml.h" 
#include "mkl.h" 


//************************************************************
//*       PARAMETROS DEFINIDOS EN LA SIMULACION
//************************************************************


//************************************************************
//*      Constantes Matematicas
//************************************************************ 

#define PI acos(-1.) 
#define rPI sqrt(PI)
#define r2 sqrt(2.)
#define dr2 2.*r2 /* 2 x sqrt(2) */


// radio de las particulas
#define R 1.
// tamano del sistema
#define LX 10*R //112.09982432795857*R
#define LY LX //112.09982432795857*R
// tamano del sistema menos un radio (para situar las particulas)
#define LXR  LX*0.5-R
#define LYR  LY*0.5-R
// fraccion de empaquetamiento
//#define nu = 0.72


//************************************************************
//*       EVENT-DRIVEN ALGORITHM FUNCTIONS (Intel MKL-based)
//************************************************************

extern int gaussian(int gseed, int gn, double *gv, int ga, int gsigma);
extern int gamma_distr(int gmseed, int gmn, double *gmv, double gmalpha, double gma, double gmbeta);
extern int hash_heapsort_f( int n_heap, double *heap );
//extern int heapsort_f( int n_heap, double *heap );
extern int heapsort_i( int n_heap, int *heap );
extern int unif_f( int useed, int un, double *uv, int u_init, int u_final);
extern int unif_i( int uiseed, int uin, double *uiv, int ui_init, int ui_final);
