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
#include <cerrno>
#include <cstdlib>
#include <iomanip>

using namespace std; 
//Information: Idea: 12.05.2021. First version 15.05.2021, Time wasted: >18000 Seconds

/*  syntax: your unit,  a colon (:) and then your desired Type.
    Example: I have 77kg and i want it to be in g, so type in the string: 77kg : g 
    Spaces don't matter
*/
string convertion = "12kg:g";  // Change this string to your favor
/*  
    Available Types: 

    s, m, h             time            (t)

    µm, mm, cm, dm, m   determination   (s)

    g, kg, t            mass            (m)     
    
    mm/s, mm/m, mm/h
    dm/s, dm/m, dm/h    
    cm/s, cm/m, cm/h    Velocity        (v)
    m/s, m/m, m/h
    km/s, km/m, km/h
*/
//get the number that you've entered !Warning: Numbers have to be written with no space in between
long double GetNumber();                                        //Example: You can't write 58 as 5 8
int getMax(int z, int o, int t, int th, int f, int fi, int s, int sev, int e, int n);  
//Get the type you have entered past your number (Past number, before the colon). Use the types documented above (Search "AvalibelTypes") 
string GetType(); 
//Get the wanted converted type (past colon) Use the types documented above (Search "AvalibelTypes") 
string GetWishedType(); 
//do some fancy Mathematics in order to get your wished number 
long double Convert(long double number, string Type, string WishedType); 
//Delete the spaces 
string DeleteSpaces(string TheString); 

int keep, FindColon; 
//Start of main 
int main()
{
    std::cout.precision(21);             //makes sure doubles and other things work correctly 
   long double number = GetNumber();     //Gets the number (using the .find and .substr method)
   string Type = GetType();              //Gets the type before the : 
   string WishedType = GetWishedType();  //Gets the type after the :, so the "Wished" Type 
   cout << setprecision(5) <<  fixed<<Convert(number, Type, WishedType) << endl; 
   /*   Warning: C++ and many other languages are bad at estimating the excact floating point of a number
        best is to leave this at 2 or 3, but if you absolutely have to get a precises answer, set it to how 
        many digits after . you want to have 
   */
    //std::cout << number << "|" << Type  << "|"<< WishedType <<  endl; 
}
//End of main 

//Start Get Number
long double GetNumber()
{
    string temp = convertion; 
    int pinpoint;  
    string find;
    while (true){ 
    int zer = temp.find("0"); 
    int one = temp.find("1"); 
    int two = temp.find("2"); 
    int thr = temp.find("3"); 
    int fou = temp.find("4"); 
    int fif = temp.find("5"); 
    int six = temp.find("6"); 
    int sev = temp.find("7"); 
    int eig = temp.find("8"); 
    int nin = temp.find("9"); 
    
    if( zer == -1 && one == -1 && two == -1 && thr == -1 && fou == -1 && fif == -1 && six == -1 & sev == -1 && eig == -1 && nin == -1)
    {
           break; 
    }
    pinpoint =  (getMax(zer, one, two, thr, fou, fif, six, sev, eig, nin)) +1; 
    keep += pinpoint; 
    temp = temp.substr(pinpoint); 
    }
   
    string temps = convertion.substr(0, keep); 
     long double output = strtold(temps.c_str(), 0); 
    return output; 
}

int getMax(int z, int o, int t, int th, int f, int fi, int s, int sev, int e, int n)
{
     int temp = max(z, o); 
    temp = max (temp, t); 
    temp = max (temp, th);
    temp = max (temp, f);
    temp = max (temp, fi);
    temp = max (temp, s);
    temp = max (temp, sev);
    temp = max (temp, e);
    temp = max (temp, n);

        return temp; 
}
//End Get Number

//Start GetType
string GetType()
{
   FindColon = convertion.find(":"); 
    string Type = convertion; 
    Type = Type.substr(keep, FindColon-keep); 
   Type = DeleteSpaces(Type); 

    return Type; 
}
//End GetType

//Start GetWishedType
string GetWishedType()
{
    string WishedType = convertion; 
    WishedType = WishedType.substr(FindColon+1); 
    WishedType = DeleteSpaces(WishedType); 

    return WishedType; 
}
//End GetWishedType

//Start of the Convert method 
long double Convert(long double number, string Type, string WishedType)
{
    //Start determination s 
    //if(Type == "c")system("clear"); return 0; 
    if(Type == "µm")  
    {
        if(WishedType == "µm")  return number; 
        if(WishedType == "mm")  return number/1000; 
        if(WishedType == "cm")  return number/10000; 
        if(WishedType == "dm")  return number/100000; 
        if(WishedType == "m")   return number/1000000; 
        if(WishedType == "km")  return number/1000000000; 
        cout << "error. Change type after colon to: mm, cm, dm, m or km" << endl; 
        return 0; 
    }
    if (Type == "mm")
    {
       if(WishedType == "µm")  return number*1000; 
        if(WishedType == "mm")  return number; 
        if(WishedType == "cm")  return number/10; 
        if(WishedType == "dm")  return number/100; 
        if(WishedType == "m")   return number/1000; 
        if(WishedType == "km")  return number/1000000; 
        cout << "error. Change type after colon to: µm, cm, dm, m or km" << endl; 
        return 0; 
    }
     if (Type == "cm")
    {
       if(WishedType == "µm")  return number*10000000; 
        if(WishedType == "mm")  return number*10; 
        if(WishedType == "cm")  return number; 
        if(WishedType == "dm")  return number/10; 
        if(WishedType == "m")   return number/100; 
        if(WishedType == "km")  return number/100000; 
        cout << "error. Change type after colon to: µm, mm, dm, m or km" << endl; 
        return 0; 
    }
     if (Type == "dm")
    {
       if(WishedType == "µm")  return number*100000000; 
        if(WishedType == "mm")  return number*100; 
        if(WishedType == "cm")  return number*10; 
        if(WishedType == "dm")  return number; 
        if(WishedType == "m")   return number/10; 
        if(WishedType == "km")  return number/10000; 
        cout << "error. Change type after colon to: µm, mm,cm, m or km" << endl; 
        return 0; 
    }
     if (Type == "m")
    {
       if(WishedType == "µm")  return number*1000000000; 
        if(WishedType == "mm")  return number*1000; 
        if(WishedType == "cm")  return number*100; 
        if(WishedType == "dm")  return number*10; 
        if(WishedType == "m")   return number; 
        if(WishedType == "km")  return number/1000; 
        cout << "error. Change type after colon to: µm, mm, cm, dm or km" << endl; 
        return 0; 
    }
     if (Type == "km")
    {
        if(WishedType == "µm")  return number*10000000000; 
        if(WishedType == "mm")  return number*100000; 
        if(WishedType == "cm")  return number*10000; 
        if(WishedType == "dm")  return number*1000; 
        if(WishedType == "m")   return number*100; 
        if(WishedType == "km")  return number; 
        cout << "error. Change type after colon to: µm, mm, cm, dm or m" << endl; 
        return 0; 
    }
    //End determination s

    //Start Mass m
    if(Type == "g")
    {
        if(WishedType == "g")   return number; 
        if(WishedType == "kg")  return number/1000; 
        if(WishedType == "t")   return number/1000000; 
        cout << "error. Change type after colon to: kg or t" << endl; 
        return 0; 
    }
     if(Type == "kg")
    {
        if(WishedType == "g")   return number*1000; 
        if(WishedType == "kg")  return number; 
        if(WishedType == "t")   return number/1000; 
        cout << "error. Change type after colon to: g or t" << endl; 
        return 0; 
    }
     if(Type == "t")
    {
        if(WishedType == "g")   return number*1000000; 
        if(WishedType == "kg")  return number*1000; 
        if(WishedType == "t")   return number; 
        cout << "error. Change type after colon to: kg or t" << endl; 
        return 0; 
    }
    //End Mass m 

    //Start time t
    if(Type == "s")
    {
        if(WishedType == "s") return number; 
        if(WishedType == "m") return number/60; 
        if(WishedType == "h") return number/3600; 
        cout << "error. Change type after : to m or h" << endl; 
        return 0; 
    }
     if(Type == "m")
    {
        if(WishedType == "s") return number*60; 
        if(WishedType == "m") return number; 
        if(WishedType == "h") return number/60; 
         cout << "error. Change type after : to s or h" << endl; 
        return 0; 
    }
     if(Type == "h")
    {
        if(WishedType == "s") return number*3600; 
        if(WishedType == "m") return number*60; 
        if(WishedType == "h") return number; 
         cout << "error. Change type after : to s or m" << endl; 
        return 0; 
    }
    //End time t 
    //!
    //Start Velocity v 
    //Start Millimeter per time #cc2323 
    if(Type == "mm/s")
    {
        //popular, most used 
        if(WishedType == "m/s")return number*0.001; 
        if(WishedType == "km/h")return number*0.0036; 

        // m / t
        if(WishedType == "m/m") return number*0.06;
        if(WishedType == "m/h") return number*3.6;

        // km / t
        if(WishedType == "km/s") return number*0.000001;
        if(WishedType == "km/m") return number*0.00006;
       
        // mm / t   
        if(WishedType == "mm/s") return number; 
        if(WishedType == "mm/m") return number*60;  
        if(WishedType == "mm/h") return number*3600; 

        // cm / t
        if(WishedType == "cm/s")  return number/10;    
        if(WishedType == "cm/m")  return number*6;    
        if(WishedType == "cm/h")  return number*360;    

        // dm / t 
        if(WishedType == "dm/s")  return number/100;    
        if(WishedType == "dm/m")  return number*0.6;    
        if(WishedType == "dm/h")   return number*36;   
        cout << "error. Change type after :" << endl;
        return 0;  

     //!    
    }
    if(Type == "mm/m")
    {
        //popular, most used 
        if(WishedType == "m/s")      return number*0.00002; 
        if(WishedType == "km/h")     return number*0.00006;

        // m / t
        if(WishedType == "m/m")      return number*0.001;
        if(WishedType == "m/h")      return number*0.06;

        // km / t
        if(WishedType == "km/s")     return number*0.00000002;
        if(WishedType == "km/m")     return number*0.000001;
       
        // mm / t   
        if(WishedType == "mm/s")     return number*0.01666;
        if(WishedType == "mm/m")     return number;
        if(WishedType == "mm/h")     return number*60;

        // cm / t
        if(WishedType == "cm/s")      return number*0.00166; 
        if(WishedType == "cm/m")      return number*0.1;
        if(WishedType == "cm/h")      return number*6;

        // dm / t 
        if(WishedType == "dm/s")      return number*0.00016; 
        if(WishedType == "dm/m")      return number*0.01;
        if(WishedType == "dm/h")      return number*0.6;
        cout << "error. Change type after :" << endl;
        return 0; 
    }
    if(Type == "mm/h")
    {
        //popular, most used 
        if(WishedType == "m/s") return number*0.0000003;
        if(WishedType == "km/h") return number*0.000001;

        // m / t
        if(WishedType == "m/m") return number*0.00002;
        if(WishedType == "m/h") return number*0.001;

        // km / t
        if(WishedType == "km/s") return number*0.0000000003;
        if(WishedType == "km/m") return number*0.00000002;
       
        // mm / t   
        if(WishedType == "mm/s")  return number*0.00027;  
        if(WishedType == "mm/m")  return number*0.01666;    
        if(WishedType == "mm/h")   return number;   

        // cm / t
        if(WishedType == "cm/s")    return number*0.00003;  
        if(WishedType == "cm/m")    return number*0.00166;  
        if(WishedType == "cm/h")    return number*0.1;  

        // dm / t 
        if(WishedType == "dm/s")  return number*0.000003;    
        if(WishedType == "dm/m")   return number*0.00016;   
        if(WishedType == "dm/h")   return number*0.01;   
        cout << "error. Change type after :" << endl;
         return 0;
    }
    //End Millimeter per time   #cc2323

    //Start Centimeter per time #db7a02
    if(Type == "cm/s")
    {
        //popular, most used 
        if(WishedType == "m/s") return number*0.01;
        if(WishedType == "km/h") return number*0.036;

        // m / t
        if(WishedType == "m/m") return number*0.6;
        if(WishedType == "m/h") return number*36;

        // km / t
        if(WishedType == "km/s") return number*0.00001;
        if(WishedType == "km/m") return number*0.0006;
       
        // mm / t   
        if(WishedType == "mm/s")    return number*10;
        if(WishedType == "mm/m")     return number*600; 
        if(WishedType == "mm/h")     return number*36000; 

        // cm / t
        if(WishedType == "cm/s")     return number; 
        if(WishedType == "cm/m")     return number*60; 
        if(WishedType == "cm/h")    return number*3600; 

        // dm / t 
        if(WishedType == "dm/s")      return number*0.1; 
        if(WishedType == "dm/m")      return number*6;
        if(WishedType == "dm/h")      return number*360;

         return 0;
    }
    if(Type == "cm/m")
    {
        //popular, most used 
        if(WishedType == "m/s") return number*0.00016;
        if(WishedType == "km/h") return number*0.0006;

        // m / t
        if(WishedType == "m/m") return number*0.01;
        if(WishedType == "m/h") return number*0.6;

        // km / t
        if(WishedType == "km/s") return number*0.00000016;
        if(WishedType == "km/m") return number*0.00001;
       
        // mm / t   
        if(WishedType == "mm/s") return number*0.16666;   
        if(WishedType == "mm/m") return number*10;     
        if(WishedType == "mm/h")  return number*600;    

        // cm / t
        if(WishedType == "cm/s")  return number*0.01666;    
        if(WishedType == "cm/m")  return number;    
        if(WishedType == "cm/h")  return number*60;    

        // dm / t 
        if(WishedType == "dm/s") return number*0.00166;     
        if(WishedType == "dm/m") return number*0.1;     
        if(WishedType == "dm/h")  return number*6;    
        cout << "error. Change type after :" << endl;
         return 0;
    }
    if(Type == "cm/h")
    {
        //popular, most used 
        if(WishedType == "m/s")  return number*0.000003;
        if(WishedType == "km/h") return number*0.00002;

        // m / t
        if(WishedType == "m/m") return number*0.00016;
        if(WishedType == "m/h") return number*0.01;

        // km / t
        if(WishedType == "km/s") return number*0.000000003;
        if(WishedType == "km/m") return number*0.00000002;
       
        // mm / t   
        if(WishedType == "mm/s")  return number*0.00277;  
        if(WishedType == "mm/m")  return number*0.16666;    
        if(WishedType == "mm/h")  return number*10;    

        // cm / t
        if(WishedType == "cm/s")  return number*0.00027;    
        if(WishedType == "cm/m")  return number*0.01666;    
        if(WishedType == "cm/h")   return number;   

        // dm / t 
        if(WishedType == "dm/s")  return number*0.00003;    
        if(WishedType == "dm/m")  return number*0.00166;    
        if(WishedType == "dm/h")   return number*0.1;   
        cout << "error. Change type after :" << endl;
         return 0;
    }
    // End Centimeter per time  #db7a02

    //Start Decimeter per time  #ded707
    if(Type == "dm/s")
    {
        //popular, most used 
        if(WishedType == "m/s")  return number*0.1;
        if(WishedType == "km/h") return number*0.36;

        // m / t
        if(WishedType == "m/m") return number*6;
        if(WishedType == "m/h") return number*360;

        // km / t
        if(WishedType == "km/s") return number*0.0001;
        if(WishedType == "km/m") return number*0.006;
       
        // mm / t   
        if(WishedType == "mm/s")  return number*100;  
        if(WishedType == "mm/m")  return number*6000;    
        if(WishedType == "mm/h")   return number*360000;   

        // cm / t
        if(WishedType == "cm/s")  return number*10;    
        if(WishedType == "cm/m")  return number*600;    
        if(WishedType == "cm/h")   return number*36000;   

        // dm / t 
        if(WishedType == "dm/s")  return number;    
        if(WishedType == "dm/m")   return number*60;   
        if(WishedType == "dm/h")    return number*3600;  
        cout << "error. Change type after :" << endl;
         return 0;
    }
    if(Type == "dm/m")
    {
        //popular, most used 
        if(WishedType == "m/s") return number*0.00166;
        if(WishedType == "km/h") return number*0.006;

        // m / t
        if(WishedType == "m/m") return number*0.1;
        if(WishedType == "m/h") return number*6;

        // km / t
        if(WishedType == "km/s") return number*0.000002;
        if(WishedType == "km/m") return number*0.0001;
       
        // mm / t   
        if(WishedType == "mm/s")   return number*1.66666; 
        if(WishedType == "mm/m")   return number*100;   
        if(WishedType == "mm/h")   return number*6000;   

        // cm / t
        if(WishedType == "cm/s")  return number*0.16666;    
        if(WishedType == "cm/m")   return number*10;   
        if(WishedType == "cm/h")   return number*600;   

        // dm / t 
        if(WishedType == "dm/s")   return number*0.01666;   
        if(WishedType == "dm/m")   return number;   
        if(WishedType == "dm/h")    return number*60;  
        cout << "error. Change type after :" << endl;
        return 0; 
        
    }
    if(Type == "dm/h")
    {
        //popular, most used 
        if(WishedType == "m/s") return number;
        if(WishedType == "km/h") return number;

        // m / t
        if(WishedType == "m/m") return number;
        if(WishedType == "m/h") return number;

        // km / t
        if(WishedType == "km/s") return number;
        if(WishedType == "km/m") return number;
       
        // mm / t   
        if(WishedType == "mm/s")   return number; 
        if(WishedType == "mm/m")    return number;  
        if(WishedType == "mm/h")    return number;  

        // cm / t
        if(WishedType == "cm/s")   return number;   
        if(WishedType == "cm/m")    return number;  
        if(WishedType == "cm/h")    return number;  

        // dm / t 
        if(WishedType == "dm/s")   return number;   
        if(WishedType == "dm/m")   return number;   
        if(WishedType == "dm/h")    return number;  
cout << "error. Change type after :" << endl;
        return 0; 
    }
    //End Decimeter per time    #ded707

    //Start Meter per time      #4fde07
    if(Type == "m/s")
    {
        //popular, most used 
        if(WishedType == "m/s") return number;
        if(WishedType == "km/h") return number*3.6;

        // m / t
        if(WishedType == "m/m") return number*60;
        if(WishedType == "m/h") return number*3600;

        // km / t
        if(WishedType == "km/s") return number*0.001;
        if(WishedType == "km/m") return number*0.06;
       
        // mm / t   
        if(WishedType == "mm/s")   return number*1000; 
        if(WishedType == "mm/m")   return number*60000;   
        if(WishedType == "mm/h")   return number*3600000;   

        // cm / t
        if(WishedType == "cm/s")   return number*100;   
        if(WishedType == "cm/m")   return number*6000;   
        if(WishedType == "cm/h")   return number*360000;   

        // dm / t 
        if(WishedType == "dm/s")   return number*10;   
        if(WishedType == "dm/m")   return number*600;   
        if(WishedType == "dm/h")   return number*36000;   
        cout << "error. Change type after :" << endl;
        return 0; 
        
    }
    if(Type == "m/m")
    {
        //popular, most used 
        if(WishedType == "m/s") return number*0.01666;
        if(WishedType == "km/h") return number*0.06;

        // m / t
        if(WishedType == "m/m") return number;
        if(WishedType == "m/h") return number*60;

        // km / t
        if(WishedType == "km/s") return number*0.00002;
        if(WishedType == "km/m") return number*0.001;
       
        // mm / t   
        if(WishedType == "mm/s")  return number*16.66666;  
        if(WishedType == "mm/m")   return number*1000;   
        if(WishedType == "mm/h")   return number*60000;   

        // cm / t
        if(WishedType == "cm/s")   return number*1.66666;   
        if(WishedType == "cm/m")   return number*100;   
        if(WishedType == "cm/h")   return number*6000;   

        // dm / t 
        if(WishedType == "dm/s")   return number*0.16666;   
        if(WishedType == "dm/m")   return number*10;   
        if(WishedType == "dm/h")   return number*600;   
        cout << "error. Change type after :" << endl;
        return 0; 
        
    }
    if(Type == "m/h")
    {
        //popular, most used 
        if(WishedType == "m/s") return number*0.00027;
        if(WishedType == "km/h") return number*0.001;

        // m / t
        if(WishedType == "m/m") return number*0.01666;
        if(WishedType == "m/h") return number;

        // km / t
        if(WishedType == "km/s") return number*0.0000003;
        if(WishedType == "km/m") return number*0.00002;
       
        // mm / t   
        if(WishedType == "mm/s")    return number*0.27777;
        if(WishedType == "mm/m")   return number*16.66666;   
        if(WishedType == "mm/h")    return number*1000;  

        // cm / t
        if(WishedType == "cm/s")   return number*0.02777;   
        if(WishedType == "cm/m")    return number*1.6666;  
        if(WishedType == "cm/h")     return number*100; 

        // dm / t 
        if(WishedType == "dm/s")    return number*0.00277;  
        if(WishedType == "dm/m")     return number*0.16666; 
        if(WishedType == "dm/h")     return number*10; 
        cout << "error. Change type after :" << endl;
        return 0; 
    }
    //End Meter per time        #4fde07

    //Start Kilometer per time  #0892c4
    if(Type == "km/s")
    {
        //popular, most used 
        if(WishedType == "m/s")  return number*1000;
        if(WishedType == "km/h") return number*3600;

        // m / t
        if(WishedType == "m/m") return number*60000;
        if(WishedType == "m/h") return number*3600000;

        // km / t
        if(WishedType == "km/s") return number;
        if(WishedType == "km/m") return number*60;
       
        // mm / t   
        if(WishedType == "mm/s") return number*1000000;   
        if(WishedType == "mm/m") return number*60000000;    
        if(WishedType == "mm/h") return number*3600000000;     

        // cm / t
        if(WishedType == "cm/s") return number*100000;     
        if(WishedType == "cm/m") return number*6000000;     
        if(WishedType == "cm/h") return number*360000000;     

        // dm / t 
        if(WishedType == "dm/s") return number*10000;     
        if(WishedType == "dm/m") return number*600000;     
        if(WishedType == "dm/h") return number*36000000;    
        cout << "error. Change type after :" << endl;
        return 0; 
        
    }
    if(Type == "km/m")
    {
        //popular, most used 
        if(WishedType == "m/s")  return number*16.66666;
        if(WishedType == "km/h") return number*60;

        // m / t
        if(WishedType == "m/m") return number*1000;
        if(WishedType == "m/h") return number*60000;

        // km / t
        if(WishedType == "km/s") return number*0.01666;
        if(WishedType == "km/m") return number;
       
        // mm / t   
        if(WishedType == "mm/s") return number*16666.66666;   
        if(WishedType == "mm/m") return number*1000000;     
        if(WishedType == "mm/h")  return number*60000000;    

        // cm / t
        if(WishedType == "cm/s")  return number*1666.66666;    
        if(WishedType == "cm/m")  return number*100000;    
        if(WishedType == "cm/h")  return number*6000000;    

        // dm / t 
        if(WishedType == "dm/s")  return number*166.66666;    
        if(WishedType == "dm/m")  return number*10000;    
        if(WishedType == "dm/h")  return number*600000;    
        cout << "error. Change type after :" << endl;
        return 0; 
    }
    if(Type == "km/h")
    {
        //popular, most used 
        if(WishedType == "m/s") return number*0.2777778;
        if(WishedType == "km/h") return number;

        // m / t
        if(WishedType == "m/m") return number*16.66666;
        if(WishedType == "m/h") return number*10000;

        // km / t
        if(WishedType == "km/s") return number*0.00027;
        if(WishedType == "km/m") return number*0.01666;
       
        // mm / t   
        if(WishedType == "mm/s")  return number*277.77777;  
        if(WishedType == "mm/m")   return number*16666.66666;   
        if(WishedType == "mm/h")    return number*1000000;  

        // cm / t
        if(WishedType == "cm/s")   return number*27.77777;   
        if(WishedType == "cm/m")   return number*1666.66666;   
        if(WishedType == "cm/h")    return number*100000;  

        // dm / t 
        if(WishedType == "dm/s")   return number*2.77777;   
        if(WishedType == "dm/m")    return number*166.66666;  
        if(WishedType == "dm/h")    return number*10000;  
        cout << "error. Change type after :" << endl;
        return 0; 
        
    }
    //End Kilometer per time    #0892c4
    cout << "Type before : cannot be recognized. Please Look at the Available Types above." << endl; 
    return 0; 
}
//End of the Convert method 

//Start DeleteSpaces 
string DeleteSpaces(string TheString)
{
    string WithOutSpaces; 
    for (char charakter : TheString)
    {
        if (!isblank(charakter))
        {
            
            WithOutSpaces += charakter; 
        }
    }
    return WithOutSpaces; 
    
}
//End DeleteSpaces
//TODO: Support for .exe (User Input), more detailed information when converting (original type), testing, add more types.

















   //795 Lines is a lot to scroll through, just saying... .
