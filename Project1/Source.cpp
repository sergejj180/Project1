#include "Header.h"

int APIENTRY WinMain(/*_In_ */HINSTANCE hInstance, /* _In_opt_ */ HINSTANCE hPrevInstance, /* _In_ */ LPSTR lpCmdLine, /*_In_*/ int nCmdShow)
{
	MSG msg;
	WNDCLASS wcmain;
	HWND hMainWindow;
	hInst = hInstance;
	memset(&wcmain, 0, sizeof(wcmain));

	wcmain.lpfnWndProc = MainWindowProcedure;
	wcmain.hInstance = hInstance;
	wcmain.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcmain.lpszClassName = ClassName;
	wcmain.hIcon = LoadIcon(NULL, IDC_ICON);
	wcmain.hCursor = LoadCursor(NULL, IDC_APPSTARTING);
	RegisterClass(&wcmain);

	hMainWindow = CreateWindow(ClassName, MainWindowTitle, WS_OVERLAPPED | WS_VISIBLE | WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_SYSMENU, 100, 100, 300, 300, (HWND) NULL, (HMENU) NULL, hInstance, NULL);

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
			HWND ChildWindow;
			WNDCLASS wcchild;
			memset(&wcchild, 0, sizeof(wcchild));
			wcchild.lpfnWndProc = ChildWindowProcedure;
			wcchild.hInstance = hInst;
			wcchild.hbrBackground = (HBRUSH)(COLOR_WINDOW)+4;
			wcchild.lpszClassName = Child;
			wcchild.hIcon = NULL;
			wcchild.hCursor = NULL;
			RegisterClass(&wcchild);
			ChildWindow = CreateWindow(Child, (LPSTR) NULL, WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_BORDER | WS_OVERLAPPED, CW_USEDEFAULT, CW_USEDEFAULT, 200, 100, hMainWindow, (HMENU) NULL, hInst, NULL);
			ShowWindow(ChildWindow, SW_SHOW);
			UpdateWindow(ChildWindow);
		case SET_STATIC_TEXT:
			GetWindowText(hEdit, TextBuffer, 8);
			SetWindowText(hMainWindow, TextBuffer);
		default:
			break;
		}
		break;

	case WM_CREATE:

		hMainMenu = CreateMenu();
		hFileSubMenu = CreateMenu();
		hPopupFileMenu = CreatePopupMenu();
		hPopupEditMenu = CreateMenu();

		AppendMenu(hMainMenu, MF_POPUP, (UINT_PTR) hPopupFileMenu, FileMenu);
		AppendMenu(hPopupFileMenu, MF_STRING, FILE_MENU_NEW, FileMenuNew);
		AppendMenu(hPopupFileMenu, MF_STRING, FILE_MENU_OPEN, FileMenuOpen);
		AppendMenu(hPopupFileMenu, MF_SEPARATOR, NULL, NULL);
		AppendMenu(hMainMenu, MF_POPUP, (UINT_PTR) hPopupEditMenu, FileMenuEdit);
		AppendMenu(hPopupEditMenu, MF_STRING, SET_STATIC_TEXT, FileMenuSetStaticText);
		SetMenu(hMainWindow, hMainMenu);

		hStaticText = CreateWindow("Static", StaticText, WS_CHILD | WS_VISIBLE | WS_BORDER, 10, 10, 100, 20, hMainWindow, (HMENU) NULL, NULL, NULL);
		hEdit = CreateWindow("Edit", Text, WS_CHILD | WS_BORDER | WS_VISIBLE, 10, 35, 200, 60, hMainWindow, (HMENU) NULL, NULL, NULL);

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

LRESULT CALLBACK ChildWindowProcedure(HWND hMainWindow, UINT msg, WPARAM wp,LPARAM lp)
{
	switch (msg)
	{
	case WM_DESTROY:
		/* insert code here */
		/* ... */
		break;
	default:
		return DefWindowProc(hMainWindow,msg,wp,lp);
		break;
	}
}
