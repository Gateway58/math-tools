#include <include.h>
using namespace std; 
/*this is nothing special, but my math teacher mentioned it today 
and i tried to implement this in c++ just for fun yk what you usually do in math lessons. 
I want to make my own sort of console calculator which will be really bad, but will
be an awesome experience in programming because it should be very logical and should not
have many lines and I may use this code from here for it.
 However my top priority is the math tools, because its soooooo
easy to edit and add new ones.  
*/

int main(){
    int NumberYouWantToFacult = 6; 
    int storage =1; 

    for (NumberYouWantToFacult-1; NumberYouWantToFacult > 0; NumberYouWantToFacult--)
    {
       
       storage *= NumberYouWantToFacult; 
    }
    cout << storage << endl; 
}   

