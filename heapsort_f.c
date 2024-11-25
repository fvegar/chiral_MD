#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "params.h"
#include "protos.h"


/******************************************************************/
// darr: array of values to heapify
// ij: boss to potentially demote
// r: range of values over which demote is performed
/******************************************************************/


/******************************************************************/
// DEMOTE FUNCTION, for promoting greater sibblings in the heap * */
/******************************************************************/
int demote(struct collisions *darr, int i, int r){

  int i_sibling, i_keep;
  struct collisions darr_keep;
  
  darr_keep = darr[i];
  i_keep = i; // safe copy value and index of current boss
  i_sibling = 2 * i + 1; // in a heap, siblings are always 2 * i + 1 and 2 * i + 2 
    
  while(i_sibling <= r){
    if (i_sibling < r && darr[i_sibling].ct < darr[i_sibling+1].ct) i_sibling++; // compare only to the greater sibling
    if (darr_keep.ct >= darr[i_sibling].ct) break ; // if it's already the boss: stop at this level & continue
    darr[i_keep] = darr[i_sibling]; // if it's not, promote its better sibling
    i_keep = i_sibling; // continue testing if it's now in its level
    i_sibling = 2 * i_sibling + 1; // next level is always 2 * current level +1
  }
  darr[i_keep] = darr_keep; // demote element, if i_keep was updated (demoted); if not, does nothing

  return 0; // THIS IS THE HASH LINE

} 
/******************************************************************/



/* **************  SERVICE INLINE FUNCTIONS ************* */
// **** iSWAP(int address, int address) **** swap two elements in an array (of integers)

static inline void iSWAP(double *a, double *b) {
  double T=*a;*a=*b;*b=T;
}
static inline void iSWAP_int(int *ia, int *ib) {
  int iT=*ia;*ia=*ib;*ib=iT;
}
/******************************************************************/


/***************************************************/
/* ****************  MAIN PROGRAM  *************** */
/***************************************************/

int heapsort_f(int n_heap, struct collisions *heap ){
  // n_heap: should be npart*npart in the case of MD with npart particles
  
  /* ********* VARIABLES DEFINITIONS ********************************************************/
  int k; // iteration variable
  // i: ij hash index ( j + i*(N-1) ) of potential collision pair,
  // running from 0 to npart*npart for MD with npart particles
  
  //int hash_ij[n_heap];
    
  void iSWAP(double *a, double *b);
  void iSWAP_int(int *ia, int *ib);
  

  /* **** PROGRAM START ********************************************************************/

  /* CREATE HEAP STRUCTURE and bossify among siblings, by left-demoting */
  for (k=n_heap/2-1; k>=0 ;k--)  demote(heap, k, n_heap-1);
  // demoting works by comparison of heap element with it(s) sibling(s)
  // NOTE: the last element with siblings is always n/2-1; n being the array (future heap) size

      
  /* ORDER HEAP COMPLETELY by promoting final elements sequentially, by right-demoting them */
  for (k=n_heap-1; k>0; k--){
    iSWAP(&heap[0].ct, &heap[k].ct); // first swap, putting at the end of array the element on top
    iSWAP_int(&heap[0].p1, &heap[k].p1);
    iSWAP_int(&heap[0].p2, &heap[k].p2);
    demote(heap, 0, k-1);
  }
  
  printf("\nended heap program\n\n\a");
  return 0;
  
}
/******************************************************************/

// NOTE: 'demoting' is defined as the opposite of promoting
