#ifndef GUI_H
#define GUI_H

#include <windows.h>

#define IDC_USERNAME 1001
#define IDC_PASSWORD 1002
#define IDC_LOGIN_BTN 1003
#define IDC_REGISTER_BTN 1004
#define IDC_ADD_BTN 2001
#define IDC_VIEW_BTN 2002
#define IDC_SEARCH_BTN 2003
#define IDC_UPDATE_BTN 2004
#define IDC_DELETE_BTN 2005
#define IDC_EXIT_BTN 2006
#define IDC_NAME 3001
#define IDC_AGE 3002
#define IDC_GENDER 3003
#define IDC_ADDRESS 3004
#define IDC_PHONE 3005
#define IDC_EMAIL 3006
#define IDC_MATH 3007
#define IDC_PHYSICS 3008
#define IDC_CHEMISTRY 3009
#define IDC_ENGLISH 3010
#define IDC_COMPUTER 3011
#define IDC_SAVE_BTN 3012
#define IDC_CANCEL_BTN 3013
#define IDC_SEARCH_ID 4001
#define IDC_SEARCH_GO 4002
#define IDC_RESULT_LIST 4003

LRESULT CALLBACK LoginWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK AddStudentProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ViewStudentsProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK SearchStudentProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

extern HINSTANCE hInst;
extern HWND hMainWindow;

#endif