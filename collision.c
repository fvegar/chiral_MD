int wall_collision(){

  double tx, ty;
  
  if (vx[i] < 0) tx = { -(LXR + x[i]) / vx[i], -1 };
  else if (vx[i] >0 ) tx = { (LXR-x[i]) / vx[i], -3 };
  else tx = INFINITY;

  if (vy[i] < 0) ty = { -(LYR + y[i]) / vy[i], -2 };
  else if (vy[i] > 0) ty = { (LYR - y[i]) / vy[i], -4 };
  else ty = INFINITY;
  
  //ltm = sorted( [ltx,lty], key=itemgetter(0) );
  if (tx[0] < ty[0]) {im = tx[1]; vdt = tx[0];}
  else {im = ty[1]; vdt = ty[0];}
  bisect.insort( listacol, [vdt,[i,im]] );
  
  return 0;
  
}

int collision(void){
  

  dx = x[i] - x[j]
    dy = y[i] - y[j]
    dvx = vx[i] - vx[j]
    dvy = vy[i] - vy[j]
    drdv = dx*dvx + dy*dvy
# estructura condicional de colision p-p
# condicion de acercamiento
    if drdv > 0:
  vct = float('inf')
  else:
    dist2 = (dx*dx + dy*dy) - 4*R*R # distancia instantanea entre dos particulas
      raiz=drdv*drdv - dist2 * (dvx*dvx + dvy*dvy) # condicion de solucion real en la condicion de col.
      if raiz < 0:
      vct = float('inf')
# si hay sol. real, guarda en dt el tiempo de col.
      else:
	vdt = dist2/(math.sqrt(raiz)-drdv)
# posicion de la colision. si en realidad la colision ocurriria fuera del sistema, descartala
	  xicol = x[i] + vx[i]*vdt
	  yicol = y[i] + vy[i]*vdt
	  xjcol = x[j] + vx[j]*vdt
	  yjcol = y[j] + vy[j]*vdt
	      
	  return 0;
  
}
