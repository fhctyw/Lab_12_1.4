// main.cpp
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "StudentGroup.h"
#include "Menu.h"
using namespace std;

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