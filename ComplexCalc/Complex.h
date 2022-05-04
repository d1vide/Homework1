#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

 struct Complex {
	double real;
	double imag;


	void complexPrint();
	Complex complexAdd(Complex b);
	Complex complexSubtract(Complex b);
	Complex complexMultiply(Complex b);
	double complexModule();
	Complex complexConjugate();
	Complex complexDivide(Complex b);
} ;



Complex complexInput();
int numberFromFile();
Complex complexStoc(std::string);


#endif 

