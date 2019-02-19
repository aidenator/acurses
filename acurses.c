#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdbool.h>

// ---- Private Globals ----
static struct winsize wsize;

int get_height() {return wsize.ws_row;}
int get_width() {return wsize.ws_col;}

bool init() {
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &wsize);
}

int main() {
    init();

    printf ("Screen height: %d\n", get_height());
    printf ("Screen width:  %d\n", get_width());
}
