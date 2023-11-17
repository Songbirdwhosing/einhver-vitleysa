#include <stdio.h>
#include <ncurses.h>
#include <string.h>

/*
 * more info with: "help"
 * [d@mn ~]$ _
 */

int 
main(int argc, char *argv[])
{
    char more_info[] = "more info with: \"help\"";
    char      term[] = "[d@mn ~]$ ";

    initscr();

    int row, col;
    getmaxyx(stdscr, row, col);
    int col_center = (col / 2) - (strlen(more_info) / 2);
    int row_center = row / 2 - 1;
    
    move(row_center, col_center);
    printw("%s\n", more_info);
    move(row_center+1, col_center);
    printw("%s", term);
    //getyx(stdscr, row, col);
    refresh();

    char str[256];
    while (strcmp(str, "exit") != 0) {
	getstr(str);
	refresh();
	if (strcmp(str, "help") == 0) {
	    mvprintw(row_center+2, col_center, "all    Show all information\n");
	    move(row_center+1, col_center+10);
	    refresh();
	} else { 
	    mvprintw(row_center+2, col_center, "command not found: %s\n", str); 
	    move(row_center+1, col_center+10);
	    refresh();
	}
    }

    noecho();
    while (getch() != 'q') {}
    endwin(); 


    return 0;
}
