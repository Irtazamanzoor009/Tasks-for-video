#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
void clearscreen();
void gameover();
void Getch();
void chaseplayer();
void maze();
void start();
bool gamerun = true;
bool gamerun1 = true;
void moveright();
void moveleft();
void moveUp();
void moveDown();
void moveghosthorizontally();
void moveghostvertically();
void gotoxy(int x, int y);
void showpacman(int x, int y);
void clearpacman(int x, int y);
char GetCharAtxy(short int x, short int y);
void printghost(int x, int y);
void clearghost(int x, int y, char previous);
void printscore();
void printlives();
string menu();
string option;
int score = 0;
int lives = 3;

string direction = "right";
string direction2 = "down";
char previouschar = ' ';
char previouschar2 = ' ';
int px = 8;
int py = 3;

int gx1 = 15;
int gy1 = 15;
int gx2 = 38;
int gy2 = 5;
float gx3 = 77;
float gy3 = 22;
main()
{
    clearscreen();
    start();
    string choice;
    gamerun1 = true;
    while (choice != "2")
    {
        choice = menu();
        if (choice == "1") // game start
        {
            clearscreen();
            maze();
            showpacman(px, py);
            printghost(gx1, gy1);
            printghost(gx2, gy2);
            printghost(gx3, gy3);
            printlives();
            printscore();
            // gamerun = true;
            while (true)
            {
                if (GetAsyncKeyState(VK_RIGHT))
                {
                    moveright();
                }
                if (GetAsyncKeyState(VK_LEFT))
                {
                    moveleft();
                }
                if (GetAsyncKeyState(VK_UP))
                {
                    moveUp();
                }
                if (GetAsyncKeyState(VK_DOWN))
                {
                    moveDown();
                }
                moveghosthorizontally();
                moveghostvertically();
                chaseplayer();
                if (lives == 0)
                {
                    char key;
                    clearscreen();
                    lives = 3;
                    score = 0;
                    gameover();
                    cout << "\nPress C to continue..";
                    cin >> key;
                    break;
                }
                Sleep(50);
            }
            if (choice == "2") // Exit
            {
                break;
            }
        }
    }
}
void moveghostvertically()
{
    if (direction2 == "down")
    {
        char nextlocation = GetCharAtxy(gx2, gy2 + 1);
        if (nextlocation == '%' || nextlocation == '|' || nextlocation == '#')
        {
            direction2 = "up";
        }
        else if (nextlocation == ' ' || nextlocation == '.')
        {
            clearghost(gx2, gy2, previouschar2);
            gy2 = gy2 + 1;
            previouschar2 = nextlocation;
            printghost(gx2, gy2);
        }
        else if (nextlocation == 'P')
        {
            clearpacman(px, py);
            score = 0;
            printscore();
            px = 8;
            py = 3;
            // px = px + 1;
            showpacman(px, py);
            lives--;
            printlives();
        }
    }
    if (direction2 == "up")
    {
        char nextlocation = GetCharAtxy(gx2, gy2 - 1);
        if (nextlocation == '%' || nextlocation == '|' || nextlocation == '#')
        {
            direction2 = "down";
        }
        else if (nextlocation == ' ' || nextlocation == '.')
        {
            clearghost(gx2, gy2, previouschar2);
            gy2 = gy2 - 1;
            previouschar2 = nextlocation;
            printghost(gx2, gy2);
        }
        else if (nextlocation == 'P')
        {
            clearpacman(px, py);
            score = 0;
            printscore();
            px = 8;
            py = 3;
            // px = px + 1;
            showpacman(px, py);
            lives--;
            printlives();
        }
    }
}

void chaseplayer()
{
    if (gx3 < px)
    {
        char nextlocation = GetCharAtxy(gx3 + 1, gy3);
        if (nextlocation == ' ' || nextlocation == '.')
        {
            clearghost(gx3, gy3, previouschar2);
            gx3 = gx3 + 0.2;
            previouschar2 = nextlocation;
            printghost(gx3, gy3);
        }
        else if (nextlocation == 'P')
        {
            clearghost(gx3 + 0.2, gy3, previouschar2);
            clearpacman(px, py);
            score = 0;
            printscore();
            px = 8;
            py = 3;
            gx3 = 77;
            gy3 = 22;
            showpacman(px, py);
            lives--;
            printlives();
        }
    }

    if (gx3 > px)
    {
        char nextlocation = GetCharAtxy(gx3 - 1, gy3);
        if (nextlocation == ' ' || nextlocation == '.')
        {
            clearghost(gx3, gy3, previouschar2);
            gx3 = gx3 - 0.2;
            previouschar2 = nextlocation;
            printghost(gx3, gy3);
        }
        else if (nextlocation == 'P')
        {
            clearghost(gx3 - 0.2, gy3, previouschar2);
            clearpacman(px, py);
            score = 0;
            printscore();
            px = 8;
            py = 3;
            gx3 = 77;
            gy3 = 22;
            showpacman(px, py);
            lives--;
            printlives();
        }
    }

    if (gy3 < py)
    {
        char nextlocation = GetCharAtxy(gx3, gy3 + 1);
        if (nextlocation == ' ' || nextlocation == '.')
        {
            clearghost(gx3, gy3, previouschar2);
            gy3 = gy3 + 0.2;
            previouschar2 = nextlocation;
            printghost(gx3, gy3);
        }
        else if (nextlocation == 'P')
        {
            clearghost(gx3, gy3 + 0.2, previouschar2);
            clearpacman(px, py);
            score = 0;
            printscore();
            px = 8;
            py = 3;
            gx3 = 77;
            gy3 = 22;
            showpacman(px, py);
            lives--;
            printlives();
        }
    }

    if (gy3 > py)
    {
        char nextlocation = GetCharAtxy(gx3, gy3 - 1);
        if (nextlocation == ' ' || nextlocation == '.')
        {
            clearghost(gx3, gy3, previouschar2);
            gy3 = gy3 - 0.2;
            previouschar2 = nextlocation;
            printghost(gx3, gy3);
        }
        else if (nextlocation == 'P')
        {
            clearpacman(px, py);
            clearghost(gx3, gy3 - 0.2, previouschar2);
            score = 0;
            printscore();
            px = 8;
            py = 3;
            gx3 = 77;
            gy3 = 22;
            printghost(gx3, gy3);
            showpacman(px, py);
            lives--;
            printlives();
        }
    }
}
void moveghosthorizontally()
{
    if (direction == "right")
    {
        char nextlocation = GetCharAtxy(gx1 + 1, gy1);
        if ((nextlocation == '%' || nextlocation == '|'))
        {
            direction = "left";
        }

        else if (nextlocation == ' ' || nextlocation == '.')
        {
            clearghost(gx1, gy1, previouschar);
            gx1 = gx1 + 1;
            previouschar = nextlocation;
            printghost(gx1, gy1);
        }
        else if (nextlocation == 'P')
        {
            clearpacman(px, py);
            score = 0;
            printscore();
            px = 8;
            py = 3;
            showpacman(px, py);
            lives--;
            printlives();
        }
    }
    if (direction == "left")
    {
        char nextlocation = GetCharAtxy(gx1 - 1, gy1);
        if ((nextlocation == '%' || nextlocation == '|'))
        {
            direction = "right";
        }
        else if (nextlocation == ' ' || nextlocation == '.')
        {
            clearghost(gx1, gy1, previouschar);
            gx1 = gx1 - 1;
            previouschar = nextlocation;
            printghost(gx1, gy1);
        }
        else if (nextlocation == 'P')
        {
            clearpacman(px, py);
            score = 0;
            printscore();
            px = 8;
            py = 3;
            // px = px + 1;
            showpacman(px, py);
            lives--;
            printlives();
        }
    }
}
void moveright()
{
    char nextlocation = GetCharAtxy(px + 1, py);
    if (nextlocation == ' ')
    {
        clearpacman(px, py);
        px = px + 1;
        showpacman(px, py);
    }
    if (nextlocation == '.')
    {
        clearpacman(px, py);
        px = px + 1;
        showpacman(px, py);
        score++;
        printscore();
    }
    if (nextlocation == 'G')
    {
        clearpacman(px, py);
        score = 0;
        printscore();
        px = 8;
        py = 3;
        gx3 = 77;
        gy3 = 22;
        showpacman(px, py);
        lives--;
        printlives();
    }
}

void moveleft()
{
    char nextlocation = GetCharAtxy(px - 1, py);
    if (nextlocation == ' ')
    {
        clearpacman(px, py);
        px = px - 1;
        showpacman(px, py);
    }
    if (nextlocation == '.')
    {
        clearpacman(px, py);
        px = px - 1;
        showpacman(px, py);
        score++;
        printscore();
    }
    if (nextlocation == 'G')
    {
        clearpacman(px, py);
        score = 0;
        printscore();
        px = 8;
        py = 3;
        gx3 = 77;
        gy3 = 22;
        showpacman(px, py);
        lives--;
        printlives();
    }
}

void moveUp()
{
    char nextlocation = GetCharAtxy(px, py - 1);
    if (nextlocation == ' ')
    {
        clearpacman(px, py);
        py = py - 1;
        showpacman(px, py);
    }
    if (nextlocation == '.')
    {
        clearpacman(px, py);
        py = py - 1;
        showpacman(px, py);
        score++;
        printscore();
    }
    if (nextlocation == 'G')
    {
        clearpacman(px, py);
        score = 0;
        printscore();
        px = 8;
        py = 3;
        gx3 = 77;
        gy3 = 22;
        showpacman(px, py);
        lives--;
        printlives();
    }
}

void moveDown()
{
    char nextlocation = GetCharAtxy(px, py + 1);
    if (nextlocation == ' ')
    {
        clearpacman(px, py);
        py = py + 1;
        showpacman(px, py);
    }
    if (nextlocation == '.')
    {
        clearpacman(px, py);
        py = py + 1;
        showpacman(px, py);
        score++;
        printscore();
    }
    if (nextlocation == 'G')
    {
        clearpacman(px, py);
        score = 0;
        printscore();
        px = 8;
        py = 3;
        gx3 = 77;
        gy3 = 22;
        showpacman(px, py);
        lives--;
        printlives();
    }
}
void printscore()
{
    gotoxy(85, 1);
    cout << "Score: " << score;
}
void printlives()
{
    gotoxy(85, 2);
    cout << "Lives: " << lives;
}
string menu()
{
    cout << "--------------------------------" << endl;
    cout << "1.  Start" << endl;
    cout << "2.  Exit" << endl;
    cout << "--------------------------------" << endl;
    cout << "Select your option: ";
    cin >> option;
    return option;
}
void clearscreen()
{
    system("cls");
}
void Getch()
{
    cout << "Press any key to continue...";
    getch();
}
void maze()
{
    cout << " ###############################################################################   " << endl;
    cout << " ||.. ..............................................................   .....  ||   " << endl;
    cout << " ||.. %%%%%%%%%%%%%%%%%          ...          %%%%%%%%%%%%%%%  |%|..    %%%   ||   " << endl;
    cout << " ||..       |%|     |%|       |%|...           |%|        |%|  |%|..    |%|   ||   " << endl;
    cout << " ||..       |%|     |%|       |%|...           |%|        |%|  |%|..    |%|   ||   " << endl;
    cout << " ||..       %%%%%%%%%%%   ..  |%|...           %%%%%%%%%%%%%%     ..    %%%.  ||   " << endl;
    cout << " ||..    G  |%|           ..  |%|...           .............. |%| ..       .  ||   " << endl;
    cout << " ||..       %%%%%%%%%%%   ..  |%|...           %%%%%%%%%%%%   |%| ..    %%%.  ||   " << endl;
    cout << " ||..               |%|.  ..                   |%|......      |%| ..    |%|.  ||   " << endl;
    cout << " ||..     ......... |%|.  ..                   |%|......|%|       ..    |%|.  ||   " << endl;
    cout << " ||..|%|  |%|%%%|%|.|%|. |%|                      ......|%|       ..|%| |%|.  ||   " << endl;
    cout << " ||..|%|  |%|   |%|..    %%%%%%%%%%%%%%%%%%       ......|%|        .|%|.      ||   " << endl;
    cout << " ||..|%|  |%|   |%|..                ...|%|          %%%%%%       . |%|.      ||   " << endl;
    cout << " ||..|%|            .                ...|%|                   |%| ..|%|.      ||   " << endl;
    cout << " ||..|%|  %%%%%%%%%%%%%%             ...|%|%%%%%%%%%%%%%%     |%| ..|%|%%%%   ||   " << endl;
    cout << " ||                                                           |%| ..........  ||   " << endl;
    cout << " ||    ...................................................          ........  ||   " << endl;
    cout << " ||..|%|  |%|  |%|..     %%%%%%%%%%%%%%      ..........|%|    |%| ..|%|.      ||   " << endl;
    cout << " ||..|%|  |%|  |%|..             ...|%|           %%%%%%%%    |%| ..|%|.      ||   " << endl;
    cout << " ||..|%|           .             ...|%|                       |%| ..|%|.      ||   " << endl;
    cout << " ||..|%|  %%%%%%%%%%%%%%%        ...|%|%%%%%%%%%%%%%%%        |%| ..|%|%%%%   ||   " << endl;
    cout << " ||.....................................................      |%| .........   ||   " << endl;
    cout << " ||  ...................................................             ......   ||   " << endl;
    cout << " ###############################################################################   " << endl;
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void showpacman(int x, int y)
{
    gotoxy(x, y);
    cout << "P";
}

void clearpacman(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void printghost(int x, int y)
{
    gotoxy(x, y);
    cout << "G";
}

void clearghost(int x, int y, char previous)
{
    gotoxy(x, y);
    cout << previous;
}

char GetCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void start()
{
    cout << "/$$$$$$$   /$$$$$$   /$$$$$$  /$$      /$$  /$$$$$$  /$$   /$$ " << endl;
    cout << "| $$__  $$ /$$__  $$ /$$__  $$| $$$    /$$$ /$$__  $$| $$$ | $$" << endl;
    cout << "| $$  \\ $$| $$  \\ $$| $$  \\__/| $$$$  /$$$$| $$  \\ $$| $$$$| $$" << endl;
    cout << "| $$$$$$$/| $$$$$$$$| $$      | $$ $$/$$ $$| $$$$$$$$| $$ $$ $$" << endl;
    cout << "| $$____/ | $$__  $$| $$      | $$  $$$| $$| $$__  $$| $$  $$$$" << endl;
    cout << "| $$      | $$  | $$| $$    $$| $$\\  $ | $$| $$  | $$| $$\\  $$$" << endl;
    cout << "| $$      | $$  | $$|  $$$$$$/| $$ \\/  | $$| $$  | $$| $$ \\  $$" << endl;
    cout << "|__/      |__/  |__/ \\______/ |__/     |__/|__/  |__/|__/  \\__/" << endl;
}

void gameover()
{
    cout << "/$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$        /$$$$$$  /$$    /$$ /$$$$$$$$ /$$$$$$$ " << endl;
    cout << " /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/       /$$__  $$| $$   | $$| $$_____/| $$__  $$" << endl;
    cout << "| $$  \\__/| $$  \\ $$| $$$$  /$$$$| $$            | $$  \\ $$| $$   | $$| $$      | $$  \\ $$" << endl;
    cout << "| $$ /$$$$| $$$$$$$$| $$ $$/$$ $$| $$$$$         | $$  | $$|  $$ / $$/| $$$$$   | $$$$$$$/" << endl;
    cout << "| $$|_  $$| $$__  $$| $$  $$$| $$| $$__/         | $$  | $$ \\  $$ $$/ | $$__/   | $$__  $$" << endl;
    cout << "| $$  \\ $$| $$  | $$| $$\\  $ | $$| $$            | $$  | $$  \\  $$$/  | $$      | $$  \\ $$" << endl;
    cout << "|  $$$$$$/| $$  | $$| $$ \\/  | $$| $$$$$$$$      |  $$$$$$/   \\  $/   | $$$$$$$$| $$  | $$" << endl;
    cout << " \\______/ |__/  |__/|__/     |__/|________/       \\______/     \\_/    |________/|__/  |__/" << endl;
}
