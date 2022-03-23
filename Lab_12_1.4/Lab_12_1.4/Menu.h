// Menu.h
#pragma once
#include <iostream>
#include "StudentGroup.h"

bool isGoodFlag(int flag);
void MainMenu(StudentGroup& sg);
void FindMenu(const StudentGroup& sg);
void SortMenuDescending(StudentGroup& sg, int _choise);
void SortMenu(StudentGroup& sg);

