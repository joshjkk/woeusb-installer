#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "../include/installer.h"

#define ENTER_K 10

// Used to centre text on the X axis
short int get_centre(WINDOW *win, char *str) { return ((win->_maxx / 2) - (strlen(str) / 2)); }

// Show the main menu
void main_menu(WINDOW *win)
{
    wclear(win);

    // 2 Lines above the centre
    short int title_y_pos = (win->_maxy / 2) - 2;

    // Print the title
    char *title = (char*)calloc(32, sizeof(char));
    snprintf(title, 32, "WoeUSB Installer v%s", VERSION);

    // Instructions
    char instructions1[] = "Use Arrow Keys to highlight an entry";
    char instructions2[] = "Use Enter to select the highlighted entry";

    // Print watermark at the bottom of the screen
    char watermark[] = "joshjkk @ github";

    // List each option as a button
    char const *options[] = { "Install Required Dependencies (recommended)", "Install All Dependencies", "Exit" };
    int const option_count = 3;

    // 2 Lines below the centre
    short int top_button_y_pos = (win->_maxy / 2) + 2;
    int highlight = 0;

    // Loop options
    bool choosing = true;
    while (choosing)
    {
        // Print title in cool text
        wattron(win, A_BOLD);
        wattron(win, A_UNDERLINE);
        mvwprintw(win, title_y_pos, get_centre(win, title), "%s", title);
        wattroff(win, A_BOLD);
        wattroff(win, A_UNDERLINE);

        // Print instructions in dim
        wattron(win, A_DIM);
        mvwprintw(win, (win->_maxy - 6), get_centre(win, instructions1), "%s", instructions1);
        mvwprintw(win, (win->_maxy - 5), get_centre(win, instructions2), "%s", instructions2);

        // Print watermark at bottom of screen dim
        mvwprintw(win, (win->_maxy - 1), get_centre(win, watermark), "%s", watermark);
        wattroff(win, A_DIM);

        // Hightlight buttons
        for (int i = 0; i < option_count; i++)
        {
            if (i == highlight)
                wattron(win, A_STANDOUT);

            // Print buttons as a list
            mvwprintw(win, top_button_y_pos+i, get_centre(win, (char*)options[i]), "%s", options[i]);
            wattroff(win, A_STANDOUT);
        }

        // Draw to the screen
        wrefresh(win);

        // Wait for keyboard input
        int key = wgetch(win);

        switch (key)
        {
            // Up arrow
            case KEY_UP:
                // Only go up if not on the top buttom
                if (highlight != 0)
                    highlight--;
                break;

            // Down arrow
            case KEY_DOWN:
                // Only go down if not on the bottom button
                if (highlight != (option_count-1))
                    highlight++;
                break;

            // Enter key
            case ENTER_K:
                switch (highlight)
                {
                    // Install required deps
                    case 0:
                        install_deps(win, false);
                        break;

                    // Install all deps
                    case 1:
                        install_deps(win, true);
                        break;

                    // Exit
                    case 2:
                        return;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }
}

void install_deps(WINDOW *win, bool all_deps)
{
    wclear(win);
    wrefresh(win);

    // All dependencies
    if (all_deps)
        system("sudo ./install_deps.sh");

    // Required dependencies
    else
        system("sudo ./install_deps.sh -r");

    wclear(win);

    wprintw(win, "\nInstallation finished, press any key to return to the main menu\n");

    wrefresh(win);
    wgetch(win);
    wclear(win);
}

void show_version()
{
    printf("WoeUSB Installer v%s\n", VERSION);
}

void show_help(const char *program)
{
    printf(
            "BUILDING\n"
            "\tbuild exe: sudo make woeusb_installer\n"
            "\tclean: sudo make clean\n"
            "\nUSAGE\n"
            "\tsudo %s [args]\n"
            "\n\twhere [ ] indicates optional arguments\n"
            "\nARGS"
            "\n\t--version, -v = show the current install version of WoeUSB Installer"
            "\n\t--help, -h = show the help menu\n"
            "\nSOURCE CODE"
            "\n\thttps://github.com/joshjkk/woeusb-installer\n", program
    );
}
