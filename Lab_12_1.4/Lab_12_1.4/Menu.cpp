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

void SortMenuDescending(StudentGroup& sg, int _choice) {
	int choice;
	do {
		cout << "������� �� ���������/����������" << endl;
		cout << "1. �� ���������" << endl;
		cout << "2. �� ����������" << endl;
		cout << "0. �����" << endl;

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
		cout << "������� ������� ����������" << endl
			<< "���������: 231" << endl
			<< "2 - ������" << endl
			<< "3 - ������" << endl
			<< "1 - �����" << endl;
		cout << "1. �� �������� �� ��'��" << endl;
		cout << "2. �� ������" << endl;
		cout << "3. �� ��������� �������" << endl;
		cout << "0. �����" << endl;

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
