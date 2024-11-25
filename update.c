#include "params.h"

int update_velocities(int i, int j){

  double dx, dy, sigma_norma, sigmax, sigmay, gsigma;
  
  dx=x[i]-x[j];
  dy=y[i]-y[j];
    
  // construye sigma_ij unitario
  sigma_norma = sqrt(dx * dx + dy * dy);
  sigmax = dx/sigma_norma;
  sigmay = dy/sigma_norma;
    
  // construye g \cdot sigma (g, vel relativa)
  gsigma = (vx[i] - vx[j]) * sigmax + (vy[i] - vy[j]) * sigmay;
    
  //# actualiza vel. de 1a. part.
  vx[i] -= 0.5 * (1 + alpha) * gsigma * sigmax;
  vy[i] -= 0.5 * (1 + alpha) * gsigma * sigmay;
    
  // actualiza vel. de 2a. part.
  vx[j] += 0.5 * (1 + alpha) * gsigma * sigmax;
  vy[j] += 0.5 * (1 + alpha) * gsigma * sigmay;

  return 0;
  
}


int update_positions(int npart, double dt){
  int i;
  for (i = 0; i < npart; i++){
    x[i] += vx[i] * dt;
    y[i] += vy[i] * dt;
  }
  return 0;
}

int compute_collisions(struct collisions *collision_list, int i, int j, dt ){

  int l,k;
  double cdt;
  struct collisions *collision_list_copy;
  collision_list_copy = (struct collisions*)mkl_malloc(Npairs * sizeof(struct collisions), 64);

  // discard non-valid collisions & update collision list
  l = 0;
  for (k = 1; k < Ncol; k++){
    if (collision_list[k].p1 != i && collision_list[k].p2 != j){
      collision_list_copy[l] = collision_list[k];
      collision_list_copy[l].ct += dt;
      l++;
    }
    else{
      cdt = tcol(collision_list[k].p1, collision_list[k].p2);
      if (cdt < INFINITY){
	collision_list_copy[l] = collision_list[k];
	collision_list_copy[l].ct = cdt;
	l++;
      }
    }
    Ncol = l;
  }

  collision_list = (struct collisions*)mkl_realloc( collision_list, sizeof(Npairs * sizeof(struct collisions)), 64);
  

  return 0;
}
