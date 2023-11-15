#include "params.h"

// *gmv : pointer to arr passed to gamma_distr; returns array gmv
// gmn: dimension of array passed
// gmseed: seed of distr generator
int unif_f( int useed, int un, double *uv, int u_init, int u_final){

  // rand uniform distribution, continuous version
  int str_err_code, fun_err_code, i;
  VSLStreamStatePtr ustream;

  /* gmn = sizeof(*gmv)/sizeof(float); */
  /* printf("gmn: %d\n", gmn); */
  
  mkl_peak_mem_usage(MKL_PEAK_MEM_ENABLE);

  printf("\n UNIFORM DISTRIBUTION \n");
  // initialize Basic Random Number Generator vsRngGamma( method, stream, n, r, alpha, a, beta );
  str_err_code = vslNewStream(&ustream, VSL_BRNG_ARS5, useed);
  printf("error status for rand str generation: %d\n", str_err_code);
  // create distribution function
  fun_err_code = vdRngUniform( VSL_RNG_METHOD_UNIFORM_STD, ustream, un, uv, u_init, u_final );
  printf("error status for rand distr function generation: %d\n", fun_err_code);

  str_err_code = vslDeleteStream(&ustream); 
  printf("error status for rand str deletion: %d\n", str_err_code);
  
  return 0;
  
}
