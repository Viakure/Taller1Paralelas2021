#include "funciones.h"

using namespace std;

vector<string> leer_archivo()
{
    ifstream archivo("estudiantes.csv");
    string line = "";

    vector<string> datos_csv;
    while(getline(archivo, line))
    {
        stringstream strstr(line);
        string word="";
        while(getline(strstr,word, ','))
        {
            datos_csv.push_back(word);
        }
    }
    return datos_csv;
}

string cambiar_comilla_por_cero(string sentencia)
{
    //comillas dobles en ascii = 34
    char string_sin_comillas[999999];
    for (int i=0;i<sentencia.size();i++)
    {
        if (sentencia.at(i)!=34)
            {string_sin_comillas[i] = sentencia.at(i);}
        else {string_sin_comillas[i] = '0';}
    }
    string resultado = string_sin_comillas;
    return resultado;
    }



vector<datosEstudiantes> llenar_struct(string archivo)
{
    vector<datosEstudiantes> result;
    datosEstudiantes *estudiante = new datosEstudiantes[15000];
    ifstream lectura;
    lectura.open(archivo);
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
        result.push_back(estudiante[cont-1]);
    }
    return result;
        
}
