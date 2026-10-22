#include "libexample.h"
int main(){
  printf("This is the C++ Libary Example");
  AddWindow(1300,1000,"C++ Libary Example");
  MSG msg;
  while (GetMessage(&msg, NULL, 0, 0)) { DispatchMessage(&msg); }
  return 0;
}
