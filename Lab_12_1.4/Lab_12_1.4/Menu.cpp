// Menu.cpp
#include "Menu.h"
#include "MakeStudent.h"

bool isGoodFlag(int flag)
{
	int length = 1;
	while (flag /= 10) length++;
	
	return length == 3;
}

void FindMenu(const StudentGroup& sg)
{
	int choice;
	do {
		cout << "Виберіть критерій пошуку" << endl;
		cout << "1. За прізвищем та ім'ям" << endl;
		cout << "2. За групою" << endl;
		cout << "3. За середньою оцінкою" << endl;
		cout << "0. Назад" << endl;

		cout << "choice: "; cin >> choice;
		cin.get();

		switch (choice)
		{
		case 1: {
			string name;
			cout << "Введіть прізвище та ім'я: ";
			getline(cin, name);
			auto i = sg.FindIndexByName(name);
			if (i == -1)
				cout << "Студента не знайдено" << endl;
			else
				cout << "[" << sg.getStudent(i).toString() << "]" << endl;
			break;
		}
		case 2: {
			string group;
			cout << "Введіть групу: ";
			getline(cin, group);
			auto i = sg.FindIndexByGroup(group);
			if (i == -1)
				cout << "Студента не знайдено" << endl;
			else
				cout << "[" << sg.getStudent(i).toString() << "]" << endl;
			break;
		}
		case 3: {
			double avg_mark;
			cout << "Введіть середній бал: ";
			cin >> avg_mark;
			auto i = sg.FindIndexByAvgMark(avg_mark);
			if (i == -1)
				cout << "Студента не знайдено" << endl;
			else
				cout << "[" << sg.getStudent(i).toString() << "]" << endl;
			break;
		}

		}
		cout << endl;
	} while (choice != 0);
}

void SortMenuDescending(StudentGroup& sg, int _choice) {
	int choice;
	do {
		cout << "Виберіть за спаданням/зростанням" << endl;
		cout << "1. За спаданням" << endl;
		cout << "2. За зростанням" << endl;
		cout << "0. Назад" << endl;

		cout << "choice: "; cin >> choice;
		cin.get();

		if (choice == 1)
			sg.Sort(_choice, false);
		else if (choice == 2)
			sg.Sort(_choice, true);

		cout << endl;

		if (choice == 1 || choice == 2) break;
	} while (choice != 0);
}

void SortMenu(StudentGroup& sg) {
	int choice;
	
	do {
		cout << "Виберіть критерій сорутвання" << endl
			<< "Наприклад: 231" << endl
			<< "2 - Перший" << endl
			<< "3 - Другий" << endl
			<< "1 - Третій" << endl;
		cout << "1. За прізвищем та ім'ям" << endl;
		cout << "2. За групою" << endl;
		cout << "3. За середньою оцінкою" << endl;
		cout << "0. Назад" << endl;

		cout << "choice: "; cin >> choice;
		cin.get();

		if (isGoodFlag(choice)) {
			SortMenuDescending(sg, choice);
			break;
		}
	} while (choice != 0);
}

void MainMenu(StudentGroup& sg)
{
	cout << "Меню класу \"студентська група\"" << endl;
	int choice;
	do {
		cout << "1. Відобразити студентів" << endl;
		cout << "2. Добавити студента в групу" << endl;
		cout << "3. Вилучити студента із групи" << endl;
		cout << "4. Добавити n-кількість випадкових студентів" << endl;
		cout << "5. Знайти" << endl;
		cout << "6. Сортувати" << endl;
		cout << "0. Вихід" << endl;


		cout << "choice: "; cin >> choice;

		switch (choice)
		{
		case 1: {
			sg.Display();
			break;
		}
		case 2: {
			Student s;
			s.Read();
			sg.Add(s);
			break;
		}
		case 3: {
			size_t index;
			cin.get();
			cout << "Якого студента вилучити із групи: "; cin >> index;
			sg.Delete(index);
			break;
		}
		case 4: {
			size_t size;
			cin.get();
			cout << "Скільки студентів добавити: "; cin >> size;
			for (size_t i = 0; i < size; i++) {
				sg.Add(makeStudent());

				cout << int(i / double(size - 1) * 100) << "% [";
				for (size_t j = 0; j < 10; j++)
				{
					auto t = i / double(size - 1);
					auto t1 = int(t * 100);
					if (t1 >= j*10)
						cout << '=';
					else
						cout << ' ';
				}
				cout << ']' << '\r';
			}
			cout << endl;

			break;
		}
		case 5: {
			FindMenu(sg);
			break;
		}
		case 6: {
			SortMenu(sg);
			break;
		}

		}

		cout << endl;
	} while (choice != 0);
}
