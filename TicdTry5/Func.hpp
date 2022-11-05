#pragma once
#include <vector>
#include <fstream>
#include <Windows.h>
#include <iostream>
#include "Menu.hpp"
#include "Item.hpp"
#include "List.hpp"
bool DataInputFromKeyboard();
bool IndividualQuestions();
bool OutputToFile();
bool InputDataFromText();
bool PrintData();
void ContunieOrNot();
void ZapisOutput(string filename);
void ZapisInput(string filename);
void FilesInput(const char* a, const char* b);
bool Add();
bool Delete();