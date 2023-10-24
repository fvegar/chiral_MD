#include <stdio.h>
#include "mkl_vsl.h"
#include "mkl_vml.h" 
#include "mkl.h" 
#include "params.h"

//int gaussian( int gseed, int gn);

int main( int argc,  char *argv[] ){
  // distr gaussiana

  gaussian( atoi(argv[1]), atoi(argv[2]) );

  gamma_distr( atoi(argv[1]), atoi(argv[2]) );
  
  return 0;
  
}
