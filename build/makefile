### Nombre del compilador
CC=icx

# librerias para el enlazador
#mkl version 2011
LPMKL=/opt/intel/oneapi/mkl/lastest/lib/intel64

## includes para el compilador
IMKL=/opt/intel/oneapi/mkl/latest/include # version 2023

### Opciones del compilador
CFLAGS=-c -g -O3  -DMKL_ILP64 -fcolor-diagnostics

#para mkl 11.1, estatico, enteros de 32 bits
#LDFLAGS=-static -L$(LPMKL) -I$(IMKL) -Wl,--start-group $(LPMKL)/libmkl_intel_lp64.a $(LPMKL)/libmkl_intel_thread.a $(LPMKL)/libmkl_core.a -Wl,--end-group -openmp -lpthread

#linkado dinamico, version en paralelo (thread). enteros de 64 bits
#LDFLAGS=-L$(LPMKL) -I$(IMKL)-lmkl_intel_ilp64 -lmkl_intel_thread -lmkl_core -liomp5 -lpthread -lm 
#LDFLAGS=-L$(LPMKL) -I$(IMKL) -lmkl_intel_lp64 -lmkl_core -lmkl_sequential -lpthread -ldl

LDFLAGS=-L${MKLROOT}/lib/intel64 -lmkl_intel_ilp64 -lmkl_sequential -lmkl_core -lpthread -lm -ldl
### Objetos a compilar
OBJS= main.o gaussian.o gamma_distr.o unif_f.o heapsort_f.o collision.o update.o
##SCRS=

CHIRAL: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o CHIRAL
#	$(CC) -o CHIRAL -static $(OBJS)

main.o: ../main.c ../params.h ../protos.h 
	$(CC) $(CFLAGS) -I"${MKLROOT}/include" ../main.c

gaussian.o: ../gaussian.c ../params.h ../protos.h 
	$(CC) $(CFLAGS) -I"${MKLROOT}/include" ../gaussian.c 

gamma_distr.o: ../gamma_distr.c ../params.h ../protos.h 
	$(CC) $(CFLAGS) -I"${MKLROOT}/include" ../gamma_distr.c

unif_f.o: ../unif_f.c ../params.h ../protos.h 
	$(CC) $(CFLAGS) -I"${MKLROOT}/include" ../unif_f.c

heapsort_f.o: ../heapsort_f.c ../params.h ../protos.h 
	$(CC) $(CFLAGS) -I"${MKLROOT}/include" ../heapsort_f.c

collision.o: ../collision.c ../params.h ../protos.h 
	$(CC) $(CFLAGS) -I"${MKLROOT}/include" ../collision.c
update.o: ../update.c ../params.h ../protos.h
	$(CC) $(CFLAGS) -I"${MKLROOT}/include" ../update.c
	 
all: CHIRAL $(OBJS)

.PHONY: clean
clean: 
	rm CHIRAL $(OBJS)
