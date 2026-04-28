#include <iostream>

// "extern" tells the compiler that the 'average' function 
// is defined in another file (output.o)
extern "C" {
    double average(double x, double y);
}

int main() {
    double result = average(20.0, 20.0);
    std::cout << "The average is: " << result << std::endl;
    return 0;
}