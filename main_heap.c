#include "params.h"

/* ###############################################
   #######   CHIRAL MD (DISKS) ###################
   ############################################### */ 

// By F. Vega Reyes. 2024. fvega@eaphysics.xyz

// ############# USAGE: ./CHIRAL npart seed ######### where npart is no. of particles (int)
// amd seed is the rand no. gen. seed (prime int)

double *vx, *vy, *x, *y, *tc;

int main( int argc,  char *argv[] ){

  int i;
  int npart = atoi(argv[2]);
  int seed = atoi(argv[1]);
  double tc;

  vx = (double*)mkl_malloc(npart*npart*sizeof(double),64);

  vy = (double*)mkl_malloc(npart*npart*sizeof(double),64);

  x = (double*)mkl_malloc(npart*npart*sizeof(double),64);

  y = (double*)mkl_malloc(npart*npart*sizeof(double),64);
  

  unif_f(seed, npart, x, -LXR, LXR);

  printf("results for a uniform (float) distribution:\n\n");
  for (i=0; i< npart; i++){
    
    printf("#%d (vx): %6.3f\n", i, x[i]);
  
  }

  hash_heapsort_f(npart, x);

  printf("results for the heaped gaussian distribution:\n\n");
      
  for (i=0; i< npart; i++){
    printf("#%d (vy): %6.3f\n", i, x[i]);
   }

  /* mkl_free(x); */

  
  gaussian( seed, npart, vx, 0., 1.);

  printf("results for a gaussian distribution:\n\n");
  for (i=0; i< npart; i++){

    printf("#%d (vx): %6.3f\n", i, vx[i]);
  
  }

  hash_heapsort_f(npart, vx);

  printf("results for the heaped gaussian distribution:\n\n");
      
  for (i=0; i< npart; i++){
    printf("#%d (vx): %6.3f\n", i, vx[i]);
   }

  /* mkl_free(vx); */
  
  gamma_distr( seed, npart, vy, 2., 0., 2.);
  
  //vy[0] = INFINITY;
  //vy[2] = INFINITY;
  
  printf("results for a gamma distribution:\n\n");
  for (i=0; i< npart; i++){

    printf("#%d (vy): %6.3f\n", i, vy[i]);
  
  }


  hash_heapsort_f(npart, vy);

  printf("results for the heaped gamma distribution:\n\n");
      
  for (i=0; i< npart; i++){
    printf("#%d (vy): %6.3f\n", i, vy[i]);
   }

  tc = tcol(1, 2);

  printf("collision time: %f\n", tc);
  
  mkl_free(x);
  mkl_free(vx);

  mkl_free(vy);
  
  return 0;
  
}
