#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <curses.h>
using namespace std;

/*void sigWinch ( int signo )
{
    winsize size;
    ioctl( fileno( stdout ), TIOCGWINTSZ, ( char * ) & size );
    resizeterm( size.ws_row, size.ws_col );
}*/

int main()
{
    initscr();//переводит консоль в нужный режим
    // signal ( SIGWINCH, sigWinch );
    if(has_colors() == FALSE)
    {
        endwin();
        return 1;
    }
    cbreak();
    noecho();// если будем писать текст, то он не отображается
    curs_set(0);//курсор не видим, число отличное от нуля делает его видимым
    attron( A_BOLD );//включаем жирный шрифт
    move(5, 15);//перемещаемся в точку
    printw( "Hello, world!\n " );//печатаем
    attroff(A_BOLD);// выключаем жирный щрифт
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(1));// включаем мерцание
    move(7,26);//перемещаемся в точку
    printw("Press any key ...");//вводим клавишу
    refresh();//обновить экран
    getch();//возвращает клавишу, которую набрали
    endwin();//закончили
    return 0;
}
