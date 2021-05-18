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
#include <istream>

using namespace std; 
/*
Update 18.05.2021 (19.05.2021) are marked with #a80505 Text gets red, when you install an extension that does it (I don't know the name right now)
if you want to use ∆, just type in the given values but no more, just like you would do with others.I am already working on a better way to fix it, probably coming tomorrow or in 2 days. 
So only change the important values to the importantest to figure out, not even gravity! 
by troubles, please contact me at the given contacts from my github.
enter this to your desire 
*/
//if you don't know this value, set it to 0
//g usually 9.81 on earth, but if you are fancy, you can change this. 
long double gravity ;  

// little t in s 
long double ttime = 0; //tt because c++ doesn't allow a variable named time 

// little a (meter / second²)if you need to convert, then you can use my converter in the same folder and repository! called converter.cpp (Not out yet, its in the OddFormat Folder)
long double acceleration = 0; 

//little v (meter /second )if you need to convert, then you can use my converter in the same folder and repository! called converter.cpp (Not out yet, its in the OddFormat Folder)
long double velocity = 55.55556;

//little h in meter
long double height = 0 ; 

//big F in Newton 
long double Force = 300; 

//little s in meter 
long double determination = 0; 

//little m in kilogram   
long double mass = 0.05; 
//enter in here, what things to check. By more than 1 thing chang it through a semicolon (;)
string WhatDoYouWant = "   t  "; //Example: I want a and I want F: a; F
//pro tip: you can chain. Which means, when you need t and want to get v with 
//the t value, you don't have to get the result and chang it above in ttime, 
//just type in (in this Example) t; v and it will auto-use the t value for v and 
//other stuff :)


//Checks what values you want 
string FindOutWhatYouWant();
//Delets the spaces that were given from FindOutWhatYouWant() 
char DeleteSpaces(string Search); 
//checks if you have entered in enough information and what to do 
int CheckWhatsThere(char WhatYouWantToDo);    
//type the short things here. If you want 2 or more things, enter with a semicolon (;) 
int Check;  
long double temp;  
int main()
{
   const int size = WhatDoYouWant.size()+1; 
for (int i = 0; i < size; i++)
{
   string uncleanCheck =  FindOutWhatYouWant(); 
   char WhatToCheck = DeleteSpaces(uncleanCheck);
  switch (WhatToCheck )
  {
      case 'a':
        Check = CheckWhatsThere('a'); 
        
             switch (Check)
            {
                case 1: temp = velocity/ttime; acceleration = temp;  
                cout << "a= " << temp << endl; break; 
              
                case 2: temp = 2*determination /pow(ttime, 2);  acceleration = temp; 
                cout << "a= " <<temp << endl;  break; 

                case 3:temp = pow(velocity, 2)/2*determination; acceleration = temp; 
                cout << "a= " << temp<< endl; break; 

                case 4: temp = Force /mass; acceleration = temp; 
                cout << "a= " << temp << endl; break; 
                default: break; 
            } 
            break; // End a 
            
      case 't': 
        Check = CheckWhatsThere('t'); 
        switch (Check)
        {
            case 1: temp = velocity/acceleration; ttime = temp; 
            cout << "t= " << temp << endl; break;   
            case 2: temp =  sqrt((2*determination/acceleration)); ttime = temp; 
            cout << "t= " << temp << endl; break; 
            case 5: temp = velocity/gravity; ttime = temp; 
            cout << "t= " << temp << endl;  break; 
            case 6: temp = sqrt((2*height/gravity)); ttime = temp; 
            cout << "t= " << temp << endl; break; 
            //Start #a80505 (red) 
            case 10: temp = mass*velocity/Force; mass = temp; 
            cout << "t= " << temp << endl; break; 
            //End #a80505 (red) 
        
        default: break;
        } 
        break; //End t 
    case 'v': 
       Check = CheckWhatsThere('v'); 
        switch (Check)
        {
            case 1: temp = acceleration*ttime; velocity = temp; 
            cout << "v= " << temp << endl; break;   
            case 3: temp = sqrt((2*acceleration*determination)); velocity = temp; 
            cout << "v= " << temp << endl; break; 
            case 5: temp = gravity *ttime; velocity = temp; 
            cout << "v= " << temp << endl;  break; 
            case 7: temp = sqrt((2*gravity*height)); velocity = temp; 
            cout << "v= " << temp << endl; break; 
            //Start #a80505 (red) 
            case 10: temp = Force*ttime/mass; mass = temp; 
            cout << "v= " << temp << endl; break; 
            //End #a80505 (red) 
        
        default: break;
        } 
        break; //End v
    case 's': 
       Check = CheckWhatsThere('v'); 
        switch (Check)
        {
            case 2: temp = 0.5*acceleration*pow(ttime, 2); determination = temp; 
            cout << "s= " << temp << endl; break;   
            case 3: temp = pow(velocity, 2)/2*acceleration; determination = temp; 
            cout << "s= " << temp << endl; break; 

        default: break;
        } 
        break; //End s
    case 'h': 
       Check = CheckWhatsThere('h'); 
        switch (Check)
        {
            case 6: temp = 0.5*gravity*pow(ttime, 2); height = temp; 
            cout << "h= " << temp << endl; break;   
            case 7: temp = pow(velocity, 2)/2*gravity; height = temp; 
            cout << "h= " << temp << endl; break; 

        default: break;
        } 
        break; //End h
    case 'g': 
      Check = CheckWhatsThere('g'); 
        switch (Check)
        {
             case 5: temp = velocity/ttime; gravity = temp;  
            cout << "g= " << temp << endl; break; 
              
            case 6: temp = 2*determination /pow(ttime, 2);  gravity = temp; 
            cout << "g= " <<temp << endl;  break; 

            case 7:temp = pow(velocity, 2)/2*determination; gravity = temp; 
            cout << "g= " << temp<< endl; break; 

            case 8: temp = Force /mass; gravity = temp; 
            cout << "g= " << temp << endl; break; 
                

        default: break;
        } 
        break; //End g

      case 'F': 
      Check = CheckWhatsThere('F'); 
      switch (Check)
      {
      case 4: temp = mass *acceleration; Force = temp; 
      cout <<"F= " << temp << endl; break; 
      case 8: temp = mass*gravity; Force = temp; 
      cout <<"F= " << temp << endl; break; 
      //Start #a80505 (red) 
      case 10: temp = mass*velocity/ttime; mass = temp; 
      cout << "F= " << temp << endl; break; 
      //End #a80505 (red) 
      default: break;
      }
      break;
      //End F
      //Begin m and also #a80505 (red) 
       case 'm': 
      Check = CheckWhatsThere('m'); 
      switch (Check)
      {
      case 4: temp = Force/acceleration; mass = temp; 
      cout <<"m= " << temp << endl; break; 
      case 8: temp = Force/gravity; mass = temp; 
      cout <<"m= " << temp << endl; break; 
      //Where #a80505 (red) should have started 
      case 10: temp = Force*ttime/velocity; mass = temp; 
      cout <<"m= " << temp << endl; break; 
      //Where #a80505 (red) should have ended 
      default: break;
      }
      break;
      //End m 



      default: break; 
      //End #a80505 (red). I forgot m last time and to add a break when none of these match.
  }
   
   
   
}


}
string FindOutWhatYouWant()
{
     //cout << WhatDoYouWant << endl; 
    int pinpoint = WhatDoYouWant.find(";");
   // cout << WhatDoYouWant << endl; 
    //cout << pinpoint << endl; 
  if(pinpoint == -1)
  { string temps = WhatDoYouWant ; 
  WhatDoYouWant =""; 
      return temps; 
  }
     
    string output = WhatDoYouWant.substr(0, pinpoint); 
   WhatDoYouWant = WhatDoYouWant.substr(pinpoint+1);
  // cout << WhatDoYouWant << endl;  
    return output; 
    
    
}
char DeleteSpaces(string Search)
{
    bool skip = false; 
    for (char SearchSpace: Search){
       
        
        switch (SearchSpace)
        {
        case 'a': return 'a'; 
        case 'F': return 'F'; 
        case 'v': return 'v'; 
        case 'h': return 'h'; 
        case 't': return 't'; 
        case 's': return 's'; 
        case 'g': return 'g'; 
        default:
            break;
        } 
        
    }
     return ' ';
}
int CheckWhatsThere(char WhatResultYouWant)
{
switch (WhatResultYouWant)
{
case 'a': if (velocity != 0 && ttime != 0 ) return 1; 
          if (determination != 0 && ttime != 0)return 2;
          if(velocity != 0 && determination != 0) return 3;
          if (Force != 0 && mass != 0) return 4; 
         
case 'v': if(acceleration != 0 && ttime != 0)return 1; 
          if(acceleration != 0 && determination != 0)return 3; 
          if (gravity != 0 && ttime != 0)return 5; 
          if (gravity != 0 && height != 0)return 6; 
          //Start #a80505 (red) 
          if(Force != 0 && ttime != 0 && mass != 0)return 10; 
          //End #a80505 (red) 

case 't': if(velocity != 0 && acceleration != 0)return 1; 
          if(determination != 0 && acceleration != 0) return 2; 
          if(velocity != 0 && gravity != 0)return 5; 
        //Start #a80505 (red) 
          if(Force != 0 && velocity != 0 && mass != 0)return 10; 
        //End #a80505 (red) 
          if(height != 0 && gravity != 0)return 6;  
case 's': if(acceleration != 0 && ttime != 0)return 2; 
          if(acceleration != 0 && determination != 0)return 3; 
case 'h':     
        if(gravity != 0 && ttime != 0)return 6; 
        if(gravity != 0 && determination != 0)return 7;  
case 'g':  
          if (velocity != 0 && ttime != 0 ) return 5; 
          if (height != 0 && ttime != 0)return 6;
          if(velocity != 0 && height != 0) return 7;
          if (Force != 0 && mass != 0) return 8;
case 'F': 
        if(mass != 0 && acceleration != 0) return 4; 
        if(mass != 0 && gravity != 0 ) return 8; 
      //Start #a80505 (red) 
        if(velocity != 0 && ttime != 0 && mass != 0)return 10; 
      //End #a80505 (red) 
case 'm': 
        if(Force != 0 && acceleration != 0)return 4; 
        if(Force != 0 && gravity != 0)return 8; 
        //Start #a80505 (red) 
        if(Force != 0 && ttime != 0 && velocity != 0)return 10; 
        //End #a80505 (red)
default: break; 
}
return 0; 
}
//if you want to understand the code, the integers refer to the formla I've learned
//here:
/*
1: v = a*t             | 5: v = g*t
2: s = 1/2 *a *t²      | 6: h = 1/2*g*t²
3: v² = 2*a*s          | 7: v²= 2*g*h
4: F = m*a             | 8: F = m*g

Start Update #a80505 (red) 
10: F * ∆t = m * ∆v
End Update #a80505 (red) 
*/
