#include "Clear_screen.h"

void Clear() {

 #ifdef _WIN32
 	system("cls");
 #else
 	system("clear");
 #endif

}
