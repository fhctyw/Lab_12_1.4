#include "Menu.h"
#include "MakeStudent.h"

char ShowSymol(bool b) {
	return b ? 'V' : 'X';
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

void SortMenuDescending(StudentGroup& sg, int _choise) {
	int choice;
	do {
		cout << "Виберіть за спаданням/зростанням" << endl;
		cout << "1. За спаданням" << endl;
		cout << "2. За зростанням" << endl;
		cout << "0. Назад" << endl;

		cout << "choice: "; cin >> choice;
		cin.get();

		switch (choice)
		{
		case 1: {
			sg.Sort(false, _choise);
			break;
		}
		case 2: {
			sg.Sort(true, _choise);
			break;
		}

		}

		cout << endl;

		if (choice == 1 || choice == 2) break;
	} while (choice != 0);
}

void SortMenu(StudentGroup& sg) {
	int choice, _choice = 0;
	bool f, s, t;
	f = s = t = false;
	do {
		cout << "Виберіть критерій сорутвання" << endl;
		cout << "1. За прізвищем та ім'ям   " << ShowSymol(f) << endl;
		cout << "2. За групою		   " << ShowSymol(s) << endl;
		cout << "3. За середньою оцінкою    " << ShowSymol(t) << endl;
		cout << "4. Далі" << endl;
		cout << "0. Назад" << endl;

		cout << "choice: "; cin >> choice;
		cin.get();

		switch (choice)
		{
		case 1: {
			f = true;
			_choice = choice;
			s = t = false;
			break;
		}
		case 2: {
			s = true;
			_choice = choice;
			f = t = false;
			break;
		}
		case 3: {
			t = true;
			_choice = choice;
			f = s = false;
			break;
		}
		case 4: {
			if (_choice == 1 || _choice == 2 || _choice == 3) {
				SortMenuDescending(sg, _choice);
			}
			break;
		}

		}

		cout << endl;
		if (choice == 4) break;
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
				sg.Add(makeStudentFromSample());

				cout << "[" << int(i / double(size - 1) * 100) << "%]" << "\b\b\b\b\b";
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
