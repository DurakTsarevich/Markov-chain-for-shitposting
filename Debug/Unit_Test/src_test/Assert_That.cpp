#include "Assert_That.h"

void assert_that(bool statement, std::string Failed_message, std::string Passed_message) {

 if(!statement) {
 
 	throw std::runtime_error(Failed_message);
 	
 }
 else {
 
 	std::cout << Passed_message << std::endl;
 
 }

}
