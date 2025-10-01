#include"Read_Write.h" 

/*
*
*@brief function get data from file
*
*@param FileName is file that is being read
*
*@return std::unordered_map<std::string, std::unordered_set<std::string>>
*
*/

std::unordered_map<std::string, std::unordered_set<std::string>> Read(std::string FileName) {
 
//Extract from file data, and creat list words
 std::unordered_map<std::string, std::unordered_set<std::string>> ListWords; 

 try { 
 
	std::ifstream MyFileIn(FileName); 

	if(MyFileIn.is_open()) { 

		ListWords = SplitForDataVector(MyFileIn); 

	} 
	else { 
                
 		throw std::runtime_error{"File don't open"}; 
    
	} 
	
 
 }
 catch(const std::exception &e) {

	std::cerr << e.what() << std::endl; 
  
 }  

 return ListWords;

}


/*
*
*@brief function write data to file
*
*@param ListWord is a list of word that will be written to the file
*@param FileName is file that is being write
*
*/

void Write(std::unordered_map<std::string, std::unordered_set<std::string>> ListWords, std::vector<std::string> Words, std::string FileName) {

 try { 

 std::ofstream MyFileOut(FileName); 


 if(MyFileOut.is_open()) { 

//Write if file is empty 
	if(!ListWords.empty()) { 


//Write data in file 
		for(auto &it : ListWords) { 

			MyFileOut << it.first << ' '; 

			for(auto &j : it.second) { 

				MyFileOut << j << ' '; 

			} 

			MyFileOut << "\n"; 

		} 

  	} 
	else { 

//Write if string is 1 word and file is empty
		if(Words.size() == 1) { 

			MyFileOut << Words[0] << " " << "\n"; 

		} 

//Write if string have more word and file is empty
  	 	else { 

			int i = 0; 

			for(; i + 1< Words.size(); ++i) { 

				MyFileOut << Words[i] << " " << Words[i] << "\n"; 

			} 

			MyFileOut << Words[i] << " " << "\n"; 

		} 

	} 

 } 
 else { 

 	throw std::runtime_error{"File don't open"}; 

 } 
	

 }
 catch(const std::exception &e) {

 	std::cerr << e.what() << std::endl;

 }

}
