/*
* ---------------
* SWFFT backend
* ---------------
*/
#ifndef FIBER_BACKEND_SWFFT_H
#define FIBER_BACKEND_SWFFT_H

#include <stdio.h>

#if defined(FIBER_ENABLE_SWFFT)
#include "swfft.h"

//=================== Initialization (if required) ============================
int init_swfft(int physical, int nx, int ny, int nz, int p_row, int p_col){
    return(0);
}

int finalize_swfft(){
    return(0);
}

//=====================  Complex-to-Complex transform =========================

void compute_z2z_swfft( int const inbox_low[3], int const inbox_high[3],
                  int const outbox_low[3], int const outbox_high[3], 
                  MPI_Comm const comm,
                  void const *in, void *out, int *swfft_options, double *timer)
{

    // Plan creation ...
    // void *plan;

    MPI_Barrier(comm);
    timer[0] = -MPI_Wtime();

    // plan create

    MPI_Barrier(comm);
    timer[0] += MPI_Wtime();



    // FFT execution ...
    MPI_Barrier(comm);
    timer[1] = -MPI_Wtime();

    // compute FFT 

    MPI_Barrier(comm);
    timer[1] = +MPI_Wtime();

    // Delete plan ...

    printf("SWFFT: Get Complex-to-Complex using TestDfft.cpp or TestFDfft.f90  \n");
    MPI_Abort(comm, 1);
}

//=====================  Real-to-Complex transform =========================


void compute_d2z_swfft( int const inbox_low[3], int const inbox_high[3],
                  int const outbox_low[3], int const outbox_high[3], 
                  MPI_Comm const comm,
                  double const *in, void *out, int *swfft_options, double *timer)
{
    printf("Real-to-Complex transform is not available for SWFFT. \n");
    MPI_Abort(comm, 1);
    timer[0] = -1;
    timer[1] = -1;
}

//=====================  Complex-to-Real transform =========================

void compute_z2d_swfft( int const inbox_low[3], int const inbox_high[3],
                  int const outbox_low[3], int const outbox_high[3], 
                  MPI_Comm const comm,
                  void const *in, double *out, int *swfft_options, double *timer)
{
    printf("Complex-to-Real transform is not available for SWFFT. \n");
    MPI_Abort(comm, 1);
    timer[0] = -1;
    timer[1] = -1;
}

#else
int init_swfft(int physical, int nx, int ny, int nz, int p_row, int p_col)
{}

int finalize_swfft()
{}

void compute_z2z_swfft( int const inbox_low[3], int const inbox_high[3],
                  int const outbox_low[3], int const outbox_high[3], 
                  MPI_Comm const comm,
                  void const *in, void *out, int *swfft_options, double *timer)
{}

void compute_d2z_swfft( int const inbox_low[3], int const inbox_high[3],
                  int const outbox_low[3], int const outbox_high[3], 
                  MPI_Comm const comm,
                  double const *in, void *out, int *swfft_options, double *timer)
{}

void compute_z2d_swfft( int const inbox_low[3], int const inbox_high[3],
                  int const outbox_low[3], int const outbox_high[3], 
                  MPI_Comm const comm,
                  void const *in, double *out, int *swfft_options, double *timer)
{}

#endif

#endif  //! FIBER_BACKEND_SWFFT_H
