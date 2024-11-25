#include "mkl.h"


//************************************************************
//*       EVENT-DRIVEN ALGORITHM FUNCTIONS (Intel MKL-based)
//************************************************************
extern int gaussian(int gseed, int gn, double *gv, int ga, int gsigma, int ierr);
extern int gamma_distr(int gmseed, int gmn, double *gmv, double gmalpha, double gma, double gmbeta, int ierr);
extern int heapsort_f( int n_heap, struct collisions *heap );
//extern int heapsort_f( int n_heap, double *heap );
extern int heapsort_i( int n_heap, struct collisions *heap );
extern int unif_f( int useed, int un, double *uv, int u_init, int u_final, int ierr);
extern int unif_i( int uiseed, int uin, double *uiv, int ui_init, int ui_final, int ierr);
extern double tcol(int i, int j );
extern int update_velocities(int i, int j);
extern int update_positions(int npart, double dt);
extern int compute_collisions(void);
