#pragma once
#include "Func.hpp"
#include <stack>
using namespace ZDA;
using namespace std;
bool RunMenu = true;
SingleList* list = new SingleList();
SingleList* list2 = new SingleList();
SingleList* list3 = new SingleList();
SingleList* list2_reverse = new SingleList();
SingleList* list3_reverse = new SingleList();
SingleList* result = new SingleList();
string fileOtput;
string fileInput;
void FilesInput(const char* input, const char* otput)
{

	fileInput = input;
	fileOtput = otput;
}
bool InputDataFromText2(string filename)
{
	system("cls");
	SingleList* listbuf = new SingleList();
	int buff = 0;
	int i = 0;
	ifstream file(filename + ".txt");
	while (!file.eof())
	{
		file >> buff;
		listbuf->AddItem(buff);
	}
	file.close();
	while (!listbuf->IsEmpty()) {
		list->AddItem(listbuf->GetTop()->data);
		listbuf->DeleteItem(1);
	}
	ContunieOrNot();
	return true;
}
bool OutputToFile2(string filename)
{
	fstream file;
	file.open(filename + ".txt");
	while (!result->IsEmpty()) {
		auto buf = result->GetTop()->data;
		file << buf << ' ';
		result->DeleteItem(1);
	}
	file.close();
	return true;
}

void ContunieOrNot()
{
	int Checker = 0;
	cout << "Back to menu?(1 - Yes 0 - No)\n>>> ";
	cin >> Checker;
	if (Checker == 1)
	{
		RunMenu = true;
	}
	else
	{
		RunMenu = false;
	}
}
bool DataInputFromKeyboard()
{
	system("cls");
	cout << "Enter size: ";
	int size; cin >> size; cout << endl;
	for (int i = 0; i < size; i++) {
		cout << "Enter value: ";
		int value; cin >> value;
		list->AddItem(value);
	}
	cout << endl;
	ContunieOrNot();
	return true;
}
bool InputDataFromText()
{

	system("cls");
	SingleList* listbuf = new SingleList();
	int buff = 0;
	int i = 0;
	ifstream file2(fileInput + ".txt");
	if (file2.fail())
	{
		ifstream file("1.txt");
		while (!file.eof())
		{
			file >> buff;
			listbuf->AddItem(buff);
		}
		file.close();
		while (!listbuf->IsEmpty()) {
			list->AddItem(listbuf->GetTop()->data);
			listbuf->DeleteItem(1);
		}
		ContunieOrNot();
	}
	else
	{
		InputDataFromText2(fileInput);
	}
	return true;
}
bool OutputToFile()
{
	fstream file2(fileOtput + ".txt");
	if (file2.fail())
	{
		fstream file;
		file.open("Result.txt");
		while (!result->IsEmpty()) {
			auto buf = result->GetTop()->data;
			file << buf << ' ';
			result->DeleteItem(1);
		}
		file.close();
		ContunieOrNot();
	}
	else
	{
		OutputToFile2(fileOtput);
	}

	return true;
}
bool IndividualQuestions()
{
	if (list->IsEmpty() == 0) {
		while (!list->IsEmpty()) {
			if (list->GetTop()->data < 0) {
				list2->AddItem(list->GetTop()->data);
				list->DeleteItem(1);
			}
			else {
				list3->AddItem(list->GetTop()->data);
				list->DeleteItem(1);
			}

		}
		while (!list2->IsEmpty()) {
			list2_reverse->AddItem(list2->GetTop()->data);
			list2->DeleteItem(1);
		}
		while (!list3->IsEmpty()) {
			list3_reverse->AddItem(list3->GetTop()->data);
			list3->DeleteItem(1);
		}
		while (!list3_reverse->IsEmpty()) {
			result->AddItem(list3_reverse->GetTop()->data);
			list3_reverse->DeleteItem(1);
		}
		while (!list2_reverse->IsEmpty()) {
			result->AddItem(list2_reverse->GetTop()->data);
			list2_reverse->DeleteItem(1);
		}
		result->PrintList();
	}
	else if (list->IsEmpty() == 1)
	{
		cout << "No data!" << endl;
	}
	ContunieOrNot();
	return true;
}
bool PrintData()
{
	if (list->IsEmpty() == 1)
	{
		cout << "No data!" << endl;
		ContunieOrNot();
	}
	else
	{
		list->PrintList();
		ContunieOrNot();
	}
	return true;
}
bool Add() {
	int addition=0;
	cout << "Input element to add\n>>> ";
	cin >> addition;
	list->AddItem(addition);
	return true;
}
bool Delete() {
	int deltion=0;
	cout << "Input element to delete\n>>> ";
	cin >> deltion;
	std::vector<int> v;
	while (!list->IsEmpty())
	{
		if (list->GetTop()->data != deltion)               
			v.push_back(list->GetTop()->data);   

		list->DeleteItem(1);
	}
	for (int i = v.size() - 1; i >= 0; --i)
		list->AddItem(v[i]);
	return true;
}