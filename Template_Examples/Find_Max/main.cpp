//
//  main.cpp
//  function_template
//
//  Created by Brian R. Hall on 3/23/14.
//  Copyright (c) 2014 Brian R. Hall. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

template <class T>
T square(T number){
   return number * number;
}

template <class T1, class T2, class T3>
void echoAndReverse(T1 a1, T2 a2, T3 a3){
   cout << "Original order is: " << a1 << " " << a2 << " " << a3 << endl;
   cout << "Reverse order is: " << a3 << " " << a2 << " " << a1 << endl;
}

int main()
{

   cout << setprecision(5);
   
   //Get an integer and compute its square
   cout << "Enter an integer: ";
   int iValue;
   cin >> iValue;
   
   //Compiler creates int square(int)
   cout << "The square is: " << square(iValue);
   
   //Get a double and compute its square
   cout << "\nEnter a double: ";
   double dValue;
   cin >> dValue;
   
   //Compiler creates double square(double)
   cout << "The square is: " << square(dValue) << endl;
   
   //Multiple Types
   echoAndReverse("Computer", 'A', 18);
   echoAndReverse("One", 4, "All");
   
   
   return 0;
}

