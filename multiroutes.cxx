#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#include "route.h"

int main (int argc, char **argv) {

	MPI_Init( &argc, &argv);

	int myrank, commsize, source, destination;
	
	MPI_Comm_rank (MPI_COMM_WORLD, &myrank);
	MPI_Comm_size (MPI_COMM_WORLD, &commsize);

	FILE *fp = fopen(argv[1], "r");
  while(fscanf(fp, "%d %d", &source, &destination) > 0)
		if (myrank == source)
		{
			printf ("Route from %d - %d\n", source, destination);
		
			char path[512];
			path[0] = '\0';

			puts(path);			

			getRoute (source, destination, path);
			printf("Path from %d - %d : %s\n", source, destination, path);
	
			fflush(stdout);
		}

	fclose(fp);

	MPI_Finalize();

	return 0;
}
