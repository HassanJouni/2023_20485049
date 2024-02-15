//begin - calc.cpp -------

#include <iostream>
#include <sstream>
#include "adder.h" // Include the header file where add function is declared

int main(int argc, char* argv[]) {
    int a, b, c;

    if (argc != 3) return 1;

    std::string sa(argv[1]);
    std::string sb(argv[2]);

    std::stringstream ssa(sa);
    std::stringstream ssb(sb); // Corrected the variable name from 'sa' to 'sb'

    ssa >> a;
    ssb >> b;

    c = add(a, b); // Call the add function
    std::cout << c;

    return 0;
}

//end - calc.cpp -------