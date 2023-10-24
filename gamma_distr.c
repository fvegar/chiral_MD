#include "params.h"
#include <mkl.h>
#include <stdio.h>


int gamma_distr( int gmseed, int gmn){

  // distr gaussiana
  FILE * fp;
  int str_err_code, fun_err_code, i;
  float *r;
  VSLStreamStatePtr gmstream;

  
  const int npart = gmn;

  r = (float*)mkl_malloc(npart*npart*sizeof(float),64);

  mkl_peak_mem_usage(MKL_PEAK_MEM_ENABLE);

  // initialize Basic Random Number Generator vsRngGamma( method, stream, n, r, alpha, a, beta );
  str_err_code = vslNewStream(&gmstream, VSL_BRNG_PHILOX4X32X10, gmseed);
  printf("error status for rand str generation: %d\n", str_err_code);
  // create distribution function
  fun_err_code = vsRngGamma(VSL_RNG_METHOD_GAMMA_GNORM_ACCURATE, gmstream, npart, r, 2., 0., 2. );
  printf("error status for rand distr function generation: %d\n", fun_err_code);

  for (i=0; i< npart; i++){

    printf("#%d: %6.3f\n", i,r[i]);
  
  }

  str_err_code = vslDeleteStream(&gmstream); 
  printf("error status for rand str deletion: %d\n", str_err_code);
  
  return 0;
  
}
