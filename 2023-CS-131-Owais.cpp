#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

char firee = 239;
void printmaze();
void moveleft();
void player();
void enemy();
void moverigth();
void hideCursor();
void fire();
void movefire();
void clear();
void directionmove(string &direction);
void enemymove(char object, string direction);
char object = 'H';
string direction = "right";
char maze[15][50] = {{"#########################################"},
                     {"#                                       #"},
                     {"#                                       #"},
                     {"#                                       #"},
                     {"#                                       #"},
                     {"#                                       #"},
                     {"#                                       #"},
                     {"#                                       #"},
                     {"#                                       #"},
                     {"#                                       #"},
                     {"#                                       #"},
                     {"#                                       #"},
                     {"#                                       #"},
                     {"#                                       #"},
                     {"#########################################"}};
main()
{
    hideCursor();
    player();
    enemy();
    system("cls");
    printmaze();
    while (true)
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            moveleft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            moverigth();
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            fire();
        }
        directionmove(direction);
        enemymove(object,direction);
        printmaze();
        movefire();
        Sleep(10);
    }
}
void printmaze()
{
    clear();
    for (int row = 0; row < 15; row++)
    {
        for (int col = 0; col < 42; col++)
        {
            cout << maze[row][col];
        }
        cout << endl;
    }
}
void player()
{
    maze[12][21] = 'O';
}
void enemy()
{
    maze[1][1] = object;
}
void fire()
{
    for (int row = 0; row < 15; row++)
    {
        for (int col = 0; col < 42; col++)
        {
            if (maze[row][col] == 'O' && maze[row - 1][col] == ' ')
            {
                maze[row - 1][col] = firee;
            }
        }
    }
}
void movefire()
{

    for (int row = 0; row < 15; row++)
    {
        for (int col = 0; col < 42; col++)
        {
            if (maze[row][col] == firee && maze[row - 1][col] == ' ')
            {
                maze[row - 1][col] = firee;
                maze[row][col] = ' ';
            }
            else if (maze[row][col] == firee && maze[row - 1][col] != ' ')
            {
                maze[row][col] = ' ';
            }
        }
    }
}
void moveleft()
{
    for (int row = 0; row < 15; row++)
    {
        for (int col = 0; col < 42; col++)
        {
            if (maze[row][col] == 'O' && maze[row][col - 1] == ' ')
            {
                maze[row][col - 1] = 'O';
                maze[row][col] = ' ';
            }
        }
    }
}
void moverigth()
{
    for (int row = 0; row < 15; row++)
    {
        for (int col = 0; col < 42; col++)
        {
            if (maze[row][col] == 'O' && maze[row][col + 1] == ' ')
            {
                maze[row][col + 1] = 'O';
                maze[row][col] = ' ';
                break;
            }
        }
    }
}
void directionmove(string &direction)
{
    for (int row = 0; row < 15; row++)
    {
        for (int col = 0; col < 42; col++)
        {
            if (maze[row][col] == object && maze[row][col + 1] == '#')
            {
                direction = "left";
            }
            else if (maze[row][col] == object && maze[row][col - 1] == '#')
            {
                direction = "right";
            }
        }
    }
}
void enemymove(char object, string direction)
{
    if (direction == "left")
    {
        for (int row = 0; row < 15; row++)
        {
            for (int col = 0; col < 42; col++)
            {
                if (maze[row][col] == object && maze[row][col - 1] != '#')
                {
                    maze[row][col - 1] = object;
                    maze[row][col] = ' ';
                }
            }
        }
    }
    else if (direction == "right")
    {
        for (int row = 0; row < 15; row++)
        {
            for (int col = 0; col < 42; col++)
            {
                if (maze[row][col] == object && maze[row][col + 1] != '#')
                {
                    maze[row][col + 1] = object;
                    maze[row][col] = ' ';
                    break;
                }
            }
        }
    }
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