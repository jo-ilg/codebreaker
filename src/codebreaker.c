#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include"mpi/mpi-layer.h"

void usage(char *argv[]) {
	fprintf(stderr, "Usage: %s -w wordlist -p passlist [-f format] [-m fmt_str]\n", argv[0]);
	fprintf(stderr, "-w wordlist: wordlist for word based attack\n");
	fprintf(stderr, "-p passlist: passlist containing hashes to be cracked\n");
	fprintf(stderr, "-f format: Specify hash-format of passlist regular, linux-crypt (default: regular) \n");
	fprintf(stderr, "-m fmt_str: Specify a format string to mangle the wordlist\n");
}
int main(int argc, char* argv[]) {
	char *wordlist = NULL;
	char *passlist = NULL;
	char *format = NULL;
	char *fmt_str = NULL;
	char c;

	opterr = 0;

	while ((c = getopt (argc, argv, "w:p:f:m:")) != -1) {
		switch (c) {
			case 'w':
				wordlist = optarg;
				break;
			case 'p':
				passlist = optarg;
				break;
			case 'f':
				format = optarg;
				break;
			case 'm':
				fmt_str = optarg;
				break;
			case '?':
				if (optopt == 'w' || optopt == 'p' || optopt == 'f' || optopt == 'm') {
					fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				} else if (isprint (optopt)) {
					fprintf (stderr, "Unknown option `-%c'.\n", optopt);
				} else {
					fprintf (stderr,"Unknown option character `\\x%x'.\n", optopt);
				}
			exit(EXIT_FAILURE);
			break;
			default:
				exit(EXIT_FAILURE);
		}
	}

	if (wordlist == NULL || passlist == NULL) {
		usage(argv);
		exit(EXIT_FAILURE);
	}

	if (format == NULL) {
		format = "regular";
	}

	//MPI TESTER
	mpi_start(argc, argv, wordlist, passlist, format, fmt_str);
	return 0;
}
