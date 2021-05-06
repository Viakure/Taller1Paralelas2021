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
    vector<datosEstudiantes> max;
    estudiante = llenar_struct("estudiantes.csv");
    max = Orden_MayorMenor(estudiante);
    //max.setPromedioGeneral();
    for (unsigned int i=0;i<100;i++)
    {   
        cout<<"Nombre: "<< max[i].getNombre() <<endl; 
        cout<<"Promedio General: "<<max[i].getPromedioGeneral() <<endl;
        cout<<"Promedio Lenguaje: "<<max[i].getPromedioLenguaje()<<endl;
        cout<<endl;
    }
    //cout<< estudiante[6].getPromedioGeneral() <<endl;
    //cout<< estudiante[1].getPromedioGeneral() <<endl;
    return 0;

}
