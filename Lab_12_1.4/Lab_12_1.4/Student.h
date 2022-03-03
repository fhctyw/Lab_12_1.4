// Student.h
#pragma once
#include <string>
using namespace std;

class Student
{
	string name;
	string group;
	double avg_mark;
public:
	string getName() const;
	string getGroup() const;
	double getAvgMark() const;

	void setName(string name);
	void setGroup(string group);
	void setAvgMark(double avg_mark);
	
	void Read();
	void Display() const;
	bool Init(string name, string group, double avg_mark);
	string toString() const;
};

int compare(const Student& s1, const Student& s2, bool descending, int choice);