/*
 *  This file and the code contained within it is (c)2001 Energon Software
 *      please direct any comments/questions to energon@micron.net
 *
 *  Any replications, duplications, uses, copies, etc. of this code must be
 *      accompanied by the original, unedited source for this program.
 *      Any non-compliances with this agreement will be taken under
 *      the extent of all intellectual property copyright laws
 *
 */

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) { return DefWindowProc(hWnd, uMsg, wParam, lParam); }

WINAPI WinMain(HINSTANCE hInstance,
			   HINSTANCE hPrevInstance,
			   LPSTR lpCmdLine,
			   int nShowCmd)
{
	HWND       hWnd;
	WNDCLASSEX wcWindowClassEx;

	wcWindowClassEx.cbSize        = sizeof(WNDCLASSEX);
	wcWindowClassEx.style         = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wcWindowClassEx.lpfnWndProc   = WindowProc;
	wcWindowClassEx.cbClsExtra    = 0;
	wcWindowClassEx.cbWndExtra    = 0;
	wcWindowClassEx.hInstance     = hInstance;
	wcWindowClassEx.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	wcWindowClassEx.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wcWindowClassEx.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcWindowClassEx.lpszMenuName  = NULL;
	wcWindowClassEx.lpszClassName = "ScrStart";
	wcWindowClassEx.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&wcWindowClassEx))
		return 0;

	if(!(hWnd = CreateWindowEx(
		WS_EX_APPWINDOW | WS_EX_WINDOWEDGE,
		"ScrStart", "ScrStart",
		WS_DISABLED | WS_MINIMIZE,
		0, 0, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL,
		hInstance,
		NULL)))
	{
		return 0;
	}

	SendMessage(hWnd, WM_SYSCOMMAND, SC_SCREENSAVE, 0);
	return FALSE;
}