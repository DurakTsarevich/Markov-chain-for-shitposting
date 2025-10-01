#include"Headers/pch.h"
#include"Headers/Learn.h"
#include"Headers/Generator.h"
#include"Headers/Text_Utils.h"
#include"Headers/Read_Write.h"
#include"Headers/Menu.h"
#include"Headers/Create_File.h"
#include"Headers/Choose_File.h"
#include"Headers/Start.h"
#include"Headers/Clear_screen.h"

//#define TEST_MODE

#ifdef TEST_MODE

#include "Unit_Test/Headers_test/Text_Utils_test.h"
#include "Unit_Test/Headers_test/Read_write_test.h"

#endif

int main() {

#ifdef TEST_MODE
 
 TEST_TEXT_UTILS();
 TEST_READ_WRITE();
 
#else

Clear();

 std::string Action;
 
 std::string FileName = "No file in work";
 
 std::cout << "[DEBUG] Launch Start.cpp" << std::endl;
 do {
 
 	Start(Action, FileName);
 	
 	Clear();
 
 } while(Action != "0" && FileName == "No file in work");
 
 

 while(Action != "0") {
	
	std::cout << "[DEBUG] Launch Menu.cpp" << std::endl;
	Menu(Action, FileName);  
	
	std::string String;
 
	if(Action == "1") {
 	 
 		do { 
 	
 			std::cout << "Enter text (no accept empty): ";
  			std::getline(std::cin, String);
 	
 		} while(String.empty());
 	        
 	        std::cout << "[DEBUG] Launch Text_Utils.cpp Funct: Split()" << std::endl;
 	        std::vector<std::string> Words = Split(String);
 	        
 	        std::cout << "[DEBUG] Launch Read_Write.cpp Funct: Read()" << std::endl;
 	        //Get data from file
 	        std::unordered_map<std::string, std::unordered_set<std::string>> ListWords = Read(FileName);
 	        
 	        std::cout << "[DEBUG] Launch Learn.cpp" << std::endl;
		Learn(Words, ListWords);
		
		//Write data in your file
		std::cout << "[DEBUG] Launch Read_Write.cpp Funct: Write()" << std::endl;
		Write(ListWords, Words, FileName);
 
 	}
	else if(Action == "2") {
    		
    		std::cout << "[DEBUG] Launch Read_Write.cpp Funct: Read()" << std::endl;
		//Get data from file
 	        std::unordered_map<std::string, std::unordered_set<std::string>> ListWords = Read(FileName);
 	        
 	        int size;
 	        
 	        std::cout << "[DEBUG] Get length of str" << std::endl;
 	        std::cout << "Enter count of word: ";
 	        std::cin >> size;
 	        
 	        std::cout << "[DEBUG] Launch Generator.cpp" << std::endl;
		std::cout << Generator(ListWords, size) << std::endl;
		
		std::cin.ignore();
		std::cin.get();
 	}
 	else if(Action == "3") {
 		
 		std::cout << "[DEBUG] Create name of file" << std::endl;
 		do { 
 	
 			std::cout << "Enter name of file (no accept empty, only .txt): ";
  			std::getline(std::cin, FileName);
 	
 		} while(FileName.empty());
 		
 		
 		std::cout << "[DEBUG] Launch Create_file.cpp Funct: Create_File()" << std::endl;
 		FileName = Create_File(FileName);
 	
 	}
	else if(Action == "4") {
 		
 		std::cout << "[DEBUG] Get name of file" << std::endl;
 		do { 
 	
 			std::cout << "Enter name of file: ";
  			std::getline(std::cin, FileName);
 	
 		} while(FileName.empty());
 		
 		std::cout << "[DEBUG] Launch Choose_file.cpp Funct: choose_file()" << std::endl;
 		FileName = choose_file(FileName);
 	
 	}
 	
  
	Clear();
	
 } 

#endif
 
 
 return 0;
 
}



