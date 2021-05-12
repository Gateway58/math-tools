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
//enter this to your desire 

//g usually 9.81 on earth, but if you are fancy, you can change this. 
double gravity = 9.81;  

// little t in s 
double ttime= 0; //tt because c++ doesn't allow a variable named time 

// little a (meter / second²) if you need to convert, then convert it yourself
double acceleration = 0; 

//little v (meter /second )if you need to convert, then convert it yourself
double velocity = 0;

//little h in meter
double height = 20 ; 

//big F in Newton 
double Force = 0; 

//little s in meter 
double determination = 0; 

//little m in kilogram   
double mass = 0; 
//enter in here, what things to check. By more than 1 thing chang it through a semicolon (;)
string WhatDoYouWant = " t; v  "; //Example: I want a and I want F: a; F
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
double temp;  
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
                cout << "a=" << temp << endl; break; 
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
            cout << "g=" << temp << endl; break; 
                

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
      
      default: break;
      }
      break;
      //End F
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

case 't': if(velocity != 0 && acceleration != 0)return 1; 
          if(determination != 0 && acceleration != 0) return 2; 
          if(velocity != 0 && gravity != 0)return 5; 
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


*/
