#include "Header.h"
#include <Commctrl.h>

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	MSG msg;
	WNDCLASSEX wcmain;
	HWND hMainWindow;

	hInst = hInstance;

	wcmain.cbSize = sizeof(WNDCLASSEX);
	wcmain.lpfnWndProc = MainWindowProcedure;
	wcmain.hInstance = hInstance;
	wcmain.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcmain.lpszClassName = ClassName;
	wcmain.style = CS_VREDRAW | CS_HREDRAW;
	wcmain.cbClsExtra = NULL;
	wcmain.cbWndExtra = NULL;
	wcmain.hIcon = NULL;
	wcmain.hIconSm = NULL;
	wcmain.hCursor = NULL;
	RegisterClassEx(&wcmain);
	
<<<<<<< HEAD
	// подправленно
=======
	// подправленно мной 16.06.2019
>>>>>>> ae504f5... // РїРѕРґРїСЂР°РІР»РµРЅРЅРѕ РјРЅРѕР№ 16.06.2019
	hMainWindow = CreateWindowEx(WS_EX_TOPMOST, ClassName, MainWindowName, WS_OVERLAPPED | WS_VISIBLE | WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, 500, 500, NULL, NULL, hInstance, NULL);
	while(GetMessage(&msg, NULL, NULL, NULL))
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
	case WM_CREATE:
		hMainMenu = CreateMenu();
		hPopupMenuFile = CreatePopupMenu();
		hPopupMenuEdit = CreatePopupMenu();

		AppendMenu(hMainMenu, MF_POPUP, (UINT_PTR)hPopupMenuFile, FileMenu);
		AppendMenu(hPopupMenuFile, MF_STRING, FILE_MENU_NEW, FileMenuNew);
		AppendMenu(hPopupMenuFile, MF_STRING, FILE_MENU_OPEN, FileMenuOpen);
		AppendMenu(hPopupMenuFile, MF_STRING, FILE_MENU_CLOSE, FileMenuClose);

		AppendMenu(hMainMenu, MF_POPUP, (UINT_PTR)hPopupMenuEdit, EditMenu);
		AppendMenu(hPopupMenuEdit, MF_STRING, EDIT_MENU_COPY, EditMenuCopy);
		AppendMenu(hPopupMenuEdit, MF_STRING, EDIT_MENU_PASTE, EditMenuPaste);
		
		SetMenu(hMainWindow, hMainMenu);
		
		TBBUTTON tbb[3];
		TBADDBITMAP tbab;

		ZeroMemory(tbb, sizeof(tbb));
		
		tbab.hInst = HINST_COMMCTRL;
		tbab.nID = IDB_STD_SMALL_COLOR;
		
		tbb[0].iBitmap = STD_FILENEW;
		tbb[0].fsState = TBSTATE_ENABLED;
		tbb[0].fsStyle = TBSTYLE_BUTTON;
		tbb[0].idCommand = FILE_MENU_NEW;

		tbb[1].iBitmap = STD_FILEOPEN;
		tbb[1].fsState = TBSTATE_ENABLED;
		tbb[1].fsStyle = TBSTYLE_BUTTON;
		tbb[1].idCommand = FILE_MENU_OPEN;

		tbb[2].iBitmap = STD_FILESAVE;
		tbb[2].fsState = TBSTATE_ENABLED;
		tbb[2].fsStyle = TBSTYLE_BUTTON;
		tbb[2].idCommand = FILE_MENU_SAVE;

		hToolBar = CreateWindowEx(WS_EX_TOOLWINDOW, TOOLBARCLASSNAME, NULL, WS_CHILD | WS_SYSMENU | WS_THICKFRAME | WS_CAPTION | WS_VISIBLE, 0, 0, 0, 0, hMainWindow, (HMENU)NULL, hInst, (LPVOID)sizeof(TBBUTTON));
		
		SendMessage(hToolBar, TB_ADDBUTTONS, sizeof(tbb) / sizeof(TBBUTTON), (LPARAM) &tbb);
		SendMessage(hToolBar, TB_ADDBITMAP, 3, (LPARAM)& tbab);
		
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hMainWindow, msg, wp, lp);
		break;
	}
}
