#include "params.h"

/* ###############################################
   #######   CHIRAL MD (DISKS) ###################
   ############################################### */ 

// By F. Vega Reyes. 2024. fvega@eaphysics.xyz

// ############# USAGE: ./CHIRAL npart seed ######### where npart is no. of particles (int)
// amd seed is the rand no. gen. seed (prime int)

#include <malloc.h>

double *vx, *vy, *x, *y;
double *tc_list;
double *col_heap;

int main( int argc,  char *argv[] ){

  int i, j, k;
  int npart = atoi(argv[2]);
  int seed = atoi(argv[1]);
  double tc; // collision time
  double ncols;
  
    //  Memory allocates dynamically using calloc() 
  tc_list = (double*)calloc(npart*(npart-1)/2, sizeof(double));
  //printf("arraySize: %zu\n", malloc_usable_size(ptr)/sizeof(double) );
  
  for (i = 0; i < npart; i++) tc_list[i] = i * 1.0;
  for (i = 0; i < npart; i++) printf("malloc tc_list(%d): %f\n", i, tc_list[i]);
    
  tc_list = realloc(tc_list, 2* npart * sizeof(double));
  for (i = 0; i < 2 * npart; i++) tc_list[i] = i * 1.0;
  for (i = 0; i < 2 * npart; i++) printf("realloc tc_list(%d): %f\n", i, tc_list[i]);

  tc_list = realloc(tc_list, npart * sizeof(double));
  for (i = 0; i < 2 * npart; i++) tc_list[i] = i * 1.0;
  for (i = 0; i < 2 * npart; i++) printf("realloc tc_list(%d): %f\n", i, tc_list[i]);

  
  // allocate velocity variables
  vx = (double*)mkl_malloc(npart*npart*sizeof(double),64);
  vy = (double*)mkl_malloc(npart*npart*sizeof(double),64);

  // allocate position variales
  x = (double*)mkl_malloc(npart*npart*sizeof(double),64);
  y = (double*)mkl_malloc(npart*npart*sizeof(double),64);


  // generate uniform distribution of particles
  unif_f(seed, npart, x, -LXR, LXR, 0); // X coordinate
  unif_f(seed, npart, y, -LYR, LYR, 0); // Y coordinate
  printf("Particle positions uniformly distributed\n");

  
  // generate gaussian velocitiy distribution
  gaussian( seed, npart, vx, 0., 1., 0); // Vx component
  gaussian( seed, npart, vy, 0., 1., 0); // Vy component
  printf("Particle velocities generated (Gaussian distribution)\n");


  k = 0;
  for (i=0; i < npart-1; i++){
    for (j > i; j < npart; j++){

      tc = tcol(i, j);
      
      if (tc < INFINITY){
	tc_list[k] = tc;
	k++;
      } // collision condition
      
    } // j loop
  } // i loop
  ncols = k;

  col_heap = (double*)malloc(ncols, sizeof(double));

  /* hash_heapsort_f(ncols, col_heap); */
  
  
  mkl_free(x);
  mkl_free(y);
  
  mkl_free(vx);
  mkl_free(vy);
  
  return 0;
  
}
