#include "params.h"
#include "protos.h"

// *gmv : pointer to arr passed to gamma_distr; returns array gmv
// gmn: dimension of array passed
// gmseed: seed of distr generator
int unif_i( int uiseed, int uin, double *uiv, int ui_init, int ui_final, int ierr){

  // rand uniform distribution, continuous version
  int str_err_code, fun_err_code, i;
  VSLStreamStatePtr uistream;

  /* gmn = sizeof(*gmv)/sizeof(float); */
  /* printf("gmn: %d\n", gmn); */
  
  mkl_peak_mem_usage(MKL_PEAK_MEM_ENABLE);

  //printf("\n UNIFORM DISTRIBUTION, integer version \n");

  // initialize Basic Random Number Generator vsRngGamma( method, stream, n, r, alpha, a, beta );
  if (ierr) str_err_code = vslNewStream(&uistream, VSL_BRNG_ARS5, uiseed);
  printf("error status for rand str generation: %d\n", str_err_code);
  // create distribution function
  fun_err_code = vdRngUniform( VSL_RNG_METHOD_UNIFORM_STD, uistream, uin, uiv, ui_init, ui_final );
  if (ierr) printf("error status for rand distr function generation: %d\n", fun_err_code);

  str_err_code = vslDeleteStream(&uistream); 
  if (ierr) printf("error status for rand str deletion: %d\n", str_err_code);
  
  return 0;
  
}
