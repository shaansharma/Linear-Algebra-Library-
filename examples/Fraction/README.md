#Class Fraction 

###Overview
The Fraction class is used by the library to store exact numbers in Vectors and Matrices. 
The class is meant to be a replacement for integers and inexact decimal numbers. The class overloads many c++ operators
thus allowing it to be used like an **int** or **double**. The [header file](../../master/fraction.h) contains all member functions 
and operator functions that the Fraction class supports. Additionally, you can look at the implementation [here](../../master/fraction.cc).

###Summary of Methods and Functions

| Method / Function  | Description |
| ------------- | ------------- |
| **bool** isWhole() | Returns true if and only if the Fraction a/b is a whole number|
| **void** reduce() | reduces the Fraction until it's numerator and denominator are co-prime|
|**Fraction** getAbsolute()| returns the absolute value of the Fraction |
|**Fraction** reciprocal()| if the Fraction is a/b, returns a new Fraction b/a. Throws an exception if reciprocal doesn't exist (i.e is 0)|
|**double** toDouble()| returns the division a/b |

Overriden operators include: =, +=, *=, -=, /=, ++, --, +, -, *, <, >, ==, !=, <=, and >=. See header file for more details.
