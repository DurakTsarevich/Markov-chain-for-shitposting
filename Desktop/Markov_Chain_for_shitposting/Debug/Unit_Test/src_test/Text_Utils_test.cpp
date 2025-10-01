#include "Text_Utils_test.h"


void TEST_TEXT_UTILS() {

 std::cout << "Test Text_Utils.cpp Function: Split()" << std::endl;
 std::cout << "The emptiness tests were not performed because the program does not accept them, this is regulated in main.cpp" << std::endl;

 std::string Tab = "			";
 std::string Space = "                  ";
 std::string MultyWord = "fsdfgaf dfgdasfg dfgdsfgd 			fdaszfgsdhb   	dsfgsadhdf   ;lh;gdhlfg;";
 std::string SingleWord = "fsdfgaf";
 
 
 
 std::vector<std::string> V_Split1 = Split(Tab);
 
 std::vector<std::string> V_Split2 = Split(Space);
 
 std::vector<std::string> V_Split3 = Split(MultyWord);
 std::vector<std::string> SplitMultyWord = {"fsdfgaf", "dfgdasfg", "dfgdsfgd", "fdaszfgsdhb", "dsfgsadhdf", ";lh;gdhlfg;"};
 
 std::vector<std::string> V_Split4 = Split(SingleWord);
 std::vector<std::string> SplitSingleWord = {"fsdfgaf"};
 
 try {
  
	assert_that(V_Split1.empty(), "[-] Failed: Vector not empty", "[+] Passed: Empty vector free tab");
  
	assert_that(V_Split2.empty(), "[-] Failed: Vector not empty", "[+] Passed: Empty vector free space");
  
	assert_that(V_Split3 == SplitMultyWord, "[-] Failed: Split() have a problem", "[+] Passed: Vector with many word");
  
	assert_that(V_Split4 == SplitSingleWord, "[-] Failed: Split() have a problem", "[+] Passed: Vector with one word");
 
 }
 
 catch(std::runtime_error &e) {
 
	std::cout << "Assertion failed: " << e.what() << std::endl;
 
 }
 
 
 
 std::cout<< "Test Text_Utils.cpp Function: SplitForDataVector()" << std::endl;
 
 
 
 std::ifstream File1("TXT_for_test/Many_Words.txt");
 std::unordered_map<std::string, std::unordered_set<std::string>> DataFile1 = SplitForDataVector(File1);
 
 std::unordered_map<std::string, std::unordered_set<std::string>> DataVector1 = {{"are", {"you"} }, {"How", {"are"} }, {"is" ,{"top"} }, {"Vaniok", {"is"} }, {"world" , {"of"} },{"rtr", { "trtrtr" }}, {"of", { "IT" } }, {"trtrtr", { "rtrtrtr" } }, {"rtrtrtr", { "rtrtr" } }, {"Hello" , { "world" }} };
 
 
 
 std::ifstream File2("TXT_for_test/One_Word.txt");
 std::unordered_map<std::string, std::unordered_set<std::string>> DataFile2 = SplitForDataVector(File2);
 
 std::unordered_map<std::string, std::unordered_set<std::string>> DataVector2 = {{"fdsfghsdfsgdsfgsdfgsdfgdsfgdfgsdfg", {} } };
 
 
 
 try {
  
	assert_that(DataFile1 == DataVector1, "[-] Failed: SplitDataForVector() have a problem", "[+] Passed: unordered map with many word");
  
	assert_that(DataFile2 == DataVector2, "[-] Failed: SplitDataForVector() have a problem", "[+] Passed: unordered map with one word");
 
 } 
 catch(std::runtime_error &e) {
 
 	std::cout << "Assertion failed: " << e.what() << std::endl;
 
 }
 
}
