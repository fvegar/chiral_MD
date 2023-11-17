#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//#include "mkl.h" // uncomment if INTEL MKL installed;

/******************************************************************/
// USAGE: ./a.out number1 number2 number3
// number1: how many numbers to sort
// number2: range of values of those figures
// number3: seed of the random generator
/******************************************************************/



/******************************************************************/
// DEMOTE FUNCTION, for promoting greater sibblings in the heap * */
/******************************************************************/
void demote(double darr[], int i, int r ){

  int i_sibling, i_keep;
  double darr_keep;

  
  darr_keep = darr[i];
  i_keep = i;
  i_sibling = 2 *i + 1;
    
  while(i_sibling <= r){
    if (i_sibling < r && darr[i_sibling] < darr[i_sibling+1]) i_sibling++; // compare only to the greater sibling
    if (darr_keep >= darr[i_sibling]) break ; // if it's already the boss: stop at this level & continue
    darr[i_keep] = darr[i_sibling]; // if it's not, promote its better sibling
    i_keep = i_sibling; // continue testing if it's now in its level
    i_sibling = 2 * i_sibling + 1; // next level is always 2*j+1
  }     
  
  darr[i_keep] = darr_keep; // demote element
} 

/* **************  SERVICE INLINE FUNCTIONS ************* */
// **** iSWAP(int address, int address) **** swap two elements in an array (of integers)

static inline void iSWAP(double *a, double *b) {
  double T=*a;*a=*b;*b=T;
}

/* **** report() **** print on screen the array in its current state */
static inline void report(double darr[], int n){
  int j;
  for (j=0; j< n; j++) printf("%g\n", darr[j]); printf("\n\n\n");// print result
}

/* ****** init_random_numbers() **** create array of integer random numbers to order  */ 
void init_random_numbers(double darr[], int n, int SEED){
  int j;
  srand48(SEED); // integer random seed according to time (so that in every run the random squence changes)
  //initstate((unsigned int)(SEED), randstate, 128); // same but for random base function
  for (j=0;j<n;j++) darr[j] = drand48(); // save test array as collision list
}


/***************************************************/
/* ****************  MAIN PROGRAM  *************** */
/***************************************************/

int hash_heapsort_f(int n_heap, double *heap ){

  /* ********* VARIABLES DEFINITIONS ********************************************************/
  int i; // iteration variable

  void iSWAP(double *a, double *b);
  void report(double darrr[], int nn);
  
  /* **** PROGRAM START ********************************************************************/

  //report(heap, n_heap);
  
  /* CREATE HEAP STRUCTURE by 'demoting' */
  for (i=n_heap/2-1; i>=0 ;i--) demote(heap, i, n_heap-1);
  // demoting works by comparison of heap element with it(s) sibling(s)
  // NOTE: the last element with siblings is always n/2-1; n being the array (future heap) size


  /* ORDER HEAP COMPLETELY by promoting final elements sequentially and then demoting them */
  for (i=n_heap-1; i>0; i--){
    iSWAP(&heap[0], &heap[i]); // first swap, putting at the end of array the element on top
    demote(heap, 0, i-1);
  }
  report(heap, n_heap);

  printf("\nended heap program\n\n\a");
  return 0;
  
}

// NOTE: 'demoting' is defined as the opposite of promoting
