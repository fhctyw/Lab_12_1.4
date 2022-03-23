// Student.cpp
#include "Student.h"
#include <iostream>
#include <sstream>

int findDig(int x, int index)
{
    int length = 0;
    int xx = x;
    while (xx /= 10) length++;

    int y = pow(10, abs(index - length));
    return (x / y) - ((x / (y * 10)) * 10);
}

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
        cin.get();
    } while (!Init(name, group, avg_mark));
}

void Student::Display() const
{
    cout << toString() << endl;
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

bool lessthan(const Student& s1, const Student& s2, int flag)
{
    int dig = findDig(flag, 0);
    switch (dig)
    {
    case 1: {
        int dig2 = findDig(flag, 1);
        if (dig2 == 2)
        {
            int dig3 = findDig(flag, 2);
            if (dig3 == 3)
                return s1.name < s2.name || s1.name == s2.name && s1.group < s2.group || s1.name == s2.name && s1.group == s2.group && s1.avg_mark < s2.avg_mark;
            return s1.name < s2.name || s1.name == s2.name && s1.group < s2.group;
        }
        else if (dig2 == 3)
        {
            int dig3 = findDig(flag, 2);
            if (dig3 == 1)
                return s1.name < s2.name || s1.name == s2.name && s1.avg_mark < s2.avg_mark || s1.name == s2.name && s1.avg_mark == s2.avg_mark && s1.group < s2.group;
            return s1.name < s2.name || s1.name == s2.name && s1.avg_mark < s2.avg_mark;
        }
        return s1.name < s2.name;
    }
    case 2: {
        int dig2 = findDig(flag, 1);
        if (dig2 == 1)
        {
            int dig3 = findDig(flag, 2);
            if (dig3 == 3)
                return s1.group < s2.group || s1.group == s2.group && s1.name < s2.name || s1.group == s2.group && s1.name == s2.name && s1.avg_mark < s2.avg_mark;
            return s1.group < s2.group || s1.group == s2.group && s1.name < s2.name;
        }
        else if (dig2 == 3)
        {
            int dig3 = findDig(flag, 2);
            if (dig3 == 3)
                return s1.group < s2.group || s1.group == s2.group && s1.avg_mark < s2.avg_mark || s1.group == s2.group && s1.avg_mark == s2.avg_mark && s1.name < s2.name;
            return s1.group < s2.group || s1.group == s2.group && s1.avg_mark < s2.avg_mark;
        }
        return s1.group < s2.group;
    }
    case 3: {
        int dig2 = findDig(flag, 1);
        if (dig2 == 1)
        {
            int dig3 = findDig(flag, 2);
            if (dig3 == 3)
                return s1.avg_mark < s2.avg_mark || s1.avg_mark == s2.avg_mark && s1.name < s2.name || s1.avg_mark == s2.avg_mark && s1.name == s2.name && s1.group < s2.group;
            return s1.avg_mark < s2.avg_mark || s1.avg_mark == s2.avg_mark && s1.name < s2.name;
        }
        else if (dig2 == 2)
        {
            int dig3 = findDig(flag, 2);
            if (dig3 == 3)
                return s1.avg_mark < s2.avg_mark || s1.avg_mark == s2.avg_mark && s1.group < s2.group || s1.avg_mark == s2.avg_mark && s1.group == s2.group && s1.name < s2.name;
            return s1.avg_mark < s2.avg_mark || s1.avg_mark == s2.avg_mark && s1.group < s2.group;
        }
        return s1.avg_mark < s2.avg_mark;
    }

    }
    return true;
    
}

bool greatthan(const Student& s1, const Student& s2, int flag)
{
    int dig = findDig(flag, 0);
    switch (dig)
    {
    case 1: {
        int dig2 = findDig(flag, 1);
        if (dig2 == 2)
        {
            int dig3 = findDig(flag, 2);
            if (dig3 == 3)
                return s1.name > s2.name || s1.name == s2.name && s1.group > s2.group || s1.name == s2.name && s1.group == s2.group && s1.avg_mark > s2.avg_mark;
            return s1.name > s2.name || s1.name == s2.name && s1.group > s2.group;
        }
        else if (dig2 == 3)
        {
            int dig3 = findDig(flag, 2);
            if (dig3 == 1)
                return s1.name > s2.name || s1.name == s2.name && s1.avg_mark > s2.avg_mark || s1.name == s2.name && s1.avg_mark == s2.avg_mark && s1.group > s2.group;
            return s1.name > s2.name || s1.name == s2.name && s1.avg_mark > s2.avg_mark;
        }
        return s1.name > s2.name;
    }
    case 2: {
        int dig2 = findDig(flag, 1);
        if (dig2 == 1)
        {
            int dig3 = findDig(flag, 2);
            if (dig3 == 3)
                return s1.group > s2.group || s1.group == s2.group && s1.name > s2.name || s1.group == s2.group && s1.name == s2.name && s1.avg_mark > s2.avg_mark;
            return s1.group > s2.group || s1.group == s2.group && s1.name > s2.name;
        }
        else if (dig2 == 3)
        {
            int dig3 = findDig(flag, 2);
            if (dig3 == 3)
                return s1.group > s2.group || s1.group == s2.group && s1.avg_mark > s2.avg_mark || s1.group == s2.group && s1.avg_mark == s2.avg_mark && s1.name > s2.name;
            return s1.group > s2.group || s1.group == s2.group && s1.avg_mark > s2.avg_mark;
        }
        return s1.group > s2.group;
    }
    case 3: {
        int dig2 = findDig(flag, 1);
        if (dig2 == 1)
        {
            int dig3 = findDig(flag, 2);
            if (dig3 == 3)
                return s1.avg_mark > s2.avg_mark || s1.avg_mark == s2.avg_mark && s1.name > s2.name || s1.avg_mark == s2.avg_mark && s1.name == s2.name && s1.group > s2.group;
            return s1.avg_mark > s2.avg_mark || s1.avg_mark == s2.avg_mark && s1.name > s2.name;
        }
        else if (dig2 == 2)
        {
            int dig3 = findDig(flag, 2);
            if (dig3 == 3)
                return s1.avg_mark > s2.avg_mark || s1.avg_mark == s2.avg_mark && s1.group > s2.group || s1.avg_mark == s2.avg_mark && s1.group == s2.group && s1.name > s2.name;
            return s1.avg_mark > s2.avg_mark || s1.avg_mark == s2.avg_mark && s1.group > s2.group;
        }
        return s1.avg_mark > s2.avg_mark;
    }

    }
    return false;
}
