#include "params.h"

// *uv : pointer to arr passed to unif_f; returns array uv
// un: dimension of array passed
// useed: seed of distr generator
int unif_f( int useed, int un, double *uv, int u_init, int u_final){

  // rand uniform distribution, continuous version
  int str_err_code, fun_err_code, i;
  VSLStreamStatePtr ustream;

  /* gmn = sizeof(*gmv)/sizeof(float); */
  /* printf("gmn: %d\n", gmn); */
  
  mkl_peak_mem_usage(MKL_PEAK_MEM_ENABLE);

  printf("\n UNIFORM DISTRIBUTION \n");
  // initialize Basic Random Number Generator. here: ARS5
  str_err_code = vslNewStream(&ustream, VSL_BRNG_ARS5, useed);
  printf("error status for rand str generation: %d\n", str_err_code);
  // create distribution function
  fun_err_code = vdRngUniform( VSL_RNG_METHOD_UNIFORM_STD, ustream, un, uv, u_init, u_final );
  printf("error status for rand distr function generation: %d\n", fun_err_code);

  str_err_code = vslDeleteStream(&ustream); 
  printf("error status for rand str deletion: %d\n", str_err_code);

  /* printf("\nPeak memory allocated by Intel MKL memory allocator after reset of peak memory counter %d bytes\n",
     mkl_peak_mem_usage(MKL_PEAK_MEM)); */
  
  return 0;
  
}
