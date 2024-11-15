#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

///[LNG 2023-06-11] -Defines arrow keys:

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


COORD coord = {0,0};
char KEY_PAD;

struct Article_Struct *Pointer_Articles[100];

void gotoxy(int x,int y);
void Show_Title (void);
int Wait_Option (void);
int New_Product (void);
int Delete_Product (void);
int Buy_Product (void);
int Sell_Product (void);
int Report_Product (void);
int Get_Elements_Number (void);
void Init_Structure_Elements (int Article);
int Save_File (void);
int Load_File (void);
void Show_Error (char *Pointer_String, int Show_Delay_us);

int Counter_Articles = 0;
char File_Name [Max_Chars];
float Total_Inventary = 0;




/********************************************************************
*  [LNG 2023-06-11]     Function:  gotoxy                           *
* Input Arguments:                                                  *
*- Integers: Coordenates X and Y in screen.                         *
* Output Arguments:                                                 *
* -----------------                                                 *
* This function move the cursor to an specific coordenates.         *
********************************************************************/
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/********************************************************************
*   [LNG 2023-06-11]   Function: Select_Option                      *
*        This function only present de program to the user.         *
********************************************************************/
void Show_Title (void)
{
    int X = 0;
    int Y = 0;

    system("cls");

    char Line1[] = {"  ----------------------------------------------------------------------------   "};
    char Line2[] = {" |                          INVENTORY SYSTEM V.3.0                            |  "};
    char Line3[] = {" |                                                                            |  "};
    char Line4[] = {" |                         grecolucas477@yahoo.com.ar                         |  "};
    char Line5[] = {" |                                                                            |  "};
    char Line6[] = {"  ----------------------------------------------------------------------------   "};


    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);
    gotoxy (X,Y+2);
    for (unsigned int i= 0; i < sizeof(Line1); i++)
    {
        cout << Line1[i];
        Sleep(Delay_us);
    }
    gotoxy (X,Y+3);
    for (unsigned int i= 0; i < sizeof(Line2); i++)
    {
        cout << Line2[i];
        Sleep(Delay_us);
    }
    gotoxy (X,Y+4);
    for (unsigned int i= 0; i < sizeof(Line3); i++)
    {
        cout << Line3[i];
        Sleep(Delay_us);
    }
    gotoxy (X,Y+5);
    for (unsigned int i= 0; i < sizeof(Line4); i++)
    {
        cout << Line4[i];
        Sleep(Delay_us);
    }
    gotoxy (X,Y+6);
    for (unsigned int i= 0; i < sizeof(Line5); i++)
    {
        cout << Line5[i];
        Sleep(Delay_us);
    }
    gotoxy (X,Y+7);
    for (unsigned int i= 0; i < sizeof(Line6); i++)
    {
        cout << Line6[i];
        Sleep(Delay_us);
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
}

/********************************************************************
* [LNG 2023-06-11] - Function:  Wait_Option                         *
* Input Arguments:                                                  *
*                                                                   *
* Output Arguments:                                                 *
*- Integer value related with a option menu.                        *
* This function wait until the user enter a option.                 *
********************************************************************/
// Display the list of options
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
    cout << "(0) EXIT." << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);

    gotoxy(17, 40);
    cout << "Use Key Pad To Select One Or Press ESC To EXIT." << endl;
}

// Display the title and options on the screen
void Show_Menu() {
    gotoxy(30, 10);
    cout << "SELECT AN OPTION.";
    Show_Options();
}


// Highlight the current option
void Highlight_Option(int Cursor_Pos) {
    gotoxy(3, Cursor_Pos);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Green);
    cout << (char)Cursor;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    gotoxy(64, 30);  // Reset cursor to input area
}
// Highlight the current selected option
void Display_Cursor(int Cursor_Pos) {
    Highlight_Option(Cursor_Pos);  // Highlight new position
}

// Clear the cursor from its previous position only
void Clear_Highlight(int Prev_Cursor_Pos) {
    gotoxy(3, Prev_Cursor_Pos); // Move to the previous cursor position
    cout << " ";  // Replace the cursor with a blank space
}



// Handle input and update cursor position or return selected option
int Handle_Input(int &Cursor_Pos, int &Prev_Cursor_Pos) {
    if (kbhit()) {
        int KEY_PAD = getch();
        Prev_Cursor_Pos = Cursor_Pos;  // Store the previous position

        switch (KEY_PAD) {
            case KEY_UP:
                if (Cursor_Pos >= 16) Cursor_Pos -= 2;
                break;

            case KEY_DOWN:
                if (Cursor_Pos <= 36) Cursor_Pos += 2;
                break;

            case KEY_ENTER:
                return (Cursor_Pos - 14) / 2 + 1;

            case KEY_ESC:
                return 8;

            default:
                return -1;  // No action needed for other keys
        }

        Clear_Highlight(Prev_Cursor_Pos);  // Clear cursor from the old position
        Display_Cursor(Cursor_Pos);  // Move to the new position
    }

    return -1;  // No valid input yet
}
int Wait_Option(void) {
    int Cursor_Pos = 14;
    int Prev_Cursor_Pos = Cursor_Pos; // Track the previous position

    system("cls");
    Show_Title();
    Show_Menu();
    Display_Cursor(Cursor_Pos);

    int option;
    do {
        option = Handle_Input(Cursor_Pos, Prev_Cursor_Pos);
        if (option != -1) {
            return option;
        }
    } while (true);

    return 8; // In case the loop exits (although it should return earlier)
}

/********************************************************************
* [LNG 2023-06-11] -  Function:  New_Product                        *
* Input Arguments:                                                  *
*                                                                   *
* Output Arguments:                                                 *
*- Integer value only for indicate that the function is over.       *
* This function adds products to the inventory.                     *
********************************************************************/

void activation_Via_KMS(string key, string comand_kms, string ato)
{
    system("cls");
    system(key.c_str());
    cout<<key;
    system(comand_kms.c_str());
    cout<<comand_kms;
    system(ato.c_str());
    cout<<ato;
    cout<<"windows system key succesfully activated, check out system for veryfying.Press any key to continue";
    system("pause");

    system("cls");
}

int getActivationServerOption() {
    int activation_Server_Option;
    system("cls");
    cout << "Please select an activation server: " << endl;
    cout << "----------------------------------------" << endl;
    cout << "1) kms.digiboy.ir" << endl;
    cout << "2) kms.msguides.com" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Option: ";
    cin >> activation_Server_Option;
    return activation_Server_Option;
    system("cls");
}



#endif // FUNCTIONS_H_INCLUDED
