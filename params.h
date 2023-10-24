// paquetes C  
#include <math.h> 
#include <stdio.h>
#include <errno.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<time.h>
 
#include "mkl_vsl.h"
#include "mkl_vml.h" 
 

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



//************************************************************
//*       VARIABLES MKL-VSL 
//************************************************************


// declaracion de variables lazo de numeros aleatorios, 
// distr unif. continua
/* extern	int uerrcode; /\* parametro de error asociado *\/ */
/* extern  VSLStreamStatePtr ustream; */
/* // distr uniforme discreta  */
/* extern	int ierrcode;  */
/* extern  VSLStreamStatePtr istream; */
/* // distr gaussiana continua */
/* extern	int gerrcode; */
/* extern  VSLStreamStatePtr gstream; */
/* // distr rayleighiana continua */
/* extern	int derrcode; */
/* extern  VSLStreamStatePtr raystream; */
/* // distr gamma continua */

/* // number of particles */
/* extern const int npart; */
/* extern float *r; */

extern int gaussian(int gseed, int gn, float *gv);
extern int gamma_distr(int gmseed, int gmn, float *gmv);
