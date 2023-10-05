# Example make.inc file for GCC
#
# NOTE: If compiling with GCC 10 or above append F90_OPTS, F77_OPTS and F90_DEBUGOPTS with:
#  -fallow-argument-mismatch
# See here for more details: https://gcc.gnu.org/gcc-10/porting_to.html

# Compiler, flags and preprocessing variables
F90 = x86_64-conda-linux-gnu-gfortran
F90_OPTS = -O3 -march=broadwell -mtune=intel -ffree-line-length-0 -fallow-argument-mismatch -ffree-line-length-0 -fallow-invalid-boz
CPP_ON_OPTS = -cpp -DXS -DISO -DLIBXC
F77 = $(F90)
F77_OPTS = -O3
# Required for compilation of LibXC 
FCCPP = cpp

F90_DEBUGOPTS = -g -O0 -DUSE_ASSERT -fbounds-check -fbacktrace -Wall -Wextra -ffree-line-length-0 -fcheck=all -finit-integer=2147483647 -finit-real=snan \
-frecord-gcc-switches -finit-character=42 -finit-logical=true -ffpe-trap=invalid,zero,overflow -fdump-core -fstack-protector-all -pipe -fallow-invalid-bozright -fallow-invalid-boz
# Unusable debug flags: -pedantic 
F77_DEBUGOPTS = $(F90_DEBUGOPTS) 



# Libaries
# Use native blas/lapack by default
export USE_SYS_LAPACK=true
LIB_LPK = -L/projectnb/smithgrp/nzr/miniforge/envs/excite/lib -lopenblas
LIB_FFT = fftlib.a
LIB_BZINT = libbzint.a
LIBS = $(LIB_LPK) $(LIB_FFT) $(LIB_BZINT)

# SMP and MPI compilers, flags and preprocessing variables
MPIF90 = h5pfc
#MPIF90_OPTS = -DMPI
#MPI_LIBS =

# To use Scalapack, include the preprocessing variable, provide the library path and library name 
MPIF90_OPTS = -DMPI -DSCAL -D_HDF5_
MPI_LIBS = -L/projectnb/smithgrp/nzr/miniforge/envs/excite/lib -lscalapack

SMPF90_OPTS = -fopenmp -DUSEOMP -fallow-argument-mismatch
SMPF77_OPTS = $(SMPF90_OPTS)
SMP_LIBS = 

BUILDMPI = true
BUILDSMP = true
BUILDMPISMP = true

