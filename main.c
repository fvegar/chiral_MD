#include "params.h"

//int gaussian( int gseed, int gn);

int main( int argc,  char *argv[] ){
  // distr gaussiana

  int i;
  int npart = atoi(argv[2]);
  int seed = atoi(argv[1]);
  double *vx, *vy, *x, *y, *w;
  vx = (double*)mkl_malloc(npart*npart*sizeof(double),64);
  vy = (double*)mkl_malloc(npart*npart*sizeof(double),64);
  x = (double*)mkl_malloc(npart*npart*sizeof(double),64);
  y = (double*)mkl_malloc(npart*npart*sizeof(double),64);

  gaussian( seed, npart, vx, 0., 1.);

  printf("results for a gaussian distribution:\n\n");
  for (i=0; i< npart; i++){

    printf("#%d (vx): %6.3f\n", i, vx[i]);
  
  }

  gamma_distr( seed, npart, vy, 2., 0., 2.);

  printf("results for a gamma distribution:\n\n");
  for (i=0; i< npart; i++){

    printf("#%d (vy): %6.3f\n", i, vy[i]);
  
  }


  heapsort_f(npart, vy);

  printf("results for the heaped gamma distribution:\n\n");
      
  for (i=0; i< npart; i++){
    printf("#%d (vy): %6.3f\n", i, vy[i]);
   }
   
  return 0;
  
}
