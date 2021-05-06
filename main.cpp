#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string.h>

#include "funciones.h"

using namespace std;




/*
*
*/
int main(int argc, char** argv)
{
    vector<datosEstudiantes> estudiante;
    estudiante = llenar_struct("estudiantes.csv");
    cout<<"id: "<<estudiante[1].getId()<<endl;
    cout<<"nombre: "<<estudiante[1].getNombre()<<endl;
    cout<<"promedio lenguaje: "<<estudiante[1].getPromedioLenguaje()<<endl;
    cout<<"promedio ingles: "<<estudiante[1].getPromedioIngles()<<endl;
    cout<<"promedio matematicas: "<<estudiante[1].getPromedioMatematicas()<<endl;
    cout<<"promedio ciencias: "<<estudiante[1].getPromedioCiencias()<<endl;
    cout<<"promedio historia: "<<estudiante[1].getPromedioHistoria()<<endl;
    cout<<"promedio tecnologia: "<<estudiante[1].getPromedioTecnologia()<<endl;
    cout<<"promedio artes: "<<estudiante[1].getPromedioArtes()<<endl;
    cout<<"promedio ed fisica: "<<estudiante[1].getPromedioEdfisica()<<endl;
    return 0;

}
