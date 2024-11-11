/* #########################
##### FUNCION tcol ######
######################### */

#include "params.h"

//  calcula los tiempos de colision p-p. para un par de particulas (i,j)

double tcol(int i, int j ){

  double dx, dy;
  double dvx, dvy, drdv;
  double vct, dist2, raiz, vdt;
  double xicol, yicol, xjcol, yjcol;

  printf("x(%d): %f\n" , i, x[i]);
  printf("vx(%d): %f\n" , i, vx[i]);

  vdt = 1.0;
  /* dx = x[i] - x[j]; */
  /* dy = y[i] - y[j]; */
  /* dvx = vx[i] - vx[j]; */
  /* dvy = vy[i] - vy[j]; */
  /* drdv = dx * dvx + dy * dvy; */
  /* // estructura condicional de colision p-p; condicion de acercamiento */

  /* if (drdv > 0){ */
  /*   vct = INFINITY; */
  /* } */
  /* else{ */
  /*   dist2 = (dx*dx + dy*dy) - 4*R*R; */
  /*   raiz = drdv*drdv - dist2 * (dvx*dvx + dvy*dvy); */
  /*   if (raiz<0) vct = INFINITY; */
  /*   else{ */
  /*     vdt = dist2/(sqrt(raiz)-drdv); */
  /*     // posicion de la colision. si en realidad la colision ocurriria fuera del sistema, descartala */
  /*     xicol = x[i] + vx[i] * vdt; */
  /*     yicol = y[i] + vy[i] * vdt;  */
  /*     xjcol = x[j] + vx[j] * vdt; */
  /*     yjcol = y[j] + vy[j] * vdt; */
  /*     //  estructura condicional de col. fuera del sistema */
  /*     if (fabs(xicol) > LXR) vdt = INFINITY; */
  /*     else if (fabs(xjcol) > LXR) vdt = INFINITY; */
  /*     else if (fabs(yicol) > LYR) vdt = INFINITY; */
  /*     else if (fabs(yjcol) > LYR) vdt = INFINITY; */
  /*   } */
  /* } // end of (occurring) collision procedure */
  
  return vdt;

}

