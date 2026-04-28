#include <iostream>

// "extern" tells the compiler that the 'average' function 
// is defined in another file (output.o)
extern "C" {
    double average(double x, double y);
}

int main() {
    double result = average(10.0, 20.0);
    std::cout << "The average of 10 and 20 is: " << result << std::endl;
    return 0;
}