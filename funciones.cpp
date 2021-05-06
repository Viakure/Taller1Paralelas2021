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
    for (unsigned int i=0;i<sentencia.size();i++)
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
        estudiante[cont].setPromedioGeneral();
        result.push_back(estudiante[cont-1]);
    }
    return result;
        
}

vector<datosEstudiantes> Orden_MayorMenor(vector<datosEstudiantes> struct_total)
{
    vector<datosEstudiantes> struct_ordenado;
    string aux_id,aux_nombre;
    float aux_proml,aux_promi,aux_promm,aux_promc,aux_promh,aux_proma,aux_promt,aux_prome,aux_promg;
    for (unsigned int i=0;i<struct_total.size();i++)
    {
        for (unsigned int j = i+1; j<struct_total.size();j++)
        {
            if (struct_total[i].getPromedioGeneral()<struct_total[j].getPromedioGeneral())
            {
                aux_promg = struct_total[j].getPromedioGeneral();
                aux_id = struct_total[j].getId();
                aux_nombre = struct_total[j].getNombre();
                aux_proml = struct_total[j].getPromedioLenguaje();
                aux_promi = struct_total[j].getPromedioIngles();
                aux_promm = struct_total[j].getPromedioMatematicas();
                aux_promc = struct_total[j].getPromedioCiencias();
                aux_promh = struct_total[j].getPromedioHistoria();
                aux_proma = struct_total[j].getPromedioArtes();
                aux_promt = struct_total[j].getPromedioTecnologia();
                aux_prome = struct_total[j].getPromedioEdfisica();

                struct_total[j].setPromedioGeneral_valor(struct_total[i].getPromedioGeneral());
                struct_total[j].setId(struct_total[i].getId());
                struct_total[j].setNombre(struct_total[i].getNombre());
                struct_total[j].setPromedioLenguaje(struct_total[i].getPromedioLenguaje());
                struct_total[j].setPromedioIngles(struct_total[i].getPromedioIngles());
                struct_total[j].setPromedioMatematicas(struct_total[i].getPromedioMatematicas());
                struct_total[j].setPromedioCiencias(struct_total[i].getPromedioCiencias());
                struct_total[j].setPromedioHistoria(struct_total[i].getPromedioHistoria());
                struct_total[j].setPromedioArtes(struct_total[i].getPromedioArtes());
                struct_total[j].setPromedioTecnologia(struct_total[i].getPromedioTecnologia());
                struct_total[j].setPromedioEdfisica(struct_total[i].getPromedioEdfisica());

                struct_total[i].setPromedioGeneral_valor(aux_promg);
                struct_total[i].setId(aux_id);
                struct_total[i].setNombre(aux_nombre);
                struct_total[i].setPromedioLenguaje(aux_proml);
                struct_total[i].setPromedioIngles(aux_promi);
                struct_total[i].setPromedioMatematicas(aux_promm);
                struct_total[i].setPromedioCiencias(aux_promc);
                struct_total[i].setPromedioHistoria(aux_promh);
                struct_total[i].setPromedioArtes(aux_proma);
                struct_total[i].setPromedioTecnologia(aux_promt);
                struct_total[i].setPromedioEdfisica(aux_prome);


            }
        }
        struct_ordenado.push_back(struct_total[i]);
    }
    return struct_ordenado;
}