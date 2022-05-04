#include "Complex.h"

int main()
{
    setlocale(0, "");
    Complex num1, num2;
    num1=complexInput();
    num2=complexInput();
    num1.complexPrint();
    num2.complexPrint();
    std::cout << "Введите операцию (+, -, *, /, module) " << std::endl << "Чтобы перейти ко второму заданию напечатайте '2' \n";
    std::string operation;
    std::cin >> operation;
    while (operation != "2") {
        if (operation == "+") {
            num1.complexAdd(num2).complexPrint();
            std::cin >> operation;
            continue;
        }
        else if (operation == "-") {
            num1.complexSubtract(num2).complexPrint();
            std::cin >> operation;
            continue;
        }
        else if (operation == "*") {
            num1.complexMultiply(num2).complexPrint();
            std::cin >> operation;
            continue;
        }
        else if (operation == "/") {
            num1.complexDivide(num2).complexPrint();
            std::cin >> operation;
            continue;
        }
        else if (operation == "module") {
            std::cout << "Модуль первого числа: " << num1.complexModule() << "\n";
            std::cout << "Модуль второго числа: " << num2.complexModule() << "\n";
            std::cin >> operation;
            continue;
        }
        else {
            std::cout << "Введена неверная операция";
            std::cin >> operation;
            continue;
        }
    }
    std::cout << "\nNumber 2 (см. файл complex.txt)\n";

    int n = numberFromFile();
    std::cout << n << std::endl;
    
    std::ifstream fin("complex.txt");
    std::string a;
    std::vector <Complex> masComplex(n);
    fin >> a;
    for (int i = 0; i < n; i++) {
        fin >> a;
        masComplex[i] = complexStoc(a);
    }

    int maxM = 0;
    Complex maxC, z;

    for (int i = 0; i < n; i++) {
        if (masComplex[i].complexModule() > maxM) {
            maxC = masComplex[i];
            maxM = masComplex[i].complexModule();
        }
    }
    maxC.complexPrint();
    std::cout << maxM;
    return 0;
}