#include <iostream>

class Complex {
	double re; // действительная часть
	double im; // ммнимая часть

public:
	Complex(double re, double im = 0);

	double getRe() const; // получение действительной части
	double getIm() const; // получение мнимой части

	Complex operator+(const Complex &x); // операция сложения двух комплексных чисел
	Complex operator-(const Complex &x); // операция вычитания двух комплексных чисел
	Complex operator*(const Complex &x); // операция умножения двух комплексных чисел

	void print(); // вывод значения числа на экран
};

Complex::Complex(double re, double im) {
	this->re = re;
	this->im = im;
}

double Complex::getRe() const {
	return re;
}

double Complex::getIm() const {
	return im;
}

Complex Complex::operator+(const Complex& x) {
	return Complex(re + x.getRe(), im + x.getIm());
}

Complex Complex::operator-(const Complex& x) {
	return Complex(re - x.getRe(), im - x.getIm());
}

Complex Complex::operator*(const Complex& x) {
	return Complex(re * x.getRe() - im * x.getIm(), re * x.getIm() + im * x.getRe());
}

void Complex::print() {
	if (re != 0)
		std::cout << re;

	if (im != 0)
		std::cout << (im < 0 || re == 0 ? "" : "+") << im << "i";

	if (re == 0 && im == 0)
		std::cout << 0; 

	std::cout << std::endl;
}

void menu() {
	int value;

	while (1) {
		std::cout << std::endl << "What do you want to do?" << std::endl;
		std::cout << "1. Add two complex numbers (a + b)" << std::endl;
		std::cout << "2. Sub two complex numbers (a - b)" << std::endl;
		std::cout << "3. Mult two complex numbers (a * b)" << std::endl;
		std::cout << "4: Exit" << std::endl;

		std::cin >> value;

		while (value < 1 || value > 4) {
			std::cout << "Incorrect input. try again: ";
			std::cin >> value;
		}

		if (value == 4)
			break;

		double re, im;
		std::cout << "Enter real part of a: ";
		std::cin >> re;
		std::cout << "Enter imaginary part of a: ";
		std::cin >> im;

		Complex a(re, im);

		std::cout << "Enter real part of b: ";
		std::cin >> re;
		std::cout << "Enter imaginary part of b: ";
		std::cin >> im;

		Complex b(re, im);
		Complex c(0);

		switch (value) {
			case 1:
				c = a + b;
				std::cout << "a + b = ";
				c.print();
				break;

			case 2:
				c = a - b;
				std::cout << "a - b = ";
				c.print();
				break;

			case 3:
				c = a * b;
				std::cout << "a * b = ";
				c.print();
				break;
		}
	}
}

int main() {
	menu();
}