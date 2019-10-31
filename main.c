// ----------------------------------------------------------------------
//  _____ _                      ___     _                       ___  __
// |_   _| |_  ___ _ __  __ _ __/ __| __| |___ __ ____ _ _ _ ___/ _ \/ /
//   | | | ' \/ _ \ '  \/ _` (_-<__ \/ _| ' \ V  V / _` | '_|_ /\_, / _ \
//   |_| |_||_\___/_|_|_\__,_/__/___/\__|_||_\_/\_/\__,_|_| /__| /_/\___/
// ----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include "helpers.h"


// Main program.
int main(int argc, char *argv[])
{
    // Init variables.
    int option;
    int isRenamed;
    int counter = 0;
    int isNeedle = 0;
    int isReplace = 0;
    char needle[50];
    char replace[50];
    char *oldName;
    char *newName;

    DIR *directory;
    struct dirent *ep;

    while ((option = getopt(argc, argv, "hv :n:r:")) != -1)
    {
        switch (option)
        {
            case 'n':
                // Set bool and copy argument.
                isNeedle = 1;
                strcpy(needle, optarg);
                break;

            case 'r':
                // Set bool and copy argument.
                isReplace = 1;
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

    // Check if we have 'needle' and 'replace'.
    if (isNeedle && isReplace)
    {
        // Read files from current directory.
        directory = opendir("./");

        // Check if folder contain files.
        if (directory != NULL)
        {
            while (ep = readdir(directory))
            {
                // Check if filename contains needle.
                if (strstr(ep->d_name, needle) != NULL)
                {

                    // Allocate storage for oldName.
                    oldName = (char *) malloc(strlen(ep->d_name) * sizeof(char));

                    // Save oldName.
                    strcpy(oldName, ep->d_name);

                    // Create newName with given options.
                    newName = str_replace(needle, replace, ep->d_name);

                    // Rename the file.
                    isRenamed = rename(oldName, newName);

                    // Check if renaming was successful.
                    if (!isRenamed)
                    {
                        printf("File %s renamed to %s.\n", oldName, newName);
                        counter++;
                    }
                }
            }
            (void) closedir(directory);
            printf("%i Files renamed.\n", counter);
        }

    }

    return 0;
}

