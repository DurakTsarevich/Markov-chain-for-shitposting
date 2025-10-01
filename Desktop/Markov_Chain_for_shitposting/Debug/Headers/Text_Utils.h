#pragma once

#include"pch.h"

std::vector<std::string> Split(std::string String);
std::unordered_map<std::string, std::unordered_set<std::string>> SplitForDataVector(std::ifstream &MyFile);
