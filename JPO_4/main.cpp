#include "ShapeContainer.h"
#include "BST.h"
#include "BazaStudentow.h"

int main() {
	setlocale(LC_ALL, "");
	bool mainOk = 0;
	short int n;
	do {
		std::cin >> n;
		switch (n) {
		case 1: {
			std::cout << "Zadanie 1" << std::endl;
			ShapeContainer container;
			std::vector<Shape*> greaterVecor;
			bool ok = 0;
			short int choise;

			do {
				std::cout << "Wybierz:\n";
				std::cout << "1. Kwadraty\n";
				std::cout << "2. Prostokąt\n";
				std::cout << "3. Koło\n";
				std::cout << "4. Elipsy\n";
				std::cout << "5. Żeby wyjść\n";
				std::cin >> choise;

				switch (choise)
				{
				case 1: {
					int howMany;
					std::cout << "Ile? ";
					std::cin >> howMany;

					for (int i = 0; i < howMany; ++i) {
						std::string name;
						double side;
						std::cout << "Podaj nazwę i dłuość boku w " << i + 1 << " kwadracie: ";
						std::cin >> name >> side;
						Shape* shapePtr = new Square(name, side);
						container.add(shapePtr);
					}

					std::cout << "Lista wszytskich figór i ich objętości: \n";
					container.displayAll();
					std::cout << "Suma wszystkich pół to: " << round(container.totalArea()) << std::endl;

					double val;
					std::cout << "Podaj wartość graniczną i wświetlą się tylko elementy z polem większym niż podana wartość: ";
					std::cin >> val;
					greaterVecor = container.getGreaterThan(val);
					for (auto& shape : greaterVecor) {
						std::cout << shape->getName() << " " << shape->area() << " ";
					}
					std::cout << std::endl;

					break;
				}
				case 2: {
					int howMany;
					std::cout << "Ile? ";
					std::cin >> howMany;

					for (int i = 0; i < howMany; ++i) {
						std::string name;
						double width;
						double height;
						std::cout << "Podaj nazwę i szerokość i wysokość boków w " << i + 1 << " prostokącie: ";
						std::cin >> name >> width >> height;
						Shape* shapePtr = new Rectangle(name, width, height);
						container.add(shapePtr);
					}

					std::cout << "Lista wszytskich figór i ich objętości: \n";
					container.displayAll();
					std::cout << "Suma wszystkich pół to: " << round(container.totalArea()) << std::endl;

					double val;
					std::cout << "Podaj wartość graniczną i wświetlą się tylko elementy z polem większym niż podana wartość: ";
					std::cin >> val;
					greaterVecor = container.getGreaterThan(val);
					for (auto& shape : greaterVecor) {
						std::cout << shape->getName() << " " << shape->area() << " ";
					}
					std::cout << std::endl;

					break;
				}
				case 3: {
					int howMany;
					std::cout << "Ile? ";
					std::cin >> howMany;

					for (int i = 0; i < howMany; ++i) {
						std::string name;
						double radius;
						std::cout << "Podaj nazwę i dłuość promienia w " << i + 1 << " kole: ";
						std::cin >> name >> radius;
						Shape* shapePtr = new Circle(name, radius);
						container.add(shapePtr);
					}

					std::cout << "Lista wszytskich figór i ich objętości: \n";
					container.displayAll();
					std::cout << "Suma wszystkich pół to: " << round(container.totalArea()) << std::endl;

					double val;
					std::cout << "Podaj wartość graniczną i wświetlą się tylko elementy z polem większym niż podana wartość: ";
					std::cin >> val;
					greaterVecor = container.getGreaterThan(val);
					for (auto& shape : greaterVecor) {
						std::cout << shape->getName() << " " << shape->area() << " ";
					}
					std::cout << std::endl;

					break;
				}
				case 4: {
					int howMany;
					std::cout << "Ile? ";
					std::cin >> howMany;

					for (int i = 0; i < howMany; ++i) {
						std::string name;
						double diagonalA;
						double diagonalB;
						std::cout << "Podaj nazwę i dwie przekątne w " << i + 1 << " elipsie: ";
						std::cin >> name >> diagonalA >> diagonalB;
						Shape* shapePtr = new Ellipse(name, diagonalA, diagonalB);
						container.add(shapePtr);
					}

					std::cout << "Lista wszytskich figór i ich objętości: \n";
					container.displayAll();
					std::cout << "Suma wszystkich pół to: " << round(container.totalArea()) << std::endl;

					double val;
					std::cout << "Podaj wartość graniczną i wświetlą się tylko elementy z polem większym niż podana wartość: ";
					std::cin >> val;
					greaterVecor = container.getGreaterThan(val);
					for (auto& shape : greaterVecor) {
						std::cout << shape->getName() << " " << shape->area() << " ";
					}
					std::cout << std::endl;

					break;
				}
				case 5: {
					ok = 1;
					break;
				}
				default:
					std::cout << "Wrong input data.\n";
					ok = 1;
					break;
				}

			} while (not(ok));
			break;
		}
		case 2: {
			
			break;
		}
		case 3: {
			
			break;
		}
		case 4: {
			
			break;
		}
		case 5: {
			
			break;
		}
		default: {
			mainOk = 1;
			break;
		}
		}
	} while (!mainOk);
	
	return 1;
}
