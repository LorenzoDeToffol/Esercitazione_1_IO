#include <iostream>
#include <math.h>
#include <iomanip>
#include<fstream>
#include<sstream>
#include <string>


double trasformazione(double value) {
    return value * (3.0 / 4.0) - 7.0 / 4.0;
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
    double value;
    std::string header;
    fstr>> header;
    double somma = 0.0;
    int conteggio = 1;
    while (fstr >> value) {
        double valtrasf = trasformazione(value);

        somma += valtrasf;
        double media = somma / conteggio;

        filerisultati << conteggio << " "  << media << std::endl;

        conteggio++;
    }

    fstr.close();
    filerisultati.close();

    return 0;
}
