#include "BazaStudentow.h"

Student::Student() {
	p_name = "";
	p_surname = "";
	p_index = -1;
}

Student::Student(std::string name, std::string surname, int index) {
	this->p_name = name;
	this->p_surname = surname;
	this->p_index = index;
}

Student::~Student() {

}

void Student::set() {
	std::cin >> p_name >> p_surname >> p_index;
}

void Student::print() {
	std::cout << getName() << " " << getSurname() << " " << getIndex() << " ";
}

// ================= BAZA =================

BazaStudentow::BazaStudentow() {

}

BazaStudentow::~BazaStudentow() {

}

void BazaStudentow::add(Student student) {
	bazaStudentow.push_back(student);
}

void BazaStudentow::print() {
	if (bazaStudentow.empty()) {
		std::cout << "Base is empty :(\n";
		return;
	}
	for (Student& s : bazaStudentow) {
		std::cout << s;
	}
	std::cout << std::endl;
}

void BazaStudentow::deleteCurrentStudent(int index) {
	int i = 0;
	for (auto& student : bazaStudentow) {
		if (student.getIndex() == index) {
			bazaStudentow.erase(bazaStudentow.begin() + i);
		}
		++i;
	}
}

void BazaStudentow::searchCurrentStudent(int index) {
	for (int i = 0; i < bazaStudentow.size(); ++i) {
		if (bazaStudentow[i].getIndex() == index) {
			std::cout << bazaStudentow[i] << std::endl;
		}
	}
}

void BazaStudentow::saveToFile() {
	std::ofstream base("baza.txt", std::ios::out);
	if (base.good()) {
		for (auto& i : bazaStudentow) {
			base << i << std::endl;
		}
	}
	else {
		std::cout << "FILE ERROR!\n";
	}
	base.close();
}

void BazaStudentow::readFromFile() {
	std::string line;
	std::ifstream base("baza.txt", std::ios::in);
	if (base.is_open()) {
		while (!base.eof()) {
			std::getline(base, line);
			std::cout << line << std::endl;
		}
	}
	else {
		std::cout << "FILE ERROR!\n";
	}
	base.close();
}

void BazaStudentow::clear() {
	bazaStudentow.clear();
}

// ================= Zwykle funkcje =================

Student load() {
	Student student;
	student.set();
	return student;
}

std::ostream& operator<<(std::ostream& out, Student& student) {
	out << student.getName() << " " << student.getSurname() << " " << student.getIndex() << " ";
	return out;
}