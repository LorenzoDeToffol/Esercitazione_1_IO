#include <iostream>
#include <math.h>
#include <iomanip>
#include<fstream>
#include<sstream>
#include <string>
using namespace std;

double trasformazione(double value)
{
    double trsf = (value * (3.0 / 4.0)) - (7.0 / 4.0);
    return trsf;
}

int main() {

    std::string nameFile = "data.csv";
    std::ifstream fstr(nameFile);
    std::string fileRisultati = "result.csv";
    std::ofstream filerisultati(fileRisultati);
    if(fstr.fail())
    {
        std::cerr << "File not found" << std::endl;
    }
    if(filerisultati.fail())
    {
        std::cerr << "result.csv non creato" << std::endl;
    }
    double somma = 0.0;
    double media = 0.0;
    int conteggio = 1;
    double value;
    while(fstr>>value)
    {
        double valtrasf = trasformazione(value);
        somma += valtrasf;
        media = somma / conteggio;

        filerisultati  << conteggio << " " << media << "\n";


        conteggio++;
    }

    fstr.close();
    filerisultati.close();

    return 0;
}
