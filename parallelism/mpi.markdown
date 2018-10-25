---
title:  Introduction to MPI
layout: main
section: parallelism
---

Some of you are sharing the same machine and some time measurements can be influenced by other users running at the very same moment. It can be necessary to run time measurements multiple times. Offloading tasks for your intelligence to Google and Stackoverflow many times is a very good idea, but not this week. Try not to use it.

Append the following to your `.bashrc` file in your home folder
~~~
# .bashrc
# Source global definitions
if [ -f /etc/bashrc ]; then
        . /etc/bashrc
fi

module load compilers/cuda-10.0
module load compilers/gcc-7.3.0_sl7
export PATH=/usr/lib64/openmpi/bin/:$PATH
export LD_LIBRARY_PATH=/usr/lib64/openmpi/lib:$LD_LIBRARY_PATH
~~~

make sure that `.bashrc` is sourced  at login by appending the following to the `.bash_profile`:
~~~

# .bash_profile
# Get the aliases and functions
if [ -f ~/.bashrc ]; then
        . ~/.bashrc
fi
~~~

Check that your environment is correctly configured to compile and runMPI code by running
~~~
$ mpic++ -v
[...]
gcc version 7.3.0 (GCC)

$ which mpirun
/usr/lib64/openmpi/bin/mpirun
~~~

Create a file `hostfile.txt` with the following data:
~~~
hpc-200-06-06 slots=4
hpc-200-06-07 slots=4
###### Note: you can comment hosts in machinefile
#hpc-200-06-05 slots=4
#hpc-200-06-04 slots=4
#############################################
~~~

To compile your application you will use `mpic++` just like if it was g++ (it actually IS g++).

To execute your application you will use `mpirun`.

If I want to run my application `hello` located in `/home/felice` using 8 processes I will need to run:
~~~
mpirun -np 8 --hostfile hostfile.txt /home/felice/hello
~~~


### Hello World!

~~~
#include <mpi.h>
#include <iostream>
int main(int argc, char** argv) {
  MPI_Init(nullptr, nullptr);
  // Get the number of processes
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  // Get the rank of the process
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  // Get the name of the processor
  char processor_name[MPI_MAX_PROCESSOR_NAME];
  int name_len;
  MPI_Get_processor_name(processor_name, &name_len);
  std::cout << "Hello world from processor " << processor_name << " rank " << rank << " of " << world_size << std::endl;
  MPI_Finalize();
}
~~~



<!--
### Useful links


<a href="http://docs.nvidia.com/cuda/cuda-runtime-api/index.html" target="_blank">http://docs.nvidia.com/cuda/cuda-runtime-api/index.html</a> -->
