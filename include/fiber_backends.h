#ifndef FIBER_BACKENDS_H_
#define FIBER_BACKENDS_H_

#include <mpi.h>

#include "fiber_backend_heffte.h"
#include "fiber_backend_fftmpi.h"
#include "fiber_backend_accfft.h"
#include "fiber_backend_p3dfft.h"
#include "fiber_backend_ffte.h"
#include "fiber_backend_swfft.h"
#include "fiber_backend_decomp2d.h"
#include "fiber_backend_nb3dfft.h"
#include "fiber_backend_fftw.h"
#include "fiber_backend_fftadvmpi.h"
#include "fiber_backend_fftwpp.h"


// Available backends
char backends[][20] = {"heFFTe", "FFTMPI", "AccFFT", "P3DFFT", "FFTE", "SWFFT", "2DECOMP&FFT", "nb3dFFT", "FFTW", "fftadvmpi", "FFTW++"};
int n_backends = 11;

enum backend{heffte, fftmpi, accfft, p3dfft, ffte, swfft, decomp2d, nb3dfft, fftw, fftadvmpi, fftwpp};

// Backends initialization
struct fiber_init
{
    char *name;
    int (*function)( int, int, int, int, int, int );
};

const struct fiber_init fiber_initialize[] = {
    { "heffte",     &init_heffte    },
    { "fftmpi",     &init_fftmpi    },
    { "accfft",     &init_accfft    },
    { "p3dfft",     &init_p3dfft    },
    { "ffte",       &init_ffte      },
    { "swfft",      &init_swfft     },
    { "decomp2d",   &init_decomp2d  },
    { "nb3dfft",    &init_nb3dfft   },
    { "fftw",       &init_fftw      },
    { "fftadvmpi",  &init_fftadvmpi },
    { "fftwpp",     &init_fftwpp }
};

// Backends finalization
struct fiber_finalize
{
    char *name;
    int (*function)( void );
};
//*
const struct fiber_finalize fiber_finalize[] = {
    { "heffte",     &finalize_heffte    },
    { "fftmpi",     &finalize_fftmpi    },
    { "accfft",     &finalize_accfft    },
    { "p3dfft",     &finalize_p3dfft    },
    { "ffte",       &finalize_ffte      },
    { "swfft",      &finalize_swfft     },
    { "decomp2d",   &finalize_decomp2d  },
    { "nb3dfft",    &finalize_nb3dfft   },
    { "fftw",       &finalize_fftw      },
    { "fftadvmpi",  &finalize_fftadvmpi },
    { "fftw",       &finalize_fftwpp }
};//*/

// Real-to-complex transform
struct fiber_map_backend_d2z
{
    char *name;
    void (*function)( int const * , int const *, int const * , int const * , MPI_Comm const , double const *, void *, int *, double *);
};

const struct fiber_map_backend_d2z fiber_execute_d2z[] = {
    { "heffte",     &compute_d2z_heffte    },
    { "fftmpi",     &compute_d2z_fftmpi    },
    { "accfft",     &compute_d2z_accfft    },
    { "p3dfft",     &compute_d2z_p3dfft    },
    { "ffte",       &compute_d2z_ffte      },
    { "swfft",      &compute_d2z_swfft     },
    { "decomp2d",   &compute_d2z_decomp2d  },
    { "nb3dfft",    &compute_d2z_nb3dfft   },
    { "fftw",       &compute_d2z_fftw      },
    { "fftadvmpi",  &compute_d2z_fftadvmpi },
    { "fftwpp",     &compute_d2z_fftwpp }
};


// Complex-to-real transform
struct fiber_map_backend_z2d
{
    char *name;
    void (*function)( int const * , int const *, int const * , int const * , MPI_Comm const , void const *, double *, int *, double *);
};

const struct fiber_map_backend_z2d fiber_execute_z2d[] = {
    { "heffte",     &compute_z2d_heffte    },
    { "fftmpi",     &compute_z2d_fftmpi    },
    { "accfft",     &compute_z2d_accfft    },
    { "p3dfft",     &compute_z2d_p3dfft    },
    { "ffte",       &compute_z2d_ffte      },
    { "swfft",      &compute_z2d_swfft     },
    { "decomp2d",   &compute_z2d_decomp2d  },
    { "nb3dfft",    &compute_z2d_nb3dfft   },
    { "fftw",       &compute_z2d_fftw      },
    { "fftadvmpi",  &compute_z2d_fftadvmpi },
    { "fftwpp",     &compute_z2d_fftwpp }
};


// Complex-to-Complex transform
struct fiber_map_backend_z2z
{
    char *name;
    void (*function)( int const * , int const *, int const * , int const * , MPI_Comm const , void const *, void *, int *, double *);
};

const struct fiber_map_backend_z2z fiber_execute_z2z[] = {
    { "heffte",     &compute_z2z_heffte    },
    { "fftmpi",     &compute_z2z_fftmpi    },
    { "accfft",     &compute_z2z_accfft    },
    { "p3dfft",     &compute_z2z_p3dfft    },
    { "ffte",       &compute_z2z_ffte      },
    { "swfft",      &compute_z2z_swfft     },
    { "decomp2d",   &compute_z2z_decomp2d  },
    { "nb3dfft",    &compute_z2z_nb3dfft   },
    { "fftw",       &compute_z2z_fftw      },
    { "fftadvmpi",  &compute_z2z_fftadvmpi },
    { "fftwpp",     &compute_z2z_fftwpp }
};

#endif  //! FIBER_BACKENDS_H_ 
