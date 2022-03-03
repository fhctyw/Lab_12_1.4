// StudentGroup.h
#pragma once
#include "Student.h"


class StudentGroup
{
	size_t size = 0;
	Student* students = nullptr;
public:
	size_t getSize() const;
	Student getStudent(size_t index) const;
	Student* getStudents() const;

	void setStudents(Student* students);
	void setStudent(size_t index, Student student);
	void setSize(size_t size);

	void Init(size_t size);
	void Free();

	void Add(Student student);
	void Delete(size_t index);

	size_t FindIndexByName(string name) const;
	size_t FindIndexByGroup(string group) const;
	size_t FindIndexByAvgMark(double avg_mark) const;

	void Sort(bool descending, int choice);

	void Display() const;
private:
	void QuickSort(int left, int right, bool descending, int choice);
};

