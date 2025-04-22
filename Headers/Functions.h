#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

/// [LNG 2023-06-11] - Defines arrow keys:

#define Color_Red 12
#define Color_Def 15
#define Color_Yellow 14
#define Color_Green 10
#define Delay_us 0
#define Cursor 16
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESC 27
#define Max_Chars 12

#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

COORD coord = {0, 0};
char KEY_PAD;

struct Article_Struct *Pointer_Articles[100];

void gotoxy(int x, int y);
void Show_Title(void);
void Show_Options();
void Show_Menu();
void Highlight_Option(int Cursor_Pos);
void Clear_Highlight(int Prev_Cursor_Pos);
int Handle_Input(int &Cursor_Pos, int &Prev_Cursor_Pos, int Max_Cursor_Pos);
int Wait_Option(void);
void activation_Via_KMS(string key, string comand_kms, string ato);
int getActivationServerOption(void);

int Counter_Articles = 0;
char File_Name[Max_Chars];
float Total_Inventary = 0;

// Moves the cursor to specific coordinates
void gotoxy(int x, int y) {
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Displays the program title
void Show_Title(void) {
    system("cls");

    char Line1[] = {"  ----------------------------------------------------------------------------   "};
    char Line2[] = {" |                          WL_f00k3r SYSTEM V.3.0                             |  "};
    char Line3[] = {" |                                                                            |  "};
    char Line4[] = {" |                      lucasnicolas.greco@gmail.com                          |  "};
    char Line5[] = {" |                                                                            |  "};
    char Line6[] = {"  ----------------------------------------------------------------------------   "};

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);

    gotoxy(0, 2);
    cout << Line1;
    gotoxy(0, 3);
    cout << Line2;
    gotoxy(0, 4);
    cout << Line3;
    gotoxy(0, 5);
    cout << Line4;
    gotoxy(0, 6);
    cout << Line5;
    gotoxy(0, 7);
    cout << Line6;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
}

// Displays the Windows activation options
void Show_Options() {
    gotoxy(5, 14);
    cout << "(1) Windows 10 Home";

    gotoxy(5, 16);
    cout << "(2) Windows 10 Home N";

    gotoxy(5, 18);
    cout << "(3) Windows 10 Home Single Language";

    gotoxy(5, 20);
    cout << "(4) Windows 10 Home Country Specific";

    gotoxy(5, 22);
    cout << "(5) Windows 10 Professional";

    gotoxy(5, 24);
    cout << "(6) Windows 10 Professional N";

    gotoxy(5, 26);
    cout << "(7) Windows 10 Enterprise";

    gotoxy(5, 28);
    cout << "(8) Windows 10 Enterprise N";

    gotoxy(5, 30);
    cout << "(9) Windows 10 Education";

    gotoxy(5, 32);
    cout << "(10) Windows 10 Education N";

    gotoxy(5, 34);
    cout << "(11) Windows 10 Enterprise 2015 LTSB";

    gotoxy(5, 36);
    cout << "(12) Windows 10 Enterprise 2015 LTSB N";

    gotoxy(5, 38);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);
    cout << "(0) EXIT.";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);

    gotoxy(17, 40);
    cout << "Use Key Pad To Select One Or Press ESC To EXIT.";
}

// Displays the full menu
void Show_Menu() {
    Show_Title();
    gotoxy(30, 10);
    cout << "SELECT AN OPTION.";
    Show_Options();
}

// Highlights the current option
void Highlight_Option(int Cursor_Pos) {
    gotoxy(3, Cursor_Pos);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);
    cout << (char)Cursor;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
}

// Clears the highlight from the previous position
void Clear_Highlight(int Prev_Cursor_Pos) {
    gotoxy(3, Prev_Cursor_Pos);
    cout << " ";
}

// Handles arrow navigation and selection
int Handle_Input(int &Cursor_Pos, int &Prev_Cursor_Pos, int Max_Cursor_Pos) {
    if (kbhit()) {
        int KEY_PAD = getch();
        Prev_Cursor_Pos = Cursor_Pos;

        switch (KEY_PAD) {
            case KEY_UP:
                if (Cursor_Pos > 14) Cursor_Pos -= 2;
                break;

            case KEY_DOWN:
                if (Cursor_Pos < Max_Cursor_Pos) Cursor_Pos += 2;
                break;

            case KEY_ENTER:
                return (Cursor_Pos - 14) / 2 + 1;

            case KEY_ESC:
                return 0; // Exit option

            default:
                return -1; // Invalid input
        }

        Clear_Highlight(Prev_Cursor_Pos); // Clear cursor from old position
        Highlight_Option(Cursor_Pos);    // Highlight the new position
    }
    return -1; // No valid input yet
}

// Waits for user to select a Windows activation method
int Wait_Option(void) {
    int Cursor_Pos = 14;
    int Prev_Cursor_Pos = Cursor_Pos;

    system("cls");

    Show_Menu();
    Highlight_Option(Cursor_Pos);

    int option;
    do {
        option = Handle_Input(Cursor_Pos, Prev_Cursor_Pos, 38);
        if (option != -1) {
            return option;
        }
    } while (true);

    return 0; // Exit
}

// Activates Windows via KMS server
void activation_Via_KMS(string key, string comand_kms, string ato) {
    system("cls");
    system(key.c_str());
    cout << key;
    system(comand_kms.c_str());
    cout << comand_kms;
    system(ato.c_str());
    cout << ato;
    cout << "Windows system key successfully activated. Check the system to verify. Press any key to continue.";
    system("pause");

    system("cls");
}

// Waits for user to select an activation server
int getActivationServerOption(void) {
    const char *serverOptions[] = {
        "kms.digiboy.ir",
        "kms.msguides.com"
    };

    int Cursor_Pos = 14;
    int Prev_Cursor_Pos = Cursor_Pos;


    system("cls");
    Show_Title();

    for (int i = 0; i < 2; i++) {
        gotoxy(5, 14 + 2 * i);
        cout << "(" << i + 1 << ") " << serverOptions[i];
    }

    gotoxy(5, 18);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);
    cout << "(3) GO BACK TO THE MAIN MENU";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);

    gotoxy(17, 20);
    cout << "Use Arrow Keys to Select or Press ESC to Exit.";

    Highlight_Option(Cursor_Pos);

    int option;
    do {
        option = Handle_Input(Cursor_Pos, Prev_Cursor_Pos, 18);
        if (option != -1) {
            return option;
        }
    } while (true);

    return 0; // Exit
}

#endif // FUNCTIONS_H_INCLUDED
