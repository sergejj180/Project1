#include <Windows.h>
#include <tchar.h>
#include "Header.h"
#include <stdlib.h>
#pragma warning(disable:4996)



int APIENTRY WinMain( /*_In_*/ HINSTANCE hInstance, /*_In_opt_*/ HINSTANCE hPrevInstance, /*_In_*/ LPSTR lpCmdLine, /*_In_*/ int nCmdShow)
{
	MSG msg;
	WNDCLASS wc;
	HWND hMainWindow;

	memset(&wc, 0, sizeof(wc));

	wc.lpfnWndProc = MainWindowProcedure;
	wc.hInstance = hInstance;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszClassName = ClassName;
	wc.hIcon = LoadIcon(NULL, IDC_ICON);
	wc.hCursor = LoadCursor(NULL, IDC_APPSTARTING);

	RegisterClass(&wc);

	hMainWindow = CreateWindow(ClassName, MainWindowTitle, WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 350, 350, (HWND)NULL, (HMENU)NULL, NULL, NULL);

	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK MainWindowProcedure(HWND hMainWindow, UINT msg, WPARAM wp, LPARAM lp)
{

	switch (msg)
	{
	case WM_COMMAND:
		switch (wp)
		{
		case FILE_MENU_NEW:
			MessageBeep(MB_OK);
		case SET_STATIC_TEXT:
			GetWindowText(hName, Name, MAX_BUFFER);
			GetWindowText(hAge, Age, MAX_BUFFER);

			strcpy(Out, LPSTR(Name));
			strcat(Out, LPSTR(_T(" is ")));
			strcat(Out, LPSTR(Age));
			strcat(Out, LPSTR(_T(" Year old.")));
			SetWindowText(hOut, Out);
			break;

		default:
			break;
		}
		break;

	case WM_CREATE:

		hMainMenu = CreateMenu();
		hFileSubMenu = CreateMenu();
		hPopupFileMenu = CreatePopupMenu();
		hPopupEditMenu = CreateMenu();

		AppendMenu(hMainMenu, MF_POPUP, (UINT_PTR)hPopupFileMenu, FileMenu);
		AppendMenu(hPopupFileMenu, MF_STRING, FILE_MENU_NEW, FileMenuNew);
		AppendMenu(hPopupFileMenu, MF_STRING, FILE_MENU_OPEN, FileMenuOpen);
		AppendMenu(hPopupFileMenu, MF_SEPARATOR, NULL, NULL);
		AppendMenu(hMainMenu, MF_POPUP, (UINT_PTR)hPopupEditMenu, FileMenuEdit);
		AppendMenu(hPopupEditMenu, MF_STRING, SET_STATIC_TEXT, FileMenuSetStaticText);
		SetMenu(hMainWindow, hMainMenu);

		CreateWindow("Static", strName, WS_CHILD | WS_VISIBLE | WS_BORDER, 10, 10, 98, 38, hMainWindow, (HMENU)NULL, NULL, NULL);
		hName = CreateWindow("Edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 110, 10, 98, 38, hMainWindow, (HMENU)NULL, NULL, NULL);
		CreateWindow("Static", strAge, WS_CHILD | WS_VISIBLE | WS_BORDER, 10, 50, 98, 38, hMainWindow, (HMENU)NULL, NULL, NULL);
		hAge = CreateWindow("Edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 110, 50, 98, 38 , hMainWindow, (HMENU)NULL, NULL, NULL);
		hOut = CreateWindow("Edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER, 10, 90, 310, 190, hMainWindow, (HMENU)NULL,NULL,NULL);
		CreateWindow("Button", ButtonName, WS_CHILD | WS_VISIBLE | WS_BORDER, 220, 10, 98, 38, hMainWindow, (HMENU)SET_STATIC_TEXT, NULL, NULL);

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hMainWindow, msg, wp, lp);
		break;
	}
	return 0;
}

