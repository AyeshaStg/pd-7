#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int, int);
void printmaze();
void printplayer();
void eraseplayer();
void printenemy();
void eraseenemy();
void moveenemy();
void moveplayerleft();
void moveplayerright();
void moveplayerup();
void moveplayerdown();

int ex = 40, ey = 24; 
int Px = 1, Py = 1;  
int mazeWidth = 50;
int mazeHeight = 28;

int main() {
    system("cls");
    printmaze();
    printenemy();
    printplayer();
    
    while (true) {

        if (GetAsyncKeyState(VK_LEFT)) {
            moveplayerleft();
            Sleep(50); 
        }

        // Check for right key press
        if (GetAsyncKeyState(VK_RIGHT)) {
            moveplayerright();
            Sleep(50);
        }

        
        if (GetAsyncKeyState(VK_UP)) {
            moveplayerup();
            Sleep(50);
        }

        
        if (GetAsyncKeyState(VK_DOWN)) {
            moveplayerdown();
            Sleep(50);
        }

        
        moveenemy();
        Sleep(100);
    }

    return 0;
}

void printmaze() {
    cout << "###################################################" << endl;
    cout << "##                                               ##" << endl;
    cout << "##                                               ##" << endl;
    cout << "##                                               ##" << endl;
    cout << "##                                               ##" << endl;
    cout << "##                                               ##" << endl;
    cout << "##         ##############################        ##" << endl;
    cout << "##         #                            #        ##" << endl;
    cout << "##         # ############################        ##" << endl;
    cout << "##         # #                                   ##" << endl;
    cout << "##         # #                                   ##" << endl;
    cout << "##         # #                                   ##" << endl;
    cout << "##         # #             ####                  ##" << endl;
    cout << "##         ###             #  #                  ##" << endl;
    cout << "##                         #  #                  ##" << endl;
    cout << "##                         #  #                  ##" << endl;
    cout << "##                         #  ############       ##" << endl;
    cout << "##                         #             #       ##" << endl;
    cout << "####################       ############# #       ##" << endl;
    cout << "##                                     # #       ##" << endl;
    cout << "##                                     # #       ##" << endl;
    cout << "##                                     # #       ##" << endl;
    cout << "##                                     # #       ##" << endl;
    cout << "##       ##################            ###       ##" << endl;
    cout << "##                                               ##" << endl;
    cout << "##                                               ##" << endl;
    cout << "##                                               ##" << endl;
    cout << "###################################################" << endl;
}

void printplayer() {
    gotoxy(Px, Py);
    cout << "       _____     ";
    gotoxy(Px, Py + 1);
    cout << "      |     |    ";
    gotoxy(Px, Py + 2);
    cout << "      |_____|    ";
}

void eraseplayer() {
    gotoxy(Px, Py);
    cout << "                 ";
    gotoxy(Px, Py + 1);
    cout << "                 ";
    gotoxy(Px, Py + 2);
    cout << "                 ";
}

void moveplayerleft() {
    if (Px > 1) {
        eraseplayer();
        Px--;
        printplayer();
    }
}

void moveplayerright() {
    if (Px < mazeWidth - 10) {
        eraseplayer();
        Px++;
        printplayer();
    }
}

void moveplayerup() {
    if (Py > 1) {
        eraseplayer();
        Py--;
        printplayer();
    }
}

void moveplayerdown() {
    if (Py + 2 < mazeHeight - 1) {
        eraseplayer();
        Py++;
        printplayer();
    }
}

void printenemy() {
    gotoxy(ex, ey);
    cout << "      ^ ^         ";
    gotoxy(ex, ey + 1);
    cout << "       -          ";
    gotoxy(ex, ey + 2);
    cout << "      ---         ";
}

void eraseenemy() {
    gotoxy(ex, ey);
    cout << "                   ";
    gotoxy(ex, ey + 1);
    cout << "                   ";
    gotoxy(ex, ey + 2);
    cout << "                   ";
}

void moveenemy() {
    eraseenemy();
    ex--;
    if (ex < 2) {
        ex = mazeWidth - 9;
    }
    printenemy();
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
