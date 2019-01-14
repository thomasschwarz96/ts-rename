// ----------------------------------------------------------------------
//  _____ _                      ___     _                       ___  __
// |_   _| |_  ___ _ __  __ _ __/ __| __| |___ __ ____ _ _ _ ___/ _ \/ /
//   | | | ' \/ _ \ '  \/ _` (_-<__ \/ _| ' \ V  V / _` | '_|_ /\_, / _ \
//   |_| |_||_\___/_|_|_\__,_/__/___/\__|_||_\_/\_/\__,_|_| /__| /_/\___/
// ----------------------------------------------------------------------

#include <stdio.h>
#include <unistd.h>
#include "helpers.h"

// Main program.
int main (int argc, char* argv[])
{
	
	int option;

	while((option = getopt(argc, argv, "hv :n:r:" )) != -1) {

		switch(option) {
			case 'n':
				puts("needle");
				printf("%s \n", optarg);
				break;

			case 'r':
				puts("replace");
				printf("%s \n", optarg);	
				break;

			case 'v':
				version();
				break;

			case 'h':
			case '?':
				info();
				break; 

			default:
				break;
		}
	}

	return 0;
}

