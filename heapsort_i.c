#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "params.h"
#include "protos.h"

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
void demote(int arr[], int i, int r ){

  int j, ikeep, arr_demote;

  arr_demote = arr[i];
  ikeep = i;
  j = ikeep*2+1;
    
  while(j <= r){
    if (j < r && arr[j] < arr[j+1]) j++; // compare only to the greater sibling
    if (arr_demote >= arr[j]) break ; // if it's already the boss: stop at this level & continue
    arr[ikeep] = arr[j]; // if it's not, promote its better sibling
    ikeep = j; // continue testing if it's now in its level
    j = 2*j+1; // next level is always 2*j+1
  }     
  
  arr[ikeep] = arr_demote; // demote element
}

/* **************  SERVICE INLINE FUNCTIONS ************* */
// **** iSWAP(int address, int address) **** swap two elements in an array (of integers)

static inline void iSWAP(int *a, int *b) {
  int T=*a;*a=*b;*b=T;
}

/* **** report() **** print on screen the array in its current state */
static inline void report(int arr[], int n){
  int j;
  for (j=0; j< n; j++) printf("%d\n", arr[j]); printf("\n\n\n");// print result
}

/* ****** init_random_numbers() **** create array of integer random numbers to order  */ 
void init_random_numbers(int arr[], int n, int SEED, int range){
  int j;
  srandom(SEED); // integer random seed according to time (so that in every run the random squence changes)
  //initstate((unsigned int)(SEED), randstate, 128); // same but for random base function
  for (j=0;j<n;j++) arr[j] = random()%range; // save test array as collision list
}



/***************************************************/
/* ****************  MAIN PROGRAM  *************** */
/***************************************************/

int main( int n_heap, int *heap  ){

  /* ********* VARIABLES DEFINITIONS ********************************************************/
  int i; // iteration variable

  void iSWAP(int *a, int *b);
  void report(int nn, int arrr[]);
  
  /* **** PROGRAM START ********************************************************************/

  //report(n_heap, heap);

  
  /* CREATE HEAP STRUCTURE by 'demoting' */
  for (i=n_heap/2-1; i>=0 ;i--) demote(heap, i, n_heap-1);
  // demoting works by comparison of heap element with it(s) sibling(s)
  // NOTE: the last element with siblings is always n/2-1; n being the array (future heap) size


  /* ORDER HEAP COMPLETELY by promoting final elements sequentially and then demoting them */
  for (i=n-1; i>0; i--){
    iSWAP(&heap[0], &heap[i]); // first swap, putting at the end of array the element on top
    demote(heap, 0, i-1);
  }

  report(n_heap, heap);

  return 0;
  
}

// NOTE: 'demoting' is defined as the opposite of promoting
