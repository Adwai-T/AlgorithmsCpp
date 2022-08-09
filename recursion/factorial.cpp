#include <iostream>

using namespace std;

//calculate factorial for a given number +ve number.
int factorial(int num)
{
  if(num <= 1) return 1; //base case

  else return num*factorial(num-1);
}
 
int main()
{
  cout << "Start" << endl;

  int fact1 = factorial(1);
  cout << "Factotial 1 = " << fact1 << endl;

  int fact0 = factorial(0);
  cout << "Factotial 0 = " << fact0 << endl; 

  int fact10 = factorial(10);
  cout << "Factotial 10 = " << fact10 << endl; 

  cout << "End" << endl;
}

// Memoization can greatly increase the speed of the algorithm.