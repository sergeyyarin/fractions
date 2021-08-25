#include "Fraction.h"

int main() {

    Fraction fraction3(1, 4);
    Fraction fraction4(12, 8);

    std::cout << fraction3.to_string() << " + " << fraction4.to_string() << std::endl;

    Fraction fraction5 = fraction3 + fraction4;
    std::cout << fraction5.to_string() << std::endl;
    std::cout << fraction5.to_decimal() << std::endl;

    std::cout << fraction3.to_string() << " - " << fraction4.to_string() << std::endl;

    Fraction fraction6 = fraction3 - fraction4;
    std::cout << fraction6.to_string() << std::endl;
    std::cout << fraction6.to_decimal() << std::endl;

    return 0;
}
