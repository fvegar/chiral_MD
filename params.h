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


// radius of particles
#define R 1.
// system size
#define LX 10*R //112.09982432795857*R
#define LY LX //112.09982432795857*R
// system size minus radius of particles
#define LXR  LX*0.5-R
#define LYR  LY*0.5-R
// fraccion de empaquetamiento
//#define nu = 0.72
#define alpha 0.999

extern double *w, *vx, *vy, *x, *y, *w;
//extern int *hash_ij;
// structure template 
struct collisions { 
    double ct; 
    int p1; 
    int p2; 
}; 
extern struct collisions *heap;

extern int Ncol, Npairs;
