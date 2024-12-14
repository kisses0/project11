#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

    void reduce() {
        int min = (numerator < denominator ? numerator : denominator);
        if (min < 0) {
            min = -min;
        }

        for (int i = min; i > 1; --i) {
            if (numerator % i == 0 && denominator % i == 0) {
                numerator /= i;
                denominator /= i;
                break;
            }
        }

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (den == 0) {
            std::cout << "Помилка: знаменник не може бути нулем!" << std::endl;
            exit(1);
        }
        reduce();
    }

    void input() {
        std::cout << "Введіть чисельник: ";
        std::cin >> numerator;
        std::cout << "Введіть знаменник: ";
        std::cin >> denominator;
        if (denominator == 0) {
            std::cerr << "Помилка: знаменник не може бути нулем!" << std::endl;
            exit(1);
        }
        reduce();
    }

    void display() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }

    Fraction add(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction subtract(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction multiply(const Fraction& other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction divide(const Fraction& other) const {
        if (other.numerator == 0) {
            std::cerr << "Помилка: неможливо ділити на нуль!" << std::endl;
            exit(1);
        }
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Fraction(num, den);
    }
};

int main() {
    setlocale(LC_CTYPE, "ukr");
    Fraction f1, f2;
    std::cout << "Введіть перший дріб:" << std::endl;
    f1.input();
    std::cout << "Введіть другий дріб:" << std::endl;
    f2.input();

    std::cout << "Перший дріб: ";
    f1.display();
    std::cout << "Другий дріб: ";
    f2.display();

    Fraction result;
    result = f1.add(f2);
    std::cout << "Сума: ";
    result.display();

    result = f1.subtract(f2);
    std::cout << "Різниця: ";
    result.display();

    result = f1.multiply(f2);
    std::cout << "Добуток: ";
    result.display();

    result = f1.divide(f2);
    std::cout << "Частка: ";
    result.display();

    return 0;
}