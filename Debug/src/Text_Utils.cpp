#include"Text_Utils.h"

/*
*
*@brief Function for split string in word
*
*@param String - your text for split in word
*
*@return vector with words
*
*/

std::vector<std::string> Split(std::string String) {

 std::cout << "[DEBUG] Split()" << std::endl;

 std::vector<std::string> Words = {};
 std::string Word = "";
 
 
//Split string in words
 for(int i = 0; i < String.size(); ++i) {
   
   
	if(String[i] != ' ' && String[i] != '	' ) { //It's Tab( '	' ), because symbol '\t' don't work 
   
		Word += String[i];  
      
	}
	else if(!Word.empty()){
   
		Words.push_back(Word);
		Word = "";
     
	}
   
   
 }
 
//Add last word
 if(!Word.empty()) {
 
	Words.push_back(Word);
	Word = "";
   
 }
 
 return Words;
  
}



/*
*
*@brief Function for get data from file and create list words
*
*@param MyFile - it's a file save list words
*
*@return unordered map with list words
*
*/

std::unordered_map<std::string, std::unordered_set<std::string>> SplitForDataVector(std::ifstream &MyFileIn) {
 std::cout << "[DEBUG] SplitForDataVector()" << std::endl;

 std::unordered_map<std::string, std::unordered_set<std::string>> Words;
 std::string line;

 //Get and split data from file
 while (std::getline(MyFileIn, line)) {   
    
	std::vector<std::string> temp = Split(line); 
       
	Words.try_emplace({temp[0],{}});
        
	for(int i = 1; i < temp.size(); ++i) {
        
		Words[temp[0]].insert(temp[i]);
          
	}
               
 }

 return Words;
    
}
