#pragma once
#include <windows.h>
#include <stdio.h>
inline LRESULT CALLBACK SimpleProc(HWND h, UINT m, WPARAM w, LPARAM l){
  if (m == WM_DESTROY) PostQuitMessage(0);
  return DefWindowProc(h,m,w,l);
}
inline HWND AddWindow(int width, int height,const char*title){
  WNDCLASS a = {0};
  a.lpfnWndProc = SimpleProc;
  a.lpszClassName = "ShortClass";
  RegisterClass(&a);
  HWND hwnd = CreateWindowA("ShortClass", title, WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, width, height, 0, 0, 0, 0);
  MSG msg;
  if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) { DispatchMessage(&msg); }
  return hwnd;
}
