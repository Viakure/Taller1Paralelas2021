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
    /* 
    OPCION DE ORDEN:
        1: promedio general
        2: Promedio Arte y edFisica
        3: Promedio Lengua y Historia
        4: Promedio Tecnología Mate y Ciencias
        5: Orden por nombre(SIRVE IMPLICITAMENTE PARA ID)
    */
    vector<datosEstudiantes> mejores_tecmatciencias_ord,
    estudiante,mejores_general,estudiante_nuevo,
    mejores_arteyedfisica,estudiante_nuevo_v2,
    estudiante_nuevo_v3,mejores_lenguahistoria,
    mejores_tecmatciencias,estudiante_nuevo_v4;
    
    cout<< "Llenando el primer struct con los datos de todos los estudiantes a partir del archivo... ----"<< endl;
    estudiante = llenar_struct("estudiantes.csv");


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout<< "Obteniendo los mejores 100 promedios..........................................................."<< endl;
    mejores_general = primeros_cien_promedios(estudiante,1);
    cout<< "Creando el archivo maximos.csv................................................................."<<endl;
    llenar_csv (mejores_general,1);
    mejores_general = mayor_menor_promedio(mejores_general,5);
    cout<< "Eliminando los mejores cien promedios del resto de los estudiantes............................."<< endl;    
    estudiante_nuevo = eliminar_estudiantes_seleccionados(estudiante,mejores_general);
    estudiante_nuevo = mayor_menor_promedio(estudiante_nuevo,1);


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout<< "Obteniendo los mejores 100 promedios restantes en arte y ed fisica............................."<< endl;
    mejores_arteyedfisica = primeros_cien_promedios(estudiante_nuevo,2);
    cout<< "Creando el archivo artistico.csv..............................................................."<<endl;
    llenar_csv (mejores_arteyedfisica,2);
    cout<< "Eliminando los mejores cien en arte y ed fisica del struct restante............................."<< endl;
    estudiante_nuevo_v2 = eliminar_estudiantes_seleccionados(estudiante_nuevo, mejores_arteyedfisica);
    estudiante_nuevo_v2 = mayor_menor_promedio(estudiante_nuevo_v2,2);


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout<< "Obteniendo los mejores 100 promedios restantes en lengua y historia... ----------------------"<< endl;
    mejores_lenguahistoria = primeros_cien_promedios(estudiante_nuevo_v2,3);
    cout<< "Creando el archivo humanismo.csv.............................................................."<<endl;
    llenar_csv (mejores_lenguahistoria,3);
    cout<< "Eliminando los mejores cien en lengua y historia del struct restante... ----------------------"<< endl;
    estudiante_nuevo_v3 = eliminar_estudiantes_seleccionados(estudiante_nuevo_v2,mejores_lenguahistoria);
    estudiante_nuevo_v3 = mayor_menor_promedio(estudiante_nuevo_v3,3);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
    cout<< "Obteniendo los mejores 100 promedios restantes en tecnologia, matematicas y ciencias... -----"<< endl;
    mejores_tecmatciencias = primeros_cien_promedios(estudiante_nuevo_v3,4);
    cout<< "Creando el archivo tecnicos.csv..............................................................."<<endl;
    llenar_csv (mejores_tecmatciencias,4);
    mejores_tecmatciencias_ord = mayor_menor_promedio(mejores_tecmatciencias,5);

    cout<<"===INTEGRANTES==="<<endl;
    cout<<" Nicolas Ipinza  "<<endl;
    cout<<" Ian Poveda      "<<endl;
    cout<<"-----------------"<<endl;

    exit(EXIT_SUCCESS);
    return 0;

}
