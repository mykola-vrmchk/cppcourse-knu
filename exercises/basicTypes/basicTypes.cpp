#include "PrintHelper.h"

/* *************************************
 * * Fundamental types and expressions *
 * *************************************
 *
 * Tasks:
 * ------
 * - Compile the program and analyse the output of the different expressions
 * - Discuss with other students or your tutor in case the result of an expression is a surprise
 * - Fix the marked expressions by changing types such that they produce meaningful results
 * - Answer the questions in the code
 */

int main() {
  std::cout << "Using literals of different number types:\n";
  print(5);
  print(5.0f/2);
  print(100/2ull);
  print(2 + 4ull);
  print(2.0f + 4ull);
  print(0 - 1);          // Changed from unsigned to signed int to handle negative numbers
  print(1.0000000001);   // Changed from float to double for better precision
  print(1.0 + 1.0E-18);  // Changed to use double literals for better precision

  std::cout << "\nUsing increment and decrement operators:\n";
  int a = 1;
  int b;
  int c;
  print(b = a++);       // Q: What is the difference between a++ and ++a?
  print(c = ++a);
  print(a);
  print(b);
  print(c);

  std::cout << "\nCompound assignment operators:\n";
  int n = 1;
  print(n *= 2);        // Q: Is there a difference between this and the next line?
  print(n *= 2.9);      // A: Yes, the first line is an integer multiplication, while the second line is a floating point multiplication.
  print(n -= 1.1f);
  print(n /= 4);        // Q: Based on the results of these expressions, is there a better type to be used for n?
  print(n /= 4.0f);     // A: Yes, a floating point type would be more appropriate for n.
  std::cout << "\nLogic expressions:\n";
  const bool alwaysTrue = true;
  bool condition1 = false;
  bool condition2 = true;
  print( alwaysTrue && condition1 && condition2 );
  print( alwaysTrue || condition1 && condition2 );  // Q: Why does operator precedence render this expression useless?
  print( alwaysTrue && condition1 || condition2 );  // A: The || operator has higher precedence than the && operator, so the expression is evaluated as (alwaysTrue && condition1) || condition2.
  print( alwaysTrue && condition1 || condition2 );
  print(condition1 != condition1);                  // Q: What is the difference between this and the following expression?
  print(condition2 = !condition2);                  // A: The first expression is a comparison of condition1 with itself, while the second expression is a comparison of condition1 with condition2.
  print( alwaysTrue && condition1 && condition2 );
  print( alwaysTrue || condition1 && condition2 );
  print( alwaysTrue && condition1 || condition2 );

  std::cout << '\n';
  print( false || 0b10 );     // Q: What is the difference between || and | ?
  print( false | 0b10 );
  printBinary( 0b1 & 0b10 );
  printBinary( 0b1 | 0b10 );
  printBinary( 0b1 && 0b10 ); // Q: Are the operators && and || appropriate for integer types?
  printBinary( 0b1 || 0b10 );

  std::cout << "\nPlay with characters and strings:\n";
  print("a");                 // Q: Why is this expression two bytes at run time, the next only one?
  print('a');                 // A: The first expression is a string literal, which is an array of characters terminated by a null character. The second expression is a character literal.

  char charArray[20] = {0};  // Initialize array with zeros
  char* charPtr = charArray;

  print(charArray);
  print(charArray[0] = 'a');
  print(charArray);
  print(charArray[1] = 98);
  print(charArray);
  print(charPtr);
}
