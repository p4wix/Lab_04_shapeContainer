#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class BazaStudentow;

class Student {
	std::string p_name;
	std::string p_surname;
	int p_index;

public:
	Student();
	Student(std::string, std::string, int);
	~Student();

	inline std::string getName() { return p_name; };
	inline std::string getSurname() { return p_surname; };
	inline int getIndex() { return p_index; };

	void set();
	void print();

	friend std::ostream& operator<<(std::ostream& out, Student& student);
};

// ================= BAZA =================

class BazaStudentow {

public:
	std::vector<Student> bazaStudentow;
	BazaStudentow();
	~BazaStudentow();

	void add(Student student);
	void print();
	void searchCurrentStudent(int index);
	void deleteCurrentStudent(int index);
	void saveToFile();
	void readFromFile();
	void clear();

	friend class Student;
};

// ================= Zwykle funkcje =================

Student load();
std::ostream& operator<<(std::ostream& out, Student& student);
