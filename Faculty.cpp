#include <include.h>
using namespace std; 
bool CheckForMinus(); 
/*this is nothing special, but my math teacher mentioned it today 
and i tried to implement this in c++ just for fun yk what you usually do in math lessons. 
I want to make my own sort of console calculator which will be really bad, but will
be an awesome experience in programming because it should be very logical and should not
have many lines and I may use this code from here for it.
 However my top priority is the math tools, because its soooooo
easy to edit and add new ones.  
*/
 double NumberYouWantToFacult = -5; //self explanained variable 
    int length = 6;                 //change the length you want 
     int64_t storage = 1;           //let this be at 1

int main(){
   bool isPlus = CheckForMinus();

   if (isPlus)
   {
       
    for (NumberYouWantToFacult-1; NumberYouWantToFacult > 0 ; NumberYouWantToFacult--)
    { 
     storage *= NumberYouWantToFacult;
     
       length--;   
        if (length == 0 )
        {
          break; 
        }
       
    }
    cout << storage << endl;
   }
   return 0; 
    
   
}   
bool CheckForMinus()
{
    if (NumberYouWantToFacult > 38) //if our Faculty number is higher than 38, then we want 
    {                               //an Unsigned long long int, because it will be very big
       storage = 1ULL;
       return true;  
    }
    if (NumberYouWantToFacult < -38)//if our Faculty number is less than 38, then we want
    {                               //a (Signed) long long int, because it will be very big in negative way.
       storage = 1LL; 
    }
    
    
    if (NumberYouWantToFacult < 0)//if its less than 0, we want it to get an unsigned int and then just print out the minus  
    {
         for (NumberYouWantToFacult+1; NumberYouWantToFacult < 0 ; NumberYouWantToFacult++)//just the opposite from above with +
        { 
                storage *= -NumberYouWantToFacult;//as i said, we want a positive number 
                length--;   
            if (length == 0 )
            {
                break; 
            }
       
        }
    cout << "-" << storage <<  endl; //to just add the minus ourselves
    return false;                   //then it exits and makes sure it doesn't do the process twice 
    }
    return true;                    //if not, hey we checked if we need an ULL, changed that and 
                                    //now do the positive thing if its not negative 
    
}
/*thanks for reading through, didn't thought i had to include negatives and include when the 
numbers get to high, but now i know more about how to break the limits of 32-bit intigers
hope you enjoyed and #roadtoonesubscriber 
*/
