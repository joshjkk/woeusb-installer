#ifndef INSTALLER_H
#define INSTALLER_H

#define VERSION "1.1.0"

#include <stdbool.h>
#include <ncurses.h>

void main_menu(WINDOW *win);

void install_deps(WINDOW *win, bool all_deps);

void show_version();

void show_help(const char *program);

#endif // INSTALLER_H
