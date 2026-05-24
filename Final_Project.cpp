#include<iostream>
#include<string>
using namespace std;

struct Student {
	string name;
	string rollNumber;
	float marks;
};

void add(Student* &stu, int students)
{
	for (int i = 0; i < students; i++)
	{
		cout << "\n---------------------------------\n";
		cout << "	Student " << i + 1 << " Details \n";
		cout << "---------------------------------\n";
		cin.ignore();
		cout << "Name		: ";
		getline(cin, stu[i].name);
		cout << "Roll Number	: ";
		getline(cin, stu[i].rollNumber);
		cout << "Marks		: ";
		do
		{
			while (!(cin >> stu[i].marks))
			{
				cout << "Invalid input! Please enter a valid integer: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if (stu[i].marks < 0)
			{
				cout << "Numbers Can't be less than zero!";
			}
		} while (stu[i].marks < 0);
	}
}

void display(Student* &stu, int students)
{
	for (int i = 0; i < students; i++)
	{
		cout << "---------------------------------\n";
		cout << "	  Student " << i + 1 << endl;
		cout << "---------------------------------\n";
		cout << "Name		: " << stu[i].name << endl;
		cout << "Roll Number	: " << stu[i].rollNumber << endl;
		cout << "Marks		: " << stu[i].marks << endl;
		cout << "---------------------------------\n\n";
	}
}

void update(Student*& stu, int students)
{
	if (stu == nullptr || students == 0)
	{
		cout << "No Student Record Found!" << endl;
		return;
	}
	int choice;
	bool found = false;

	cout << "\nUpdate By:" << endl;
	cout << "1. Name" << endl;
	cout << "2. Roll Number" << endl;
	cout << "Enter Choice: ";
	cin >> choice;

	cin.ignore();

	if (choice == 1)
	{
		string name;
		cout << "Enter Student Name: ";
		getline(cin, name);
		for (int i = 0; i < students; i++)
		{
			if (stu[i].name == name)
			{
				found = true;
				cout << "\nEnter New Name: ";
				getline(cin, stu[i].name);
				cout << "Enter New Roll Number: ";
				getline(cin, stu[i].rollNumber);
				cout << "Enter New Marks: ";
				do
				{
					while (!(cin >> stu[i].marks))
					{
						cout << "Invalid input! Please enter a valid integer: ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					if (stu[i].marks < 0)
					{
						cout << "Numbers Can't be less than zero!";
					}
				} while (stu[i].marks < 0);
				cout << "\nRecord Updated Successfully!" << endl;
				break;
			}
		}
		if (!found)
		{
			cout << "Student Name Not Found!" << endl;
		}
	}
	else if (choice == 2)
	{
		string roll;

		cout << "Enter Roll Number: ";
		getline(cin, roll);
		for (int i = 0; i < students; i++)
		{
			if (stu[i].rollNumber == roll)
			{
				found = true;
				cout << "\nEnter New Name: ";
				getline(cin, stu[i].name);
				cout << "Enter New Roll Number: ";
				getline(cin, stu[i].rollNumber);
				cout << "Enter New Marks: ";
				do
				{
					while (!(cin >> stu[i].marks))
					{
						cout << "Invalid input! Please enter a valid integer: ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					if (stu[i].marks < 0)
					{
						cout << "Numbers Can't be less than zero!";
					}
				} while (stu[i].marks < 0);
				cout << "\nRecord Updated Successfully!" << endl;
				break;
			}
		}
		if (!found)
		{
			cout << "Roll Number Not Found!" << endl;
		}
	}
	else
	{
		cout << "Invalid Choice!\n";
	}
}

int main()
{
	cout << "====================================\n";
	cout << "  Student Record Management System  \n";
	cout << "====================================\n";

	int choice;
	int students = 0;
	Student* stu = nullptr;
	do
	{
		cout << "\n1. Add Students\n";
		cout << "2. Display Students\n";
		cout << "3. Update Students\n";
		cout << "4. Exit\n";
		cout << "Enter Choice: ";
		cin >> choice;

		if (choice == 1)
		{
			do
			{
				cout << "\nEnter Number Of Students: ";
				while (!(cin >> students)) 
				{
					cout << "Invalid input! Please enter a valid integer: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if (students < 0)
				{
					cout << "Error: Input can't be negative!" << endl;
				}
			} while (students < 0);
			stu = new Student[students];
			add(stu, students);
		}
		else if (choice == 2)
		{
			if (stu == nullptr)
			{
				cout << "No Student Record found!" << endl;
			}
			else
			{
				display(stu, students);
			}
		}
		else if (choice == 3)
		{
			update(stu, students);
		}
		else if (choice == 4)
		{
			cout << "Thanks for using this program! " << endl;
			break;
		}
		else
		{
			cout << "Invalid Choice!" << endl;
		}

	} while (choice != 4);

	system("pause");
	return 0;
}