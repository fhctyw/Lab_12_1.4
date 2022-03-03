#include "Menu.h"
#include "MakeStudent.h"

char ShowSymol(bool b) {
	return b ? 'V' : 'X';
}

void FindMenu(const StudentGroup& sg)
{
	int choice;
	do {
		cout << "������� ������� ������" << endl;
		cout << "1. �� �������� �� ��'��" << endl;
		cout << "2. �� ������" << endl;
		cout << "3. �� ��������� �������" << endl;
		cout << "0. �����" << endl;

		cout << "choice: "; cin >> choice;
		cin.get();

		switch (choice)
		{
		case 1: {
			string name;
			cout << "������ ������� �� ��'�: ";
			getline(cin, name);
			auto i = sg.FindIndexByName(name);
			if (i == -1)
				cout << "�������� �� ��������" << endl;
			else
				cout << "[" << sg.getStudent(i).toString() << "]" << endl;
			break;
		}
		case 2: {
			string group;
			cout << "������ �����: ";
			getline(cin, group);
			auto i = sg.FindIndexByGroup(group);
			if (i == -1)
				cout << "�������� �� ��������" << endl;
			else
				cout << "[" << sg.getStudent(i).toString() << "]" << endl;
			break;
		}
		case 3: {
			double avg_mark;
			cout << "������ ������� ���: ";
			cin >> avg_mark;
			auto i = sg.FindIndexByAvgMark(avg_mark);
			if (i == -1)
				cout << "�������� �� ��������" << endl;
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
		cout << "������� �� ���������/����������" << endl;
		cout << "1. �� ���������" << endl;
		cout << "2. �� ����������" << endl;
		cout << "0. �����" << endl;

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
		cout << "������� ������� ����������" << endl;
		cout << "1. �� �������� �� ��'��   " << ShowSymol(f) << endl;
		cout << "2. �� ������		   " << ShowSymol(s) << endl;
		cout << "3. �� ��������� �������    " << ShowSymol(t) << endl;
		cout << "4. ���" << endl;
		cout << "0. �����" << endl;

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
	cout << "���� ����� \"����������� �����\"" << endl;
	int choice;
	do {
		cout << "1. ³��������� ��������" << endl;
		cout << "2. �������� �������� � �����" << endl;
		cout << "3. �������� �������� �� �����" << endl;
		cout << "4. �������� n-������� ���������� ��������" << endl;
		cout << "5. ������" << endl;
		cout << "6. ���������" << endl;
		cout << "0. �����" << endl;


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
			cout << "����� �������� �������� �� �����: "; cin >> index;
			sg.Delete(index);
			break;
		}
		case 4: {
			size_t size;
			cin.get();
			cout << "������ �������� ��������: "; cin >> size;
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
