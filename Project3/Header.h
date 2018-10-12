#include <Windows.h>
#include <tchar.h>

#define FILE_MENU_NEW 1
#define FILE_MENU_OPEN 2
#define FILE_MENU_CLOSE 3
#define FILE_MENU_SAVE 6

#define EDIT_MENU_COPY 4
#define EDIT_MENU_PASTE 5
 
HINSTANCE hInst;
HMENU hMainMenu;
HMENU hPopupMenuFile, hPopupMenuEdit;
HMENU hFileSubMenu;

HWND hToolBar;

const char MainWindowName[] = _T("Window Caption");
const char ClassName[] = _T("MainWindow");
const char FileMenu[] = _T("File");
const char FileMenuNew[] = _T("File_new");
const char FileMenuOpen[] = _T("File_open");
const char FileMenuClose[] = _T("File_close");

const char EditMenu[] = _T("Edit");
const char EditMenuCopy[] = _T("Copy");
const char EditMenuPaste[] = _T("Paste");

LRESULT CALLBACK MainWindowProcedure(HWND hMainWindow, UINT msg, WPARAM wp, LPARAM lp);