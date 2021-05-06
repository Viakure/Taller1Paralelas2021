#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "funciones.h"


using namespace std;

/*
*
*/
int main(int argc, char** argv)
{
    struct datosEstudiantes
    {
        string id;
        string nombre;
        float promedio_lenguaje;
        float promedio_ingles;
        float promedio_matematicas;
        float promedio_ciencias;
        float promedio_historia;
        float promedio_tecnologia;
        float promedio_artes;
        float promedio_edfisica;

    };

    datosEstudiantes *estudiante = new datosEstudiantes[14999];
    ifstream lectura;
    lectura.open("estudiantes.csv");
    int cont=0;
    for (string linea; getline(lectura, linea); )
    {
        stringstream registro(linea);
        string dato;
        cont++;
        for (int columna=0 ; getline(registro, dato, ';'); ++columna)
        {
            switch(columna)
            {
                case 0: //ID
                    estudiante[cont].id = dato;
                break;
                case 1: // NOMBRE
                    estudiante[cont].nombre = dato;
                break;
                case 2: // PROMEDIO LENGUAJE
                    estudiante[cont].promedio_lenguaje = stof(cambiar_comilla_por_cero(dato).c_str());
                break;
                case 3: // PROMEDIO INGLES
                    estudiante[cont].promedio_ingles = stof(cambiar_comilla_por_cero(dato).c_str());
                break;
                case 4: // PROMEDIO MATEMATICAS
                    estudiante[cont].promedio_matematicas = stof(cambiar_comilla_por_cero(dato).c_str());
                break;
                case 5: // PROMEDIO CIENCIAS
                    estudiante[cont].promedio_ciencias = stof(cambiar_comilla_por_cero(dato).c_str());
                break;
                case 6: // PROMEDIO HISTORIA
                    estudiante[cont].promedio_historia = stof(cambiar_comilla_por_cero(dato).c_str());
                break;
                case 7: // PROMEDIO TECNOLOGIA
                    estudiante[cont].promedio_tecnologia = stof(cambiar_comilla_por_cero(dato).c_str());
                break;
                case 8: // PROMEDIO ARTES
                    estudiante[cont].promedio_artes = stof(cambiar_comilla_por_cero(dato).c_str());
                break;
                case 9: // PROMEDIO ED. FISICA
                    estudiante[cont].promedio_edfisica = stof(cambiar_comilla_por_cero(dato).c_str());
                break;
            }       
        }
    }


    cout<<"id: "<<estudiante[5].id<<endl;
    cout<<"nombre: "<<estudiante[5].nombre<<endl;
    cout<<"promedio lenguaje: "<<estudiante[5].promedio_lenguaje<<endl;
    cout<<"promedio ingles: "<<estudiante[5].promedio_ingles<<endl;
    cout<<"promedio matematicas: "<<estudiante[5].promedio_matematicas<<endl;
    cout<<"promedio ciencias: "<<estudiante[5].promedio_ciencias<<endl;
    cout<<"promedio historia: "<<estudiante[5].promedio_historia<<endl;
    cout<<"promedio tecnologia: "<<estudiante[5].promedio_tecnologia<<endl;
    cout<<"promedio artes: "<<estudiante[5].promedio_artes<<endl;
    cout<<"promedio ed fisica: "<<estudiante[5].promedio_edfisica<<endl;

    
    return 0;

}
