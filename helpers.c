// ----------------------------------------------------------------------
//  _____ _                      ___     _                       ___  __
// |_   _| |_  ___ _ __  __ _ __/ __| __| |___ __ ____ _ _ _ ___/ _ \/ /
//   | | | ' \/ _ \ '  \/ _` (_-<__ \/ _| ' \ V  V / _` | '_|_ /\_, / _ \
//   |_| |_||_\___/_|_|_\__,_/__/___/\__|_||_\_/\_/\__,_|_| /__| /_/\___/
// ----------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

// Replace 'needle' with 'replace' in the 'haystack'.
char *str_replace(char *needle, char *replace, char *haystack)
{
	char *tempString, *searchStart;
    	int len=0;

	// Check if 'needle' is in 'haystack'.
	searchStart = strstr(haystack, needle);
	if(searchStart == NULL)
	{
		return haystack;
	}

	// Allocate storage.
	tempString = (char*) malloc(strlen(haystack) * sizeof(char));
	if(tempString == NULL) 
	{
		return NULL;
	}

	// Create temporarily copy.
	strcpy(tempString, haystack);

	// Replace first part.
	len = searchStart - haystack;
	haystack[len] = '\0';

	// Replace second part.
	strcat(haystack, replace);

	// Add third part.
	len += strlen(needle);
	strcat(haystack, (char*)tempString+len);

	// Deallocate storage.
	free(tempString);

	printf("New String: %s \n", haystack);

	return haystack;
}



