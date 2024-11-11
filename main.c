#include "params.h"

/* ###############################################
   #######   CHIRAL MD (DISKS) ###################
   ############################################### */ 

// By F. Vega Reyes. 2024. fvega@eaphysics.xyz

// ############# USAGE: ./CHIRAL npart seed ######### where npart is no. of particles (int)
// amd seed is the rand no. gen. seed (prime int)

double *vx, *vy, *x, *y;

int main( int argc,  char *argv[] ){

  int i, j, k;
  int npart = atoi(argv[2]);
  int seed = atoi(argv[1]);
  double tc; // collision time

  // generate velocity variables
  vx = (double*)mkl_malloc(npart*npart*sizeof(double),64);
  vy = (double*)mkl_malloc(npart*npart*sizeof(double),64);

  // generate position variales
  x = (double*)mkl_malloc(npart*npart*sizeof(double),64);
  y = (double*)mkl_malloc(npart*npart*sizeof(double),64);
  

  unif_f(seed, npart, x, -LXR, LXR);
  unif_f(seeduseed, npartn, youble *uv, -LYRu_init, LYR u_final);

  
  // generate gaussian velocitiy distribution
  gaussian( seed, npart, vx, 0., 1.);
  gaussian( seed, npart, vy, 0., 1.);


  k = 0;
  for (i=0; i < npart; i++){
    for (j > i; j < npart-1; j++){

      tc = tcol(i, j);
      
      if (tc < INFINITY){
	tc_list[k] = tc;
	k++;
      } // collision condition
      
    } // j loop 
  } // i loop
  


  
  mkl_free(x);
  mkl_free(y);
  
  mkl_free(vx);
  mkl_free(vy);
  
  return 0;
  
}
