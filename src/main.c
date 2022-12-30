#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include "../include/installer.h"

int main(int argc, char **argv)
{
    // Path to exe file
    const char *program = argv[0];

    // An argument was given
    if (argc > 1)
    {
        // Version
        if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0)
        {
            show_version();
            return 0;
        }

        // Help
        else if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
        {
            show_help(program);
            return 0;
        }

        else
        {
            fprintf(stderr, "Error: unknown argument '%s' provided\n", argv[1]);
            printf("Use 'sudo %s -h' to see the help menu\n", program);
            return 1;
        }
    }

    // Initialize screen
    initscr();
    cbreak();
    curs_set(0);

    // Get screen size
    int x = 0;
    int y = 0;
    getmaxyx(stdscr, y, x);

    // Create the window
    WINDOW *win = newwin(y, x, 0, 0);

    // Use arrow keys
    keypad(win, TRUE);

    main_menu(win);
    
    endwin();

    return 0;
}
