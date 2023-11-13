#include "params.h"
#include <mkl.h>
#include <stdio.h>

// *gmv : pointer to arr passed to gamma_distr; returns array gmv
// gmn: dimension of array passed
// gmseed: seed of distr generator
int gamma_distr( int gmseed, int gmn, float *gmv){

  // distr gaussiana
  FILE *fp;
  int str_err_code, fun_err_code, i;
  VSLStreamStatePtr gmstream;

  /* gmn = sizeof(*gmv)/sizeof(float); */
  /* printf("gmn: %d\n", gmn); */
  
  mkl_peak_mem_usage(MKL_PEAK_MEM_ENABLE);

  // initialize Basic Random Number Generator vsRngGamma( method, stream, n, r, alpha, a, beta );
  str_err_code = vslNewStream(&gmstream, VSL_BRNG_PHILOX4X32X10, gmseed);
  printf("\n GAMMA DISTRIBUTION \n");
  printf("error status for rand str generation: %d\n", str_err_code);
  // create distribution function
  fun_err_code = vsRngGamma(VSL_RNG_METHOD_GAMMA_GNORM_ACCURATE, gmstream , gmn, gmv, 2., 0., 2. );
  printf("error status for rand distr function generation: %d\n", fun_err_code);

  str_err_code = vslDeleteStream(&gmstream); 
  printf("error status for rand str deletion: %d\n", str_err_code);
  
  return 0;
  
}
