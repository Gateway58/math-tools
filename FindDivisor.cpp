#include "include.hpp" //https://github.com/Gateway58/math-tools/edit/main/include.hpp
//this tool should help with problems in which you have to 
// find (a) number(s) with specific divisors 
//for instance naboj 23.04.2021 Problem 6
// | https://math.naboj.org/archive/problems/pdf/math/2021_en_sol.pdf | 
void dostuff(int& mini);
void dostuffthesequal();  
using namespace std; 
int minimum = 0; //minimum to check enter here your minimum you want to check 
int maximum = 100;  //the absolute maximum of a 32-bit integer is 2,147,483,647 enter here your maximum you want to check 
vector<int>check = {2, 3}; //what divisors of the numbers enter here what divisors they should have seperat them through a , {if you wanna have 3; 6; 8; 100; then
// enter {3, 6, 8, 100}; decimals aren't possible yet. 
int main()
{
    dostuff(minimum); 
    for (minimum; minimum < maximum; minimum++)
    {
    /*if (minimum % check[0] == 0 && minimum % check[1] == 0 && minimum % check[3] == 0 )
    {
        cout << minimum <<endl; 
    }
    */
   //!High Warning this is very time intensive and can lead to a loss of time. If you don't have 
   //very much numbers to prove, you can rely on this and be fine, but otherwise 
   //comment the line below ,uncomment the if statement and customize it to your preference
   dostuffthesequal(); 
    
   
        
    }
    return 0; 
}
void dostuff(int& mini)
{
    if (mini == 0 )
    {
        mini = 1; 
    }
    
}
void dostuffthesequal()
{
    switch (check.size())
    {
    case 1:
    if (minimum % check[0] == 0)
    {
        cout << minimum << endl; 
    }
    break; 
    case 2:
    if (minimum % check[0] == 0 && minimum % check[1] == 0 )
    {
        cout << minimum << endl; 
    }
    break; 
    case 3:
    if (minimum % check[0] == 0 && minimum % check[1] == 0 && minimum % check[2] == 0)
    {
        cout << minimum << endl; 
    }
    break; 
    case 4:
    if (minimum % check[0] == 0 && minimum % check[1] == 0 && minimum % check[2] == 0 && minimum % check[3] == 0)
    {
        cout << minimum << endl; 
    }
    break; 
    case 5:
    if (minimum % check[0] == 0 && minimum % check[1] == 0 && minimum % check[2] == 0 && minimum % check[3] == 0 && minimum % check[4] == 0)
    {
        cout << minimum << endl; 
    }
    break; 
    case 6:
    if (minimum % check[0] == 0 && minimum % check[1] == 0 && minimum % check[2] == 0 && minimum % check[3] == 0 && minimum % check[4] == 0 && minimum % check[5] == 0)
    {
        cout << minimum << endl; 
    }
    break; 
    case 7:
    if (minimum % check[0] == 0 && minimum % check[1] == 0 && minimum % check[2] == 0 && minimum % check[3] == 0 && minimum % check[4] == 0 && minimum % check[5] == 0 && minimum % check[6] == 0)
    {
        cout << minimum << endl; 
    }
    break; 
    case 8:
    if (minimum % check[0] == 0 && minimum % check[1] == 0 && minimum % check[2] == 0 && minimum % check[3] == 0 && minimum % check[4] == 0 && minimum % check[5] == 0 && minimum % check[6] == 0 && minimum % check[7] == 0)
    {
        cout << minimum << endl; 
    }
    break; 
    case 9:
    if (minimum % check[0] == 0 && minimum % check[1] == 0 && minimum % check[2] == 0 && minimum % check[3] == 0 && minimum % check[4] == 0 && minimum % check[5] == 0 && minimum % check[6] == 0 && minimum % check[7] == 0 && minimum %check[8] == 0 )
    {
        cout << minimum << endl; 
    }
    break; 
    case 10:
    if (minimum % check[0] == 0 && minimum % check[1] == 0 && minimum % check[2] == 0 && minimum % check[3] == 0 && minimum % check[4] == 0 && minimum % check[5] == 0 && minimum % check[6] == 0 && minimum % check[7] == 0 && minimum %check[8] == 0 && minimum %check[9] == 0)
    {
        cout << minimum << endl; 
    }
    break; 
    }
    //hey whats the name of this game, how do you play it and how long does it take 
    //bing bong baaaaayyyyy ohhhh 
    //and how many times is the game going to change aaaaaaaahhhhh 

}
