#include <stdio.h>
#include "mkl_vsl.h"
#include "mkl_vml.h" 
#include "mkl.h" 
#include "params.h"

//int gaussian( int gseed, int gn);

int main( int argc,  char *argv[] ){
  // distr gaussiana

  int i;
  int npart = atoi(argv[2]);
  int seed = atoi(argv[1]);
  float *vx, *vy, *x, *y, *w;
  vx = (float*)mkl_malloc(npart*npart*sizeof(float),64);
  vy = (float*)mkl_malloc(npart*npart*sizeof(float),64);
  x = (float*)mkl_malloc(npart*npart*sizeof(float),64);
  y = (float*)mkl_malloc(npart*npart*sizeof(float),64);

  
  gaussian( seed, npart, vx);

  for (i=0; i< npart; i++){

    printf("#%d: %6.3f\n", i, vx[i]);
  
  }

  gamma_distr( seed, npart, vx);

  //*v = (double)(*v);
  for (i=0; i< npart; i++){

    printf("#%d: %6.3f\n", i, vx[i]);
  
  }

  return 0;
  
}
