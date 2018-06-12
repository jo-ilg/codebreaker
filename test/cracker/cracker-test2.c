
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../src/cracker/cracker.h"



int main (int argc, char *argv[]) {
    char *wlist, *plist;
    int w, h, hash_size;
	FILE *words_fp, *pass_fp;
	vector *words, *pass;
	size_t file_size;
	hash_element *hashes;

     
    if (argc < 3) {
        return EXIT_FAILURE;
    }
    
    wlist = argv[1];
    plist = argv[2];
   
    
   
	words_fp = open_file(wlist, &file_size);
	words = index_file(words_fp, file_size);

	pass_fp = open_file(plist, &file_size);
	pass = index_file(pass_fp, file_size);

    if ((hashes = parse_passfile(pass, &hash_size)) == NULL ) {
        return EXIT_FAILURE;
    }
    

	for (w = 0; w < total_vector(words); w++) { 
		for (h = 0; h < hash_size; h++) {
			if (check_pass (&hashes[h].ctx, get_vector(words, w), hashes[h].salt, hashes[h].hash)) {
				hashes[h].done = 1;
			}
		}
	}

	for (h = 0; h < hash_size; h++) {
		if (!hashes[h].done) {
			return EXIT_FAILURE;
		}
	}
	
	return EXIT_SUCCESS;
}
