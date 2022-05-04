#include "Complex.h"

Complex complexInput() {
	std::cout << "¬ведите комплексное число: действительна€ часть и через пробел мнима€" << std::endl;
	double r, i;
	std::cin >> r >> i;
	Complex chislo = { r, i };
	return chislo;
}

void Complex::complexPrint() {
	if (this->imag > 0) {
		std::cout << this->real << '+' << imag << 'i' << std::endl;
	}
	else if (imag < 0) {
		std::cout << real << '-' << abs(imag) << 'i' << std::endl;
	}
	else {
		std::cout << real << std::endl;
	}
}

Complex Complex::complexAdd(Complex b) {
	Complex result{ real + b.real, imag + b.imag };
	return result;
}

Complex Complex::complexSubtract(Complex b) {
	Complex result{ real - b.real, imag - b.imag };
	return result;
}

Complex Complex::complexMultiply(Complex b) {
	Complex result{ real * b.real - imag * b.imag, real * b.imag + imag * b.real };
	return result;
}

double Complex::complexModule() {
	return (sqrt(imag*imag + real*real));
}

Complex Complex::complexConjugate() {
	return {real, imag*(-1)};
}


Complex Complex::complexDivide(Complex b) {
	Complex conj = this->complexMultiply(b.complexConjugate());
	return { conj.real / (b.real * b.real + b.imag * b.imag),conj.imag / (b.real * b.real + b.imag * b.imag) };
}

int numberFromFile() {
	std::ifstream fin("complex.txt");
	std::string a;
	getline(fin, a);
	fin.close();
	return stoi(a);
}

Complex complexStoc(std::string str) {
	int l = str.length(), i=0, minus1=1, minus2=1;
	std::string re, im;
	str.append(1, '*');
	if (str[0] == '-') {
		minus2 = -1;
		str.erase(i, 1);
	}
	while (str[i] != '+' and str[i] != '-') {
		re.append(1, str[i]);
		i++;
		if (str[i] == '-') {
			minus1 = -1;
		}
	}
	i++;
	while (str[i] != '*') {
		im.append(1, str[i]);
		i++;
	}
	return { minus2*stod(re), minus1*stod(im) };

}

