#include "include.hpp"
using namespace std; 
void check(); 
//a tool for problems like naboj 11.12.2020 problem 4
//https://math.naboj.org/archive/problems/pdf/math/2020_en_sol.pdf  
//change numbers up from here: 
int diff = 1;               //The difference 
double consecutive = 5;     //5 consecutive numbers 
double EndResult = 0.8;     //what should be number1/number2 (in Problem 4/5, you have to write it decimal)
int mincheck = 0;           //the minimum it should check 
int maxcheck = 10000;       // the maximum to check, so it checks all the numbers from 0 to 10000
//yeah don't change that stuff below
double a, b;                
int main()
{
    //I could delete this but i may add things later 
    check(); 
}
void check()
{
 for (mincheck; mincheck < maxcheck; mincheck++)
 { 
     a = mincheck ;  
     b = mincheck +diff;  
     for (int i = 1; i < consecutive; i++)
     {
         a = a*(mincheck+i); 
         b = b*(mincheck+i+1);   
     }

      if (a / b == EndResult)
     {
        cout <<"starting number for PlayerOne is: " <<  mincheck << endl; 
        cout <<"starting number for PlayerTwo is: " <<  mincheck+diff << endl; 
     }
    //  a =  mincheck*(mincheck+ 1)*(mincheck+ 2)*(mincheck+ 3)*(mincheck+ 4); 
     // b = (mincheck+ 1)*(mincheck+ 2)*(mincheck+ 3)*(mincheck+ 4)*(mincheck+5);
     
     
 }
 
}
/*Thank you for reading through I try somthing with recursive methods
which will be the complicatest thing i've done so far in my programing journey
because there will be NO explanation or guides 
so this may not come any time soon or at all, but I will try it at least 
But the next file I upload is probably somthing different, but if you want to know
on what "Big" im working on, here you go :)
*/
