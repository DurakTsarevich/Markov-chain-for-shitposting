#include"Generator.h"

/*
*
*@brief function for generate scent
*
*@param ListWord is list of word from which words will be bred for generation
*@param size is length of scent
*
*@return std::unordered_map<std::string, std::unordered_set<std::string>>
*
*/

std::string Generator(const std::unordered_map<std::string, std::unordered_set<std::string>> &ListWords, int size) {

 if(ListWords.empty()) return "File is empty, please tech program";

 std::string String;

 std::random_device rd;
 
 std::mt19937 gen(rd());
 
 std::uniform_int_distribution<> distribKey(0, ListWords.size() - 1);
 
 int RandomKey = distribKey(gen);
 
 auto itKey = ListWords.begin();
 std::advance(itKey, RandomKey);
 

 String += itKey->first;
 
 
for(int i = 0; i < size; ++i) {
     
     if(!itKey->second.empty()) {
     
     	std::uniform_int_distribution<> distribValue(0, itKey->second.size() - 1);
 
	int RandomValue = distribValue(gen);
 
	auto itValue = itKey->second.begin();
	std::advance(itValue, RandomValue);
 
        String += " " + *itValue;
 
	if(ListWords.find(*itValue) == ListWords.end()) break;
 
	itKey = ListWords.find(*itValue);
     
     }
     else break;	
 
}
 
 return String;
 
}
