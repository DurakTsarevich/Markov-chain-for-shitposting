#include "Start.h"

/*
*
*@brief function first menu befor execute of program
*
*@param Action this is what will do
*@param FileName this file is what will use in program until change it
*
*/

void Start(std::string &Action, std::string &FileName) {
 std::cout << "[DEBUG] Start()" << std::endl;
 Action.clear();
       
 std::cout << "\t\t Please create or choose file!" << std::endl;
 std::cout << "\tCreate file enter -    1" << std::endl;
 std::cout << "\tChoose file enter - 2" << std::endl; 
 std::cout << "\tExit enter - 0" << std::endl; 
       	
 bool IsEmpty = true;
  
 while(IsEmpty) {
  
	if(Action == "1" || Action == "2" || Action == "0") {
	IsEmpty = false;
    
 }
  
 if(IsEmpty == false) break;
  
	Action.clear();
  
	std::cout << "Enter number(0, 1, or 2): ";
	std::getline(std::cin, Action);  
  
 }  
       	
 if(Action == "1") {
 	
 	do { 
 	
 		std::cout << "Enter name of file (no accept empty, only .txt): ";
  		std::getline(std::cin, FileName);
 	
 	} while(FileName.empty());
 		
 		
 	FileName = Create_File(FileName);
 			
 	
 }
 else if(Action == "2") {
 	
	 do { 
 	
		std::cout << "Enter name of file: ";
  		std::getline(std::cin, FileName);
 	
	 } while(FileName.empty());
 		
 		
 	FileName = choose_file(FileName);
 			
 	
 }
 		
 				   		     		    		
}
