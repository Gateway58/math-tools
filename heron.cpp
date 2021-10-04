#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdio.h>
int main()
{
    std::cout << std::setprecision(30); // Output kann 30 Nachkommastellen beinhalten

    int sqrt = 2; //int = Ganzzahl (Z)

    //double = Dezimalzahl. Long + double = Dezimalzahl mit vielen Stellen
    long double x, y; // Seitenlängen

    long double newvar = sqrt + 1; //Rechteck mit radikand * 1

    for (int i = 0; i < 1000; i++) //Heron algorithmus
    {
        x = newvar / 2; //Die eine Seitenlängen ist das arithmetische Mittel Beider, um das Rechteck immer mehr zu einem Quadrat umzuformen
        y = sqrt / x; //Andere Seitenlängen
        newvar = x + y; //Adierung der Seitenlängen, um im nächsten Schritt wieder das arithmetische Mittel rauszubekommen
    }
    std::cout << x << std::endl;
    return 0;
}
