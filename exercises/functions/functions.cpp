/* Tasks:
 * 1. Check out Structs.h. It defines two structs that we will work with.
 *    FastToCopy
 *    SlowToCopy
 *    They are exactly what their name says, so let's try to avoid copying the latter.
 * 2. Using "printName()" as an example, write a function that prints the name of "SlowToCopy".
 *    Call it in main().
 * 3. Try passing by copy and passing by reference, see the difference.
 * 4. When passing by reference, ensure that your "printName" cannot inadvertently modify the original object.
 *    To test its const correctness, try adding something like
 *      argument.name = "other name";
 *    to your print function.
 *    Try both with and without const attributes in your print function's signature.
 */

#include "Structs.h" // The data structs we will work with

#include <iostream> // For printing

void printName(FastToCopy argument) {
    std::cout << argument.name << '\n';
}

// Pass by copy - will be slow due to copying
void printNameCopy(SlowToCopy argument) {
    std::cout << "Pass by copy: " << argument.name << '\n';
}

// Pass by reference - faster but can modify the original
void printNameRef(SlowToCopy& argument) {
    std::cout << "Pass by reference: " << argument.name << '\n';
    // Uncomment to see that we can modify the original:
    // argument.name = "other name";
}

// Pass by const reference - both fast and safe
void printNameConstRef(SlowToCopy const& argument) {
    std::cout << "Pass by const reference: " << argument.name << '\n';
    // This would cause a compilation error:
    // argument.name = "other name";
}

// Print first five characters of the name using const reference to avoid copies
void printFiveCharacters(SlowToCopy const& a) {
    std::cout << "First five characters: " << a.name.substr(0, 5) << '\n';
}

int main() {
    FastToCopy fast = {"Fast"};
    printName(fast);

    SlowToCopy slow = {"Slow"};
    
    // This will be slow (3 second delay):
    printNameCopy(slow);
    
    // These will be fast:
    printNameRef(slow);
    printNameConstRef(slow);

    // Print first five characters
    printFiveCharacters(slow);

    return 0;
}
