#pragma once
#include <iostream>
#include <math.h>
#include <vector>

# define M_PI           3.14159265358979323846 /* pi */

// =================== Shape ===================

class Shape {
protected:
	//Variables
	std::string name;
public:
	//Constructors and destructors
	Shape(std::string);
	virtual ~Shape();

	//Virtual functions
	virtual double area() = 0;
	virtual double perimeter() = 0;
	
	//Functions
	std::string getName() const { return name; };
};

// =================== Rectangle ===================

class Rectangle : public Shape {
protected:
	//Variables
	double width;
	double height;
public:
	//Constructors and destructors
	Rectangle(std::string, double, double);
	virtual ~Rectangle();

	//Virtual functions
	virtual double area();
	virtual double perimeter();
};

// =================== Square ===================

class Square : public Shape {
protected:
	//Variables
	double side;
public:
	//Constructors and destructors
	Square(std::string, double);
	virtual ~Square();

	//Virtual functions
	virtual double area();
	virtual double perimeter();
};

// =================== Cricle ===================

class Circle : public Shape {
protected:
	//Variables
	double radius;
public:
	//Constructors and destructors
	Circle(std::string, double);
	virtual ~Circle();

	//Virtual functions
	virtual double area();
	virtual double perimeter();
};

// =================== Ellipse ===================

class Ellipse : public Shape {
protected:
	//Variables
	double diagonalA;
	double diagonalB;
public:
	//Constructors and destructors
	Ellipse(std::string, double, double);
	virtual ~Ellipse();

	//Virtual functions
	virtual double area();
	virtual double perimeter();
};

// =================== ShapeContainer ===================

class ShapeContainer {
protected:
	//Variables
	std::vector<Shape*> shapes;
public:
	//Constructors and destructors
	ShapeContainer();
	~ShapeContainer();

	//Functions
	void add(Shape*);
	void displayAll() const;
	double totalArea() const;
	std::vector<Shape*> getGreaterThan(double area);
};

