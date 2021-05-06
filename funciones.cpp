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




/*void leer()
{
    ifstream infile("estudiantes.csv");
    string line = "";
    string id,prom_lenguaje,prom_ingles,prom_mat,prom_ciencias,prom_hist,prom_tec,prom_art,prom_edfis;
    string nombre,final;
    vector<string> datos_csv;
    vector<string> id_nombre_leng;
    vector<string> arreglo;
    while(getline(infile, line))
    {
        getline(infile, id, ';');
        getline(infile, nombre, ';');
        getline(infile, prom_lenguaje, ';');
        getline(infile, prom_ingles, ';');
        getline(infile, prom_mat, ';');
        getline(infile, prom_ciencias, ';');
        getline(infile, prom_hist, ';');
        getline(infile, prom_tec, ';');
        getline(infile, prom_art, ';');
        getline(infile, prom_edfis, ';');


        stringstream strstr(line);
        string word="";
        //while(getline(strstr,word, ';'))
        //{
        //    datos_csv.push_back(word);
        //}

    }

    //for(int i=0; i<datos_csv.size() ;i++)
    //{
      //  cout<<datos_csv.at(i)<<"\n";
   // }  
}*/