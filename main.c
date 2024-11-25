#include "params.h"
#include "protos.h"
#include "mkl.h"

/* ###############################################
   #######   CHIRAL MD (DISKS) ###################
   ############################################### */ 

// By F. Vega Reyes. 2024. fvega@eaphysics.xyz

// ############# USAGE: ./CHIRAL npart seed ######### where npart is no. of particles (int)
// amd seed is the rand no. gen. seed (prime int)

double *w, *vx, *vy, *x, *y;
//int *hash_ij;
double sigma_norma;

struct collisions *collision_list, *collision_list_copy;

struct Student {
    int id;
    char name[50];
};

int Ncol, Npairs;

int main( int argc,  char *argv[] ){
    
  int i, j, k, l, Ncol, Npairs;
  int npart = atoi(argv[2]);
  int seed = atoi(argv[1]);
  double t, dt, cdt;
  FILE *fptr;


  // Particle variable initialization
  vx = (double*)mkl_malloc(npart*sizeof(double),64);
  vy = (double*)mkl_malloc(npart*sizeof(double),64);

  x = (double*)mkl_malloc(npart*sizeof(double),64);
  y = (double*)mkl_malloc(npart*sizeof(double),64);

  // Collision list initialization
  Npairs = npart*(npart-1)/2;
  collision_list = (struct collisions*)mkl_malloc(Npairs * sizeof(struct collisions), 64);

  // ******************************************
  // Initial position/velocity distributions **
  // ******************************************
  unif_f(seed, npart, x, -LXR, LXR, 0 ); // X positions
  unif_f(seed, npart, y, -LYR, LYR, 0 ); // Y positions

  // Open a file in writing mode
  fptr = fopen("XY0000.dat", "w");
  for (i=0; i < npart; i++){
    fprintf(fptr, "%8.4f\t%8.4f\n", x[i], y[i]); 
  }
  fclose(fptr);
  printf("written results for a uniform (float) distribution:\n\n");

  
  gaussian( seed, npart, vx, 0., 1., 0); // velocities, X coordinate
  gaussian(seed, npart, vy, 0., 1., 0);  // velocities, Y coordinate

  // Open a file in writing mode
  fptr = fopen("VxVy0000.dat", "w");
  for (i=0; i < npart; i++){
    fprintf(fptr, "%8.4f\t%8.4f\n", vx[i], vy[i]); 
  }
  fclose(fptr);
  printf("written results for the Gaussian distribution:\n\n");


  // ******************************************
  // Initial position/velocity distributions **
  // ******************************************

  for (i = 0; i < npart; i++) {
    collision_list[i].ct = i * 1.0;
    printf("col_test.time: %f\n", collision_list[i].ct);
  }
  
  // COMPUTE COLLISION TIMES
  Ncol = 0;
  for(i=0; i < npart-1; i++){
    for(j=i+1; j < npart; j++){
      cdt = tcol(i,j);
      printf("tc: %f\n", cdt);
      if (cdt < INFINITY){
	collision_list[Ncol].ct = cdt;
	collision_list[Ncol].p1 = i;
	collision_list[Ncol].p2 = j;
	Ncol++;
      }
    }
  }
  
  printf("number of colisions: %d\n", Ncol);

  // Open a file in writing mode
  fptr = fopen("lc0000.dat", "w");
  for (i=0; i < Ncol; i++){
    fprintf(fptr, "%d\t%d\t%8.4f\n", collision_list[i].p1, collision_list[i].p2, collision_list[i].ct);
  }
  fclose(fptr);
  printf("written results for the original collision list:\n\n");

  heapsort_f(Ncol, collision_list);

  // Open a file in writing mode
  fptr = fopen("lc0001.dat", "w");
  for (i=0; i < Ncol; i++){
    fprintf(fptr,"%d\t%d\t%8.4f\n", collision_list[i].p1, collision_list[i].p2, collision_list[i].ct);
  }
  fclose(fptr);
  printf("written results for the heaped collision list:\n\n");


  dt = collision_list[0].ct;
  t += dt;
  i = collision_list[0].p1;
  j = collision_list[0].p2;


  update_velocities(i,j);

  update_positions(npart, dt);

  compute_collisions(i,j);
  
  /* printf("results for the hashing:\n\n"); */
      
  /* for (i=0; i< npart; i++){ */
  /*   printf("orig. index %d, hashed index: %d\n", i, hash_ij[i]); */
  /*  } */

  /* mkl_free(x); */

  

  /* printf("results for a gaussian distribution:\n\n"); */
  /* for (i=0; i< npart; i++){ */

  /*   printf("#%d (vx): %6.3f\n", i, vx[i]); */
  
  /* } */

  /* hash_heapsort_f(npart, vx); */

  /* printf("results for the heaped gaussian distribution:\n\n"); */
      
  /* for (i=0; i< npart; i++){ */
  /*   printf("#%d (vx): %6.3f\n", i, vx[i]); */
  /*  } */

  /* /\* mkl_free(vx); *\/ */
  
  /* gamma_distr( seed, npart, vy, 2., 0., 2., 0); */
  
  /* //vy[0] = INFINITY; */
  /* //vy[2] = INFINITY; */
  
  /* printf("results for a gamma distribution:\n\n"); */
  /* for (i=0; i< npart; i++){ */

  /*   printf("#%d (vy): %6.3f\n", i, vy[i]); */
  
  /* } */


  /* hash_heapsort_f(npart, vy); */

  /* printf("results for the heaped gamma distribution:\n\n"); */
      
  /* for (i=0; i< npart; i++){ */
  /*   printf("#%d (vy): %6.3f\n", i, vy[i]); */
  /*  } */

  //tc = tcol(1, 2);

  //printf("collision time: %f\n", tc);
  
  mkl_free(x);
  mkl_free(y);
  mkl_free(vx);
  mkl_free(vy);

  mkl_free(&collision_list);

  //  mkl_free(collision_list.ctimes);
  /* mkl_free(collision_list.p1); */
  /* mkl_free(collision_list.p2); */
  
  return 0;
  
}
