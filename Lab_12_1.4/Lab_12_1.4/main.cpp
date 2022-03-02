// main.cpp
#include <iostream>
#include <Windows.h>
#include "StudentGroup.h"
#include "MakeStudent.h"
using namespace std;

Student makeStudent(string name, string group, double avg_mark) {
	Student s;
	if (!s.Init(name, group, avg_mark))
		s = Student();
	return s;
}

int main() {
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);	

	//  клас Student
	Student s1;
	s1.Init("Іван Іванов", "ФЛ-31", 4.1);
	s1.Display();

	Student s2 = makeStudent("Петро Петрович", "IT-42", 3.18);
	s2.Display();

	StudentGroup studentGroup;
	studentGroup.Init(20);

	return 0;
}