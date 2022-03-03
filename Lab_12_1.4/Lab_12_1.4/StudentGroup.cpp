// StudentGroup.cpp
#include "StudentGroup.h"
#include <iostream>
#include <iomanip>

size_t StudentGroup::getSize() const
{
    return size;
}

Student StudentGroup::getStudent(size_t index) const
{
    return students[index];
}

Student* StudentGroup::getStudents() const
{
    return students;
}

void StudentGroup::setStudents(Student* students)
{
    this->students = students;
}

void StudentGroup::setStudent(size_t index, Student student)
{
    students[index] = student;
}

void StudentGroup::setSize(size_t size)
{
    this->size = size;
}

void StudentGroup::Init(size_t size)
{
    setSize(size);
    setStudents(new Student[size]());
}

void StudentGroup::Free()
{
    if (students != nullptr)
        delete[] students;
}

void StudentGroup::Add(Student student)
{
    Student* tmp = new Student[size + 1]();
    for (size_t i = 0; i < size; i++)
        tmp[i] = students[i];
    tmp[size++] = student;
    
    if (students != nullptr)
        delete[] students;
    
    students = tmp;
    
}

void StudentGroup::Delete(size_t index)
{
    if (index >= 0 && index < size) {
        Student* tmp = new Student[size - 1]();
        for (size_t i = 0, i1 = 0; i < size; i++, i1++)
        {
            if (i == index) {
                i1--;
                continue;
            }
            tmp[i1] = students[i];
        }
        size--;
        if (students != nullptr)
            delete[] students;
        students = tmp;
    }
}

size_t StudentGroup::FindIndexByName(string name) const
{
    for (size_t i = 0; i < size; i++)
        if (getStudent(i).getName() == name)
            return i;
    return -1;
}

size_t StudentGroup::FindIndexByGroup(string group) const
{
    for (size_t i = 0; i < size; i++)
        if (getStudent(i).getGroup() == group)
            return i;
    return -1;
}

size_t StudentGroup::FindIndexByAvgMark(double avg_mark) const
{
    for (size_t i = 0; i < size; i++)
        if (int(getStudent(i).getAvgMark()*100) == int(avg_mark*100))
            return i;
    return -1;
}

void StudentGroup::Sort(bool descending, int choise)
{
    QuickSort(0, getSize() - 1, descending, choise);
}

void StudentGroup::Display() const
{
    cout << left << fixed << setprecision(2);
    cout << "========================================================" << endl;
    cout << "|  №  |      Прізвище ім'я      | Група | Середній бал |" << endl;
    cout << "========================================================" << endl;

    for (size_t i = 0; i < size; i++)
        cout << '|' 
        << setw(5) << i << '|' 
        << setw(25) << students[i].getName() << '|'
        << setw(7) <<  students[i].getGroup() << '|' 
        << setw(14) << students[i].getAvgMark() << '|' << endl;
    cout << "========================================================" << endl;
    cout << right << defaultfloat;
}

void StudentGroup::QuickSort(int left, int right, bool descending, int choise)
{
    int l = left, r = right;
    Student mid = students[(right + left) / 2];

    while (l <= r)
    {
        while (compare(students[l], mid, descending, choise) < 0) l++;
        while (compare(students[r], mid, descending, choise) > 0) r--;
        if (l <= r) {
            swap(students[l], students[r]);
            l++;
            r--;
        }
    }
    if (left < r) QuickSort(left, r, descending, choise);
    if (right > l) QuickSort(l, right, descending, choise);
}
