#include "params.h"
#include <mkl.h>
#include <stdio.h>


int gaussian( int gseed, int gn, float *gv){

  // distr gaussiana
  FILE *fp;
  int str_err_code, fun_err_code, i;
  VSLStreamStatePtr gstream;

  //gv = (float*)mkl_malloc(npart*npart*sizeof(float),64);

  mkl_peak_mem_usage(MKL_PEAK_MEM_ENABLE);
  // initialize Basic Random Number Generator
  str_err_code = vslNewStream(&gstream, VSL_BRNG_PHILOX4X32X10, gseed);
  printf("\n GAUSSIAN DISTRIBUTION \n");
  printf("error status for rand str generation: %d\n", str_err_code);
  fun_err_code = vsRngGaussian(VSL_RNG_METHOD_GAUSSIAN_BOXMULLER2, gstream, gn, gv, 0., 1. );
  printf("error status for rand distr function generation: %d\n", fun_err_code);

  str_err_code = vslDeleteStream(&gstream); 
  printf("error status for rand str deletion: %d\n", str_err_code);
  
  return 0;
  
}
