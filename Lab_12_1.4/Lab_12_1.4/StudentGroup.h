// StudentGroup.h
#pragma once
#include "Student.h"


class StudentGroup
{
	size_t size;
	Student* students;
public:
	size_t getSize() const;
	Student getStudent(size_t index) const;
	Student* getStudents() const;

	void setStudents(Student* students);
	void setStudent(size_t index, Student student);
	void setSize(size_t size);

	void Init(size_t size);
	void Free();

	void Display() const;
};

