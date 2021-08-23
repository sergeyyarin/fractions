#include "Fraction.h"

int main() {
    Fraction fraction1;
    std::cout << fraction1.to_string() << std::endl;
    std::cout << fraction1.to_decimal() << std::endl;

    Fraction fraction2(4);
    std::cout << fraction2.to_string() << std::endl;
    std::cout << fraction2.to_decimal() << std::endl;

    Fraction fraction3(1, 4);
    std::cout << fraction3.to_string() << std::endl;
    std::cout << fraction3.to_decimal() << std::endl;

    return 0;
}
