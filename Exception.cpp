// Exception Lecture
// --------------------------------------------

#include <iostream>
#include <stdexcept>

int divideNumbers(int dividend, int divisor) {
    if (divisor == 0) {
        throw std::runtime_error("Division by zero is not allowed");
    }

    return dividend / divisor;
}

int main() {
    int dividend, divisor;

    std::cout << "Enter the dividend: ";
    std::cin >> dividend;

    std::cout << "Enter the divisor: ";
    std::cin >> divisor;

    try {
        int result = divideNumbers(dividend, divisor);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& ex) {
        std::cout << "Exception occurred: " << ex.what() << std::endl;
    }

    return 0;
}
