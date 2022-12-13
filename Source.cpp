#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <vector>
using namespace std;

class Student {

public:
	Student() {

	}

	Student(string n, string sn) {
		name = n;
		surname = sn;
	}

	friend ostream& operator << (ostream& os, Student& st) {
		os << setw(10) << st.name << setw(15) << st.surname << setw(5) << st.avg;
		return os;
	}

	void setAvg() {
		avg = (rand()%12+1)+ (rand()% 100 / 100.0);
	}

	double getAvg() {
		return avg;
	}

//private:
	string name;
	string surname;
	int* mark;
	double avg;
};

int main() {
	srand(time(NULL));

	vector <Student> students;

	Student st1("s1", "st_surname1");
	Student st2("s2", "st_surname2");
	Student st3("s3", "st_surname3");
	Student st4("s4", "st_surname4");
	Student st5("s5", "st_surname5");

	Student st_all[4] = { st1,st2,st3,st4 };

	//for (int i = 0; i < 4; i++) {
	//	st_all[i].setAvg();
	//	students.push_back(st_all[i]);
	//	cout << st_all[i];
	//}

	//fstream fs;
	//fs.open("Student.txt", ios::in);
	//if (!fs.fail()) {
	//	cout << "Error\n";
	//	}
	//else {
	//	ofstream fz;
	//	fz.open("Students.txt");
	//	for (auto it = students.begin(); it < students.end(); it++) // авто итератор
	//	{
	//		fz << *it;
	//	}
	//	fz.close();
	//}

	vector <Student> st_new;
	fstream is("Students.txt");
	for (string l; getline(is,l);)
	{
		Student tmp;
		is >> tmp.name >> tmp.surname >> tmp.avg;
		st_new.push_back(tmp);
	}
	is.close();

	for (int i = 0; i < st_new.size(); i++) {
		cout << st_new[i] << endl;
	}

	return 0;
}

//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <windows.h>
//#include <io.h>
//#include <stdio.h>
//#include <string>
//#include <vector>
//#include <iomanip>
//#include <fstream>
//using namespace std;
//
//class Student
//{
//private:
//	string name_;
//	string surname;
//	//int* marks;
//	double avg;
//public:
//	Student() {}
//
//	Student(string _name, string _surname)
//	{
//		name_ = _name;
//		surname = _surname;
//	}
//	Student(string _name, string _surname, double _avg)
//	{
//		name_ = _name;
//		surname = _surname;
//		avg = _avg;
//	}
//	friend ostream& operator<<(ostream& os, Student& st)
//	{
//		os << setw(10) << st.name_ << setw(18) << st.surname << setw(5) << st.avg;
//		return os;
//	}
//	void SetAvg()
//	{
//		avg = (rand() % 12 + 1) + (rand() % 100 / 100.0);
//	}
//	double GetAvg()
//	{
//		return avg;
//	}
//	friend void  Read_file(vector<Student>& v);
//
//};
//void Read_file(vector<Student>& v)
//{
//
//	ifstream fw;
//	fw.open("Students.txt");
//	if (!fw.is_open())
//	{
//		cout << "Error" << endl;
//	}
//	else
//	{
//		Student tmp;
//		while (fw >> tmp.name_ >> tmp.surname >> tmp.avg)
//		{
//			v.push_back(tmp);
//		}
//		fw.close();
//		for (int i = 0; i < v.size(); i++)
//		{
//			cout << v[i] << endl;
//		}
//	}
//
//}
//void main()
//{
//	srand(time(0));
//	vector <Student> students;
//
//	Student st1("s1", "st_surname_1");
//	Student st2("s2", "st_surname_2");
//	Student st3("s3", "st_surname_3");
//	Student st4("s4", "st_surname_4");
//	Student st_all[4] = { st1,st2,st3,st4 };
//	/*for (int i = 0; i < 4; i++)
//	{
//		st_all[i].SetAvg();
//		students.push_back(st_all[i]);
//		cout << st_all[i] << endl;
//	}*/
//
//	/*fstream fs;
//	fs.open("Students.txt", ios::in);
//	if (!fs.fail())
//	{
//		cout << "Error" << endl;
//	}*/
//
//	/*ofstream fz;
//	fz.open("Students.txt");
//	for (auto it = students.begin(); it != students.end(); it++)
//	{
//		fz << *it;
//	}
//	fz.close();*/
//
//
//	vector <Student> st_new;
//
//	Read_file(st_new);
//
//}