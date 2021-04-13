#include "ShapeContainer.h"

// =================== Shape ===================

Shape::Shape(std::string name) {
	this->name = name;
	std::cout << "ctor Shape" << std::endl;
}

Shape::~Shape() {
	std::cout << "dtor Shape" << std::endl;
}

// =================== Rectangle ===================

Rectangle::Rectangle(std::string name, double width, double height) : Shape(name) {
	this->width = width;
	this->height = height;

	std::cout << "ctor Rectangle " << name << std::endl;
}

Rectangle::~Rectangle() {
	std::cout << "dtor Rectangle " << name << std::endl;
}

double Rectangle::area() {
	return width * height;
}

double Rectangle::perimeter() {
	return (2 * width) + (2 * height);
}

// =================== Square ===================

Square::Square(std::string name, double side) : Shape(name) {
	this->side = side;

	std::cout << "ctor Square " << name << std::endl;
}

Square::~Square() {
	std::cout << "dtor Rectangle " << name << std::endl;
}

double Square::area() {
	return pow(side, 2);
}

double Square::perimeter() {
	return 4 * side;
}

// =================== Circle ===================

Circle::Circle(std::string name, double radius) : Shape(name){
	this->radius = radius;

	std::cout << "ctor Cricle " << name << std::endl;
}

Circle::~Circle() {
	std::cout << "dtor Cricle " << name << std::endl;
}

double Circle::area() {
	return M_PI * pow(radius, 2);
}

double Circle::perimeter() {
	return 2 * M_PI * radius;
}


// =================== Ellipse ===================

Ellipse::Ellipse(std::string name, double diagonalA, double diagonalB) : Shape(name) {
	this->diagonalA = diagonalA;
	this->diagonalB = diagonalB;

	std::cout << "ctor Ellipse " << name << std::endl;
}

Ellipse::~Ellipse() {
	std::cout << "dtor Ellipse " << name << std::endl;
}

double Ellipse::area() {
	return M_PI * diagonalA * diagonalB;
}

double Ellipse::perimeter() {
	double ans = 0.f;
	ans = M_PI* (1.5 * (diagonalA + diagonalB - sqrt(diagonalA * diagonalB)));
	return ans;
}

// =================== Ellipse ===================

ShapeContainer::ShapeContainer() {
	std::cout << "ctor ShapeContainer " << std::endl;
}

ShapeContainer::~ShapeContainer() {
	std::cout << "dtor ShapeContainer " << std::endl;
}

void ShapeContainer::add(Shape* myShape) {
	shapes.push_back(myShape);
}

void ShapeContainer::displayAll() const {
	int i = 1;
	for (auto& shape : shapes) {
		std::cout << i <<". "<<shape->getName() << " " << shape->perimeter() << " ";
		++i;
	}
	std::cout << std::endl;
}

double ShapeContainer::totalArea() const {
	double totalAreas = 0.f;
	for (auto& shape : shapes) {
		totalAreas += shape->area();
	}
	return totalAreas;
}

std::vector<Shape*> ShapeContainer::getGreaterThan(double area) {
	std::vector<Shape*> greaterVector;
	for (auto& shape : shapes) {
		if (shape->area() > area) {
			greaterVector.push_back(shape);
		}
	}
	return greaterVector;
}