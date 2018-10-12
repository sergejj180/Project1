#include <Windows.h>
#include <tchar.h>

#define FILE_MENU_NEW 1
#define FILE_MENU_OPEN 2
#define CHANGE_TITLE 3
#define SET_STATIC_TEXT 4

#define MAX_BUFFER 500

HMENU hMainMenu;
HMENU hPopupFileMenu, hPopupEditMenu;
HMENU hFileSubMenu;
HWND hEdit, hStaticText;
HWND ChildWindow;
HINSTANCE hInst;

const char ClassName[] = _T("xcbcvb");
char MainWindowTitle[] = _T("Tite");
const char FileMenu[] = _T("File");
const char FileMenuNew[] = _T("New_File");
const char FileMenuOpen[] = _T("File_Open");
const char FileMenuExit[] = _T("Cols_Programm");
const char FileMenuCols[] = _T("File_Cols");
const char FileMenuEdit[] = _T("Edit");
const char FileMenuSetStaticText[] = _T("Set Static Text");

char Text[] = _T("bcvbxcvbcvb");
char StaticText[] = _T("zzzzzzzzzzzzzz");
char TextBuffer[MAX_BUFFER];

const char Child[] = "xcvxcvbvcb";

LRESULT CALLBACK MainWindowProcedure(HWND hMainWindow, UINT msg, WPARAM wp, LPARAM lp);
LRESULT CALLBACK ChildWindowProcedure(HWND hMainWindow,UINT msg, WPARAM wp, LPARAM lp);
