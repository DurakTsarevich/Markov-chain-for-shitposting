#include"Create_File.h"

/*
*
*@brief function allows create file for work
*
*@param FileName this name of file for create
*
*/

std::string Create_File(std::string FileName) {

 std::string FinalFileName;

 if(FileName.find(".") != std::string::npos) {

	FinalFileName = FileName.substr(0, FileName.find("."));
	FinalFileName += ".txt";

 }
 else {
	FinalFileName = FileName + ".txt";
 }

 if(!(std::filesystem::exists(FinalFileName))) {

	std::ofstream File (FinalFileName);

 }
 else {

	std::cout << "File exists\n";
	std::cout << "Click anyone cup\n";
	std::cin.get();
 
 }

 return FinalFileName;

}
