#include <iostream>
#include <math.h>
#include <fstab.h>
#include <fstream>
#include <ostream>
#include <sstream>
#include <condition_variable>
#include <cerrno>
#include <string>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
// Like in naboj  23.04.2021 Problem 3
// | https://math.naboj.org/archive/problems/pdf/math/2021_en_sol.pdf |
//or naboj        11.12.2021 Problem 3 again huh 
// | https://math.naboj.org/archive/problems/pdf/math/2020_en_sol.pdf |
using namespace std; 
int pluss, minuss, supersame; 
vector<double>participants = {23, 32}; 
vector<double>same = {0.25};
vector<double>super_same {}; 
/*Warning cpp and javascript (and probably others too) are really bad when it 
comes to get the ecaxt value of decimals like 0.1 becomes 0.1000000000000000056
what's that 56 lurking there? I don't know. 
however, since its just slightly  off and you still work with integers,
because calculating with 0.5 people would be really dark, it should still work
if you want the results like in naboj 11.12.2021 Problem 3, here's how you do it: 

vector<double>participants = {23, 32}; //23 and 32 people [order doesn't matter]
vector<double>same = {0.25}; //we have 1/4 which is this in decimal 
//IMPORTANT! Decimals always get points, so if you want 1,25 you have to write 1.25
vector<double>super_same {}; //LEAVE THIS EMPTY! Only if you want to calculate 
//something like naboj 23.04.2021 Problem 3 with the 3 Super children
*/ 
int main()
{
    bool super_is_used = true; 
 int issuperused = super_same.size(); 
 if (issuperused == 0)
 {
     super_is_used =  false; 
 }
 if (super_is_used) 
 {                   
    for (int i = 0; i <participants.size() ; i++ )
    {
       pluss += participants[i]; 
    }
    for (int i = 0; i < same.size(); i++)
    {
         minuss += -same[i]; 
    }
    for (int i = 0; i < super_same.size() ; i++)
    {
       supersame += super_same[i]; 
    }
      cout << pluss + minuss + supersame; 
    
 }
 else if (super_is_used == false){
    int a = participants.size(); 
    for (int i = 0; i < a; i++)
    {
     pluss += participants[i]; 
    }
    for (int i = 0; i < 10000000; i++)
    { 
       if (i + (i * same[0]) == pluss)
       {
         cout << i; 
       }
       
    }
    
    
 }
 else{
    cout << "error"; 

 }
 return 0; 
 //Thanks for reading through! 
}
