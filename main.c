// ----------------------------------------------------------------------
//  _____ _                      ___     _                       ___  __
// |_   _| |_  ___ _ __  __ _ __/ __| __| |___ __ ____ _ _ _ ___/ _ \/ /
//   | | | ' \/ _ \ '  \/ _` (_-<__ \/ _| ' \ V  V / _` | '_|_ /\_, / _ \
//   |_| |_||_\___/_|_|_\__,_/__/___/\__|_||_\_/\_/\__,_|_| /__| /_/\___/
// ----------------------------------------------------------------------

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "helpers.h"

// Main program.
int main (int argc, char* argv[])
{
	// Init variables.	
	int option;
	bool isNeedle = false;
	bool isReplace = false;
	char needle[50];
	char replace[50];

	while((option = getopt(argc, argv, "hv :n:r:" )) != -1) {

		switch(option) {
			case 'n':
				// Set bool and copy argument.
				isNeedle = true;
				strcpy(needle, optarg);	
				break;

			case 'r':
				// Set bool and copy argument.
				isReplace = true;
				strcpy(replace, optarg);
				break;

			case 'v':
				// Show current version.
				version();
				break;

			case 'h':
			case '?':
				// Show informations. 
				info();
				break; 

			default:
				break;
		}
	}

	if (isNeedle && isReplace) {
		puts("Replace something...");
		printf("Needle: %s \n", needle);
		printf("Replace: %s \n", replace);
		// to do: replace needle with replace!
	}	

	return 0;
}

