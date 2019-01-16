// ----------------------------------------------------------------------
//  _____ _                      ___     _                       ___  __
// |_   _| |_  ___ _ __  __ _ __/ __| __| |___ __ ____ _ _ _ ___/ _ \/ /
//   | | | ' \/ _ \ '  \/ _` (_-<__ \/ _| ' \ V  V / _` | '_|_ /\_, / _ \
//   |_| |_||_\___/_|_|_\__,_/__/___/\__|_||_\_/\_/\__,_|_| /__| /_/\___/
// ----------------------------------------------------------------------

#ifndef HELPERS_H_
#define HELPERS_H_

// Show's the name in ASCII art.
void showName();

// Show usage infos.
void showUsage();

// Show help informations.
void info();

// Show the current version.
void version();

// Replace 'needle' with 'replace' in the 'haystack'.
char *str_replace(char *needle, char *replace, char *haystack);

#endif

