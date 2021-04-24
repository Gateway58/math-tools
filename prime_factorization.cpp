#include "include.hpp"
using namespace std; 
void get_primes();  
/*credits to https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/ which provides 
the prime factorization method which i could code of course, but
it would cost me some time and it seems very good. 
The code from them is 
modified by me and only me in order to calculate the result of problems like 
*/
//Problem 2 naboj 11.12.2021 https://math.naboj.org/archive/problems/pdf/math/2020_en_sol.pdf
//And i really put thought into this, just to realize that you can just simply use the size of the 
//arrray xD.
int number = 10;
//Please only change to number above. 
vector<int>prime_numbers; 
int quantety; 
int main()
{
     get_primes();      
       int size = prime_numbers.size() +1; 

      if ((size-1) == 0)
      {
          cout << "ERROR, check your inputs (number)" << endl; 
          return 0; 
      }
    
    cout << size << endl; 
    return 0; 
}

void get_primes()
{
     while (number % 2 == 0) 
    { 
        prime_numbers.push_back(0);  
        number = number/2; 
    } 
  
    for (int i = 3; i <= sqrt(number); i = i + 2) 
    { 
        while (number % i == 0) 
        { 
            prime_numbers.push_back(0); 
            number = number/i; 
            
        } 
    } 
  
    if (number > 2) 
    {
       prime_numbers.push_back(number); 
    } 
}
