#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;
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

    //Asignar dato
    void setId(string num){id = num;}
    void setNombre(string name){nombre = name;}
    void setPromedioLenguaje(float avg_leng){promedio_lenguaje = avg_leng;}
    void setPromedioIngles(float avg_ing){promedio_ingles = avg_ing;}
    void setPromedioMatematicas(float avg_mat){promedio_matematicas = avg_mat;}
    void setPromedioCiencias(float avg_cienc){promedio_ciencias = avg_cienc;}
    void setPromedioHistoria(float avg_hist){promedio_historia = avg_hist;}
    void setPromedioTecnologia(float avg_tec){promedio_tecnologia = avg_tec;}
    void setPromedioArtes(float avg_art){promedio_artes = avg_art;}
    void setPromedioEdfisica(float avg_edfis){promedio_edfisica = avg_edfis;}

    //Obtener dato
    const string getId(){return id;}
    const string getNombre(){return nombre;}
    const float getPromedioLenguaje(){return promedio_lenguaje;}
    const float getPromedioIngles(){return promedio_ingles;}
    const float getPromedioMatematicas(){return promedio_matematicas;}
    const float getPromedioCiencias(){return promedio_ciencias;}
    const float getPromedioHistoria(){return promedio_historia;}
    const float getPromedioTecnologia(){return promedio_tecnologia;}
    const float getPromedioArtes(){return promedio_artes;}
    const float getPromedioEdfisica(){return promedio_edfisica;}
};

//vector<string> leer_archivo();
void leer();
string cambiar_comilla_por_cero(string sentencia);
vector<datosEstudiantes> llenar_struct(string archivo);


#endif /* FUNCIONES_H */
