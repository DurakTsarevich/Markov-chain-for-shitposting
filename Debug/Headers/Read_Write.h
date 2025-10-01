#pragma once

#include"pch.h"
#include"Text_Utils.h" 

std::unordered_map<std::string, std::unordered_set<std::string>> Read(std::string FileName); 
void Write(std::unordered_map<std::string, std::unordered_set<std::string>> ListWords, std::vector<std::string> Words, std::string FileName); 
