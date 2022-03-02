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
    delete[] getStudents();
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
