#include"Choose_File.h"

/*
*
*@brief function allows change file to work
*
*@param FileName this name of file for change
*
*@return std::string
*
*/

std::string choose_file(std::string FileName) {
std::cout << "[DEBUG] choose_file()" << std::endl;
 std::string FinalFileName;

 if(FileName.find(".") != std::string::npos) {

	FinalFileName = FileName.substr(0, FileName.find("."));
	FinalFileName += ".txt";

 }
 else {
	FinalFileName = FileName + ".txt";
 }


 if(std::filesystem::exists(FinalFileName)) {

	FileName = FinalFileName;

 }
 else {

	FileName = "No file in work";
	
	std::cout << "File don't exists\n";
	std::cout << "Click anyone cup\n";
	std::cin.get();
 
 }

 return FileName;

}
