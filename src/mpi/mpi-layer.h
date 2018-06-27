#ifndef MPI_INIT_H_
#define MPI_INIT_H_

int mpi_start (int argc, char* argv[], char *wlist, char *plist, char *hash_format, char *fmt_str);
void node_logic (int rank, int size, char *wlist, char *plist, char *hash_format, char *fmt_str);

#endif
