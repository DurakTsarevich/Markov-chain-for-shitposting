#include"Menu.h"

/*
*
*@brief function second menu befor Start.cpp
*
*@param Action this is what will do
*@param FileName this file is what will use in program until change it
*
*/

void Menu(std::string &LearnOrGenerate, std::string FileName) {

 std::cout << "[DEBUG] Menu()" << std::endl;

 LearnOrGenerate.clear(); 

 std::cout << "\t\tMenu" << std::endl;
 std::cout << "\tLearn enter -    1";
 std::cout << "\t\t\t\t File in work: " << FileName << std::endl;
 std::cout << "\tGenerate enter - 2" << std::endl; 
 std::cout << "\tCreate file enter - 3" << std::endl; 
 std::cout << "\tChoose file enter - 4" << std::endl; 
 std::cout << "\tExit -           0" << std::endl; 
  
 bool IsEmpty = true;
  
 while(IsEmpty) {
  
	if(LearnOrGenerate == "1" || LearnOrGenerate == "2" || LearnOrGenerate == "3" || LearnOrGenerate == "4" || LearnOrGenerate == "0") {
		IsEmpty = false;
    
	}
  
	if(IsEmpty == false) break;
  
	LearnOrGenerate.clear();
  
	std::cout << "Enter number(0, 1, 2, 3 or 4): ";
	std::getline(std::cin, LearnOrGenerate);  
  
 }  

}
