// Student.cpp
#include "Student.h"
#include <iostream>
#include <sstream>

string Student::getName() const
{
    return name;
}

string Student::getGroup() const
{
    return group;
}

double Student::getAvgMark() const
{
    return avg_mark;
}

void Student::setName(string name)
{
    this->name = name;
}

void Student::setGroup(string group)
{
    this->group = group;
}

void Student::setAvgMark(double avg_mark)
{
    this->avg_mark = avg_mark;
}

void Student::Read()
{
    string name, group;
    double avg_mark;
    
    cin.get();
    do {
        cout << "Введіть прізвище та ім'я: ";
        getline(cin, name);
        
        cout << "Введіть групу студента: ";
        getline(cin, group);
        
        cout << "Введіть середню оцінку з предметів: ";
        cin >> avg_mark;
        
    } while (!Init(name, group, avg_mark));
}

void Student::Display() const
{
    cout << "Студент: " << name << ", Група: " << group << ", Середня оцінка: " << avg_mark << endl;
}

bool Student::Init(string name, string group, double avg_mark)
{
    setName(name);
    setGroup(group);
    setAvgMark(avg_mark);

    return this->avg_mark > 0 && this->avg_mark <= 5;
}

string Student::toString() const
{
    stringstream ss;
    ss << "Студент: " << name << ", Група: " << group << ", Середня оцінка: " << avg_mark;
    return ss.str();
}

int compare(const Student& s1, const Student& s2, bool descending, int choice)
{
    if (choice == 1) {
        if (s1.getName() < s2.getName()) return descending ? -1 : 1;
        if (s1.getName() > s2.getName()) return descending ? 1 : -1;
    }
    if (choice == 2) {
        if (s1.getGroup() < s2.getGroup()) return descending ? -1 : 1;
        if (s1.getGroup() > s2.getGroup()) return descending ? 1 : -1;
    }
    if (choice == 3) {
        if (s1.getAvgMark() < s2.getAvgMark()) return descending ? -1 : 1;
        if (s1.getAvgMark() > s2.getAvgMark()) return descending ? 1 : -1;
    }
    return 0;
}
