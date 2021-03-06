#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#include "route.h"

int main (int argc, char **argv) {

	MPI_Init( &argc, &argv);

	int myrank, commsize, source, destination;
	
	MPI_Comm_rank (MPI_COMM_WORLD, &myrank);
	MPI_Comm_size (MPI_COMM_WORLD, &commsize);

	source = atoi(argv[1]);
	destination = atoi(argv[2]);

	if (myrank == source)
	{
		char path[64];
		getRoute (source, destination, path);
		puts(path);
	}

	MPI_Finalize();

	return 0;
}
