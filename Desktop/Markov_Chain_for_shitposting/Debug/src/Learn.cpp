#include"Learn.h"  

/*
*
*@brief function add in list words string
*
*@param Words - it's your string cut in word
*@param ListWords - it's data from file
*
*/

void Learn(std::vector<std::string> &Words, std::unordered_map<std::string, std::unordered_set<std::string>> &ListWords) {  
 
 std::cout << "[DEBUG] Learn()" << std::endl;
 
 if(Words.size() == 1) { 
 
   ListWords.try_emplace(Words[0]);
 
 }
 else {
 
 	//Insert in list words new key and values
 	for(int i = 0; i + 1 < Words.size(); ++i) { 

		ListWords.try_emplace(Words[i]);
	
		//If in values be words don't add	
		ListWords[Words[i]].insert(Words[i+1]);
			
		
	
	

 	} 
 }
 
}
