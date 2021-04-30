#include "include.hpp"
using namespace std; 
/*for problems like in kangaroo problem A5
I can't provide a link yet, because it's all german, so i have to translate it and build my own website
for the translation, that will be fun, so don't excpect to see much these next days, because i have to set 
it up and translate it so you can understand it, but please notice: the kangaroo test is 
much simpler than naboj and I think unlike in naboj (or at least this year) you can't
officially use calculators... Yeah, but i think problem solving self-made tools are fine xD.
*/
int quantity = 15; 
int TimesMore = 4;         //If you want to search like in the question, if not, keep it 0 
int quantity_already = 0; //If you want to search how many times more, if not keep 0  
int mincheck = 0; 
int maxcheck = 1000; 

int main()
{
    if (TimesMore != NULL)
    {
        for (mincheck;  mincheck < maxcheck; mincheck++)
    {
        int multiply = mincheck*TimesMore; 
        int whole = multiply + mincheck;
        if (whole ==  quantity)
        {
            cout << mincheck << endl;
           
             
        }
       
    }
        return 0;  
    }
     for (mincheck;  mincheck < maxcheck; mincheck++)
    {
        int multiply = quantity_already*mincheck; 
        int whole = multiply + quantity_already;
        if (whole ==  quantity)
        {
            cout << mincheck << endl; 
            
            
        }
       
    }
    return 0; 
    
}
