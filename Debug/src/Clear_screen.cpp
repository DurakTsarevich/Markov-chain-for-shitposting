#include "Clear_screen.h"

void Clear() {
std::cout << "[DEBUG] Clear()" << std::endl;
 #ifdef _WIN32
 	system("cls");
 #else
 	system("clear");
 #endif

}
