// ----------------------------------------------------------------------
//  _____ _                      ___     _                       ___  __
// |_   _| |_  ___ _ __  __ _ __/ __| __| |___ __ ____ _ _ _ ___/ _ \/ /
//   | | | ' \/ _ \ '  \/ _` (_-<__ \/ _| ' \ V  V / _` | '_|_ /\_, / _ \
//   |_| |_||_\___/_|_|_\__,_/__/___/\__|_||_\_/\_/\__,_|_| /__| /_/\___/
// ----------------------------------------------------------------------

#include <stdio.h>
#include "helpers.h"

// Show's the name in ASCII art.
void showName()
{
	printf("-- TS-Rename --\n");
}

// Show usage infos.
void showUsage()
{
	printf("Usage: tsrename [options]\n");
	printf("\t -h \t Display the simple help and exit\n");
	printf("\t -v \t Display the current version and exit\n");
	printf("\n");
	printf("\t -n \t Needle/String what should be replaced\n");
	printf("\t -r \t String for replacing the needle\n");
}

// Show help informations.
void info()
{
	showName();
	showUsage();
}

// Show the current version.
void version()
{
	showName();
	printf("Current Version: 0.0.1-Alpha\n");
}

