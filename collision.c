/* #########################
##### FUNCION tcol ######
######################### */

#include "params.h"
#include "protos.h"

//  calcula los tiempos de colision p-p. para un par de particulas (i,j)

double tcol(int i, int j ){

  double dx, dy;
  double dvx, dvy, drdv;
  double dist2, raiz, vct, denom;
  double xicol, yicol, xjcol, yjcol;

  dx = x[i] - x[j];
  dy = y[i] - y[j];
  dvx = vx[i] - vx[j];
  dvy = vy[i] - vy[j];
  drdv = dx * dvx + dy * dvy;
  // estructura condicional de colision p-p; condicion de acercamiento

  if (drdv > 0){
    vct = INFINITY;
  }
  else{
    dist2 = (dx*dx + dy*dy) - 4*R*R;
    raiz = drdv*drdv - dist2 * (dvx*dvx + dvy*dvy);
    denom = sqrt(raiz)-drdv;
    if (raiz<0 || denom <0 || dist2 <0) vct = INFINITY;
    else{
      vct = dist2/denom;
      // posicion de la colision. si en realidad la colision ocurriria fuera
      // del sistema, descartala
      xicol = x[i] + vx[i] * vct;
      yicol = y[i] + vy[i] * vct;
      xjcol = x[j] + vx[j] * vct;
      yjcol = y[j] + vy[j] * vct;
      //  estructura condicional de col. fuera del sistema
      if (fabs(xicol) > LXR)
	vct = INFINITY;
      else if (fabs(xjcol) > LXR)
	vct = INFINITY;
      else if (fabs(yicol) > LYR)
	vct = INFINITY;
      else if (fabs(yjcol) > LYR)
	vct = INFINITY;
    } 
  } // end of (occurring) collision procedure

  return vct;

}

