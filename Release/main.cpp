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


int main() {

 Clear();

 std::string Action;
 
 std::string FileName = "No file in work";
 
 do {
 
 	Start(Action, FileName);
 	
 	Clear();
 
 } while(Action != "0" && FileName == "No file in work");
 
 

 while(Action != "0") {
	
	Menu(Action, FileName);  
	
	std::string String;
 
	if(Action == "1") {
 	 
 		do { 
 	
 			std::cout << "Enter text (no accept empty): ";
  			std::getline(std::cin, String);
 	
 		} while(String.empty());
 	        
 	        std::vector<std::string> Words = Split(String);
 	        
 	        //Get data from file
 	        std::unordered_map<std::string, std::unordered_set<std::string>> ListWords = Read(FileName);
 	        
 	        
		Learn(Words, ListWords);
		
		//Write data in your file
		Write(ListWords, Words, FileName);
 
 	}
	else if(Action == "2") {
    
		//Get data from file
 	        std::unordered_map<std::string, std::unordered_set<std::string>> ListWords = Read(FileName);
 	        
 	        int size;
 	        
 	        std::cout << "Enter count of word: ";
 	        std::cin >> size;
 	        
		std::cout << Generator(ListWords, size) << std::endl;
		
		std::cin.ignore();
		std::cin.get();
 	}
 	else if(Action == "3") {
 	
 		do { 
 	
 			std::cout << "Enter name of file (no accept empty, only .txt): ";
  			std::getline(std::cin, FileName);
 	
 		} while(FileName.empty());
 		
 		
 		FileName = Create_File(FileName);
 	
 	}
	else if(Action == "4") {
 	
 		do { 
 	
 			std::cout << "Enter name of file: ";
  			std::getline(std::cin, FileName);
 	
 		} while(FileName.empty());
 		
 		
 		FileName = choose_file(FileName);
 	
 	}
 	
  
	Clear();
	
 } 
 
 
 return 0;
 
}



