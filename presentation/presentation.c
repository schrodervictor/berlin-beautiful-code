#include <ncurses.h>
#include <string.h>

#define LAST_SLIDE 11

typedef struct _WIN_struct {
        WINDOW *win;
        int height, width, starty, startx;
} WIN;

typedef struct _PRES_struct {
        WIN title;
        WIN content;
} PRES;

void setTextFromFile(WINDOW *win, char* filename, int row, int col) {
        char buffer[1024];

        FILE *fp = fopen(filename, "r");

        while (fgets(buffer, sizeof(buffer), fp)) {
                wmove(win, row++, col);
                wprintw(win, "%s", buffer);
        }

        fclose(fp);
}

void setCentralizedTextFromFile(WINDOW *win, char* filename, int row) {
        char buffer[1024];
        int size, rows, cols;

        getmaxyx(win, rows, cols);

        FILE *fp = fopen(filename, "r");

        while (fgets(buffer, sizeof(buffer), fp)) {
                size = strlen(buffer);
                wmove(win, row++, (cols - size)/2);
                wprintw(win, "%s", buffer);
        }

        fclose(fp);
}

void setTitle(PRES *presentation) {
        int rows, cols;

        getmaxyx(stdscr, rows, cols);

        WIN title = {
                .height = 6,
                .width = cols - 4,
                .starty = 1,
                .startx = 2
        };

        title.win = newwin(
                title.height,
                title.width,
                title.starty,
                title.startx
        );

        attron(A_BOLD);
        setCentralizedTextFromFile(title.win, "title.txt", 0);
        attroff(A_BOLD);

        presentation->title = title;
}

void setContent(PRES *presentation, int slide) {
        int rows, cols;
        char filename[12] = {};

        getmaxyx(stdscr, rows, cols);

        WIN content = {
                .height = rows - presentation->title.height - 3,
                .width = cols - 4,
                .starty = presentation->title.height + 1,
                .startx = 2
        };

        content.win = newwin(
                content.height,
                content.width,
                content.starty,
                content.startx
        );

        sprintf(filename, "slide%d.txt", slide);
        setCentralizedTextFromFile(content.win, filename, 2);

        wborder(content.win, '|', '|', '-', '-', '+', '+', '+', '+');

        presentation->content = content;
}

void setSignature() {
        int rows, cols;
        char* sig = "Victor Schroeder - presentation proudly written in C";

        getmaxyx(stdscr, rows, cols);
        move(rows - 2, cols - strlen(sig) - 2);
        printw("%s", sig);
}

void setPagination(int slide) {
        int rows, cols;

        getmaxyx(stdscr, rows, cols);
        move(rows - 2, 2);
        printw("%d/%d", slide, LAST_SLIDE);
}

void drawSlide(int slide) {
        PRES presentation;

        border('|', '|', '-', '-', '+', '+', '+', '+');

        setTitle(&presentation);
        setContent(&presentation, slide);
        setPagination(slide);
        setSignature();

        refresh();
        wrefresh(presentation.title.win);
        wrefresh(presentation.content.win);
}

int main(int argc, char *argv[])
{
        int ch;
        int slide = 0;

        initscr();
        cbreak();
        noecho();
        curs_set(false);
        keypad(stdscr, TRUE);

        drawSlide(slide);

        while (ch = getch()) {
                if (ch == 27) {
                        break;
                }
                if (ch == KEY_RESIZE) {
                        clear();
                        drawSlide(slide);
                }
                if (ch == KEY_LEFT && slide > 0) {
                        clear();
                        drawSlide(--slide);
                }
                if (ch == KEY_RIGHT && slide < LAST_SLIDE) {
                        clear();
                        drawSlide(++slide);
                }
        }

        endwin();
        return 0;
}
