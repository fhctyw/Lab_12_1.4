// main.cpp
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "StudentGroup.h"
#include "Menu.h"
using namespace std;

Student makeStudent(string name, string group, double avg_mark) {
	Student s;
	if (!s.Init(name, group, avg_mark))
		s = Student();
	return s;
}

int main()
{
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	
	StudentGroup sg;

	MainMenu(sg);

	sg.Free();
	return 0;
}