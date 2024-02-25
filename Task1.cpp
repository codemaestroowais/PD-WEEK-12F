#include<iostream>
#include<direct.h>
#include<conio.h>
#include<cctype>
#include<windows.h>
#include<time.h>
void hideCursor();
void hideCursor();
void printmaize();
void printplayer();
void clear();
using namespace std;
string star[27][74]={{"##########################################################################"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"#                                                                        #"},
                     {"##########################################################################"}};
main()
{
    hideCursor();
    system("cls");
    printplayer();
    printmaize();
}
void printmaize()
{
    clear();
    for(int row=0; row<27; row++)
    {
        for(int col=0; col<74; col++)
        {
            cout<<star[row][col];
        }
        cout<<endl;
    }
    
}
void printplayer()
{
    star[21][2]="  __--__   ";
    star[22][2]=" /(o)(o)\\  ";
    star[23][2]="|   \\/   | ";
    star[24][2]=" \\_.____/ ";

}
void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
void clear()
{
    COORD cursorPos;
    cursorPos.X = 0;
    cursorPos.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
}