#include <bits/stdc++.h>
using namespace std;

class Person
{
private:
  string name, class_name;
  int age;

public:
  Person()
  {
    this->name = "";
    this->class_name = "";
    this->age = 0;
  }
  Person(string name, string class_name, int age)
  {
    this->name = name;
    this->class_name = class_name;
    this->age = age;
  }
  friend ostream &operator<<(ostream &os, const Person &t)
  {
    os << "Name: " << t.name << endl;
    os << "Class: " << t.class_name << endl;
    os << "Age: " << t.age << endl;
    return os;
  }
  friend istream &operator>>(istream &is, Person &t)
  {
    cin.ignore();
    cout << "Enter name: ";
    getline(is, t.name, '\n');
    cout << "Enter class: ";
    is >> t.class_name;
    cout << "Enter age: ";
    is >> t.age;
    return is;
  }
  string get_name()
  {
    return this->name;
  }
  int get_age()
  {
    return this->age;
  }
};

int num_of_students = 0;
int num_of_teachers = 0;
vector<Person> students;
vector<Person> teachers;
vector<Person> oldest_students;
void menu()
{
  cout << "1. Add student" << endl;
  cout << "2. Add teacher" << endl;
  cout << "3. Sort by name A-Z" << endl;
  cout << "4. Sort by name Z-A" << endl;
  cout << "5. The 3 oldest students" << endl;
  cout << "6. Show student" << endl;
  cout << "7. Show teacher" << endl;
  cout << "8. Exit" << endl;
}

int main()
{
  int choice, choice1;
  do
  {
    menu();
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "Number of students: " << endl;
      cin >> num_of_students;
      for (int i = 0; i < num_of_students; i++)
      {
        Person p;
        cout << "Student " << i + 1 << endl;
        cin >> p;
        students.push_back(p);
      }
      break;
    case 2:
      cout << "Number of teachers: " << endl;
      cin >> num_of_teachers;
      for (int i = 0; i < num_of_teachers; i++)
      {
        Person p;
        cout << "Teacher " << i + 1 << endl;
        cin >> p;
        teachers.push_back(p);
      }
      break;
    case 3:
      cout << endl;
      cout << "1. Teachers" << endl;
      cout << "2. Students" << endl;
      cout << "Enter your choice: ";
      cin >> choice1;
      if (choice1 == 1)
      {
        sort(teachers.begin(), teachers.end(), [](Person a, Person b)
             { return a.get_name() < b.get_name(); });
        cout << endl
             << "Teachers sorted by name A-Z" << endl;
        for (int i = 0; i < num_of_teachers; i++)
        {
          cout << teachers[i] << " ";
        }
      }
      else
      {
        sort(students.begin(), students.end(), [](Person a, Person b)
             { return a.get_name() < b.get_name(); });
        cout << endl
             << "Students sorted by name A-Z" << endl;
        for (int i = 0; i < num_of_students; i++)
        {
          cout << students[i] << " ";
        }
      }
      break;
    case 4:
      cout << endl;
      cout << "1. Teachers" << endl;
      cout << "2. Students" << endl;
      cout << "Enter your choice: ";
      cin >> choice1;
      if (choice1 == 1)
      {
        sort(teachers.begin(), teachers.end(), [](Person a, Person b)
             { return a.get_name() > b.get_name(); });
        cout << endl
             << "Teachers sorted by name Z-A" << endl;
        for (int i = 0; i < num_of_teachers; i++)
        {
          cout << teachers[i] << " ";
        }
      }
      else
      {
        sort(students.begin(), students.end(), [](Person a, Person b)
             { return a.get_name() > b.get_name(); });
        cout << endl
             << "Students sorted by name Z-A" << endl;
        for (int i = 0; i < num_of_students; i++)
        {
          cout << students[i] << " ";
        }
      }
      break;
    case 5:
      oldest_students = students;
      sort(oldest_students.begin(), oldest_students.end(), [](Person a, Person b)
           { return a.get_age() > b.get_age(); });
      cout << "The 3 oldest students" << endl;
      for (int i = 0; i < 3; i++)
      {
        cout << oldest_students[i] << " ";
      }
      break;
    case 6:
      cout << endl
           << "List of student:" << endl;
      for (int i = 0; i < num_of_students; i++)
      {
        cout << students[i] << " ";
      }
      break;
    case 7:
      cout << endl
           << "List of teacher:" << endl;
      for (int i = 0; i < num_of_teachers; i++)
      {
        cout << teachers[i] << " ";
      }
      break;
    default:
      cout << "Wrong choice" << endl;
      break;
    }
  } while (choice != 8);
}