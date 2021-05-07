#include "funciones.h"

using namespace std;

string cambiar_comilla_por_cero(string sentencia)                       //función que toma como parámetro una variable de tipo string
                                                                        //con la finalidad de cambiar las comillas por un "cero" lo que
{                                                                       //permite con la función STOF, convertir los valores a FLOAT
    //comillas dobles en ascii = 34                                     //y así compararlos posteriormente.
    char string_sin_comillas[999999];                                   //**Se recorre la sentencia como un arreglo, y si el valor encontrado
    for (unsigned int i=0;i<sentencia.size();i++)                       //es ASCII 34 (Comillas dobles), entonces al valor en esa posición
    {                                                                   //se le asigna '0', esto debido a que la funcion STOF, termina cuando detecta un caracter.
        if (sentencia.at(i)!=34)         
            {string_sin_comillas[i] = sentencia.at(i);}
        else {string_sin_comillas[i] = '0';}
    }
    string resultado = string_sin_comillas;
    return resultado;
    }



vector<datosEstudiantes> llenar_struct(string archivo)                   //función que recibe como parametro el nombre del archivo
{                                                                        //y retorna un struct de tipo vector, en donde estarán almacenados
    vector<datosEstudiantes> result;                                     //todos los datos del archivo, ordenados por fila y columna.
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
        result.push_back(estudiante[cont]);
    }
    return result;
}

vector<datosEstudiantes> primeros_cien_promedios(vector<datosEstudiantes> struct_total, int opcion_de_promedio)     //Esta función recibe como parámetro un vector de tipo struct, y un entero el cual es una opción estandarizada.
{                                                                                                                   //La función cumple con ordenar los datos del struct de mayor a menor, según la opcion seleccionada, posteriormente
    /*                                                                                                                llena un struct nuevo, con sólo los primeros cien datos ordenados.
    OPCION DE ORDEN:
        1: promedio general
        2: Promedio Arte y edFisica
        3: Promedio Lengua y Historia
        4: Promedio Tecnología Mate y Ciencias
    */
    vector<datosEstudiantes> struct_ordenado;
    string aux_id, aux_nombre;
    float aux_proml, aux_promi, aux_promm, aux_promc, aux_promh, aux_proma, aux_promt, aux_prome, aux_promg;
    for (unsigned int i = 0; i < struct_total.size(); i++)
    {
        for (unsigned int j = i + 1; j < struct_total.size(); j++)
        {
            if (opcion_de_promedio == 1)
            {
                if (struct_total[i].getPromedioGeneral() < struct_total[j].getPromedioGeneral())
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
            if (opcion_de_promedio == 2)
            {
                if (struct_total[i].getPromedioArtesyEdfisica() < struct_total[j].getPromedioArtesyEdfisica())
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
            if (opcion_de_promedio == 3)
            {
                if (struct_total[i].getPromedioLenguayHistoria() < struct_total[j].getPromedioLenguayHistoria())
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
            if (opcion_de_promedio == 4)
            {
                if (struct_total[i].getPromedioTecMateCiencias() < struct_total[j].getPromedioTecMateCiencias())
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
        }
    }
    for (unsigned int k = 0; k < 100; k++)
    {
        struct_ordenado.push_back(struct_total[k]);
    }
    return struct_ordenado;
}

vector<datosEstudiantes> mayor_menor_promedio(vector<datosEstudiantes> struct_total, int opcion_de_orden)       //Función similar a la anterior, con la diferencia
{                                                                                                               //que esta ordena los datos de mayor a menor
    /*                                                                                                          //(en el caso de id es menor a mayor)
    OPCION DE ORDEN:                                                                                            //
        1: promedio general
        2: Promedio Arte y edFisica
        3: Promedio Lengua y Historia
        4: Promedio Tecnología Mate y Ciencias
        5: POR ID
    */
    vector<datosEstudiantes> struct_ordenado;
    string aux_id,aux_nombre;
    float aux_proml,aux_promi,aux_promm,aux_promc,aux_promh,aux_proma,aux_promt,aux_prome,aux_promg;
    for (unsigned int i=0;i<struct_total.size();i++)
    {
        for (unsigned int j = i+1; j<struct_total.size();j++)
        {
            if (opcion_de_orden == 1)
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

            if (opcion_de_orden == 2)
            {
                if (struct_total[i].getPromedioArtesyEdfisica()<struct_total[j].getPromedioArtesyEdfisica())
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
            if (opcion_de_orden == 3)
            {
                if (struct_total[i].getPromedioLenguayHistoria()<struct_total[j].getPromedioLenguayHistoria())
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
            if (opcion_de_orden == 4)
            {
                if (struct_total[i].getPromedioTecMateCiencias() < struct_total[j].getPromedioTecMateCiencias())
                if (struct_total[i].getPromedioTecMateCiencias()<struct_total[j].getPromedioTecMateCiencias())
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
            if (opcion_de_orden == 5)
            {
                /*int x,y;
                x = struct_total[i].getIdInt();
                y = struct_total[j].getIdInt();*/
                if (struct_total[i].getNombre()>struct_total[j].getNombre())
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
        }
    }
    for (unsigned int k = 0; k < struct_total.size(); k++)
    {
        struct_ordenado.push_back(struct_total[k]);
    }
    return struct_ordenado;
}

vector<datosEstudiantes> eliminar_estudiantes_seleccionados(vector<datosEstudiantes> struct_total, vector<datosEstudiantes> struct_seleccionados)   
{
    vector<datosEstudiantes> resultado;                                 //Esta funcion recibe como parámetro un vector de tipo struct, con los estudiantes "globales"
    float cero = 0.0;                                                   //y otro parámetro con los estudiantes que fueron seleccionados,
    for (unsigned int i = 0; i < struct_seleccionados.size(); i++)      //con la finalidad de buscar en el struct global, aquellos estudiantes que coincidan con
    {                                                                   //los seleccionados, y así eliminarlos, y retornar un nuevo vector de tipo struct que contenga    
        string aux = struct_seleccionados[i].getId();                   //los estudiantes restantes.
        for (unsigned int j = 0; j < struct_total.size(); j++)
        {
            if (struct_total[j].getId() == aux)
            {
                struct_total[j].setId("eliminado");
                struct_total[j].setNombre("eliminado");
                struct_total[j].setPromedioGeneral_valor(cero);
                struct_total[j].setPromedioLenguaje(cero);
                struct_total[j].setPromedioIngles(cero);
                struct_total[j].setPromedioMatematicas(cero);
                struct_total[j].setPromedioCiencias(cero);
                struct_total[j].setPromedioHistoria(cero);
                struct_total[j].setPromedioTecnologia(cero);
                struct_total[j].setPromedioArtes(cero);
                struct_total[j].setPromedioEdfisica(cero);
            }
        }
    }
    for (unsigned int k = 0; k < struct_total.size(); k++)
    {
        if (struct_total[k].getPromedioGeneral() == cero
         || struct_total[k].getPromedioLenguaje() == cero 
         || struct_total[k].getPromedioMatematicas() == cero 
         || struct_total[k].getPromedioIngles() == cero 
         || struct_total[k].getPromedioCiencias() == cero 
         || struct_total[k].getPromedioHistoria() == cero 
         || struct_total[k].getPromedioTecnologia() == cero 
         || struct_total[k].getPromedioArtes() == cero 
         || struct_total[k].getPromedioEdfisica() == cero)
        {
        }
        else
        {
            resultado.push_back(struct_total[k]);
        }
    }

    return resultado;
}

void llenar_csv(vector<datosEstudiantes> e, int opcion, string ruta)
{
    fstream archivo;
    if (opcion == 1)                                                                           //Opcion de los 100 mejores promedios
    {   
        string ubicacion = ruta.append("maximos.csv");  
        fstream CreateFile(ubicacion, ios::out);                                                //Crea el .CSV en la ubicacion del .CSV de origen
        CreateFile << "ID;Nombre;promedio general" << endl;                                    //Creando las columnas del .CSV
        archivo.open(ubicacion, ios::app);  
        for (int i = 0; i < 100; i++)                                                           //Llenando el archivo según estudiantes solicitados
        {
            archivo << e[i].id << ";" << e[i].nombre << ";" << e[i].promedio_general << endl;
        }
        archivo.close();
    }
    if (opcion == 2)                                                                            //Opcion de los 100 mejores estudiantes artisticos                                                                            
    {
        string ubicacion = url.append("artistico.csv");
        fstream CreateFile(ubicacion, ios::out);
        CreateFile << "ID;Nombre;promedio arte y edfisica" << endl;
        archivo.open(ubicacion, ios::app);
        for (int i = 0; i < 100; i++)
        {
            archivo << e[i].id << ";" << e[i].nombre << ";" << e[i].getPromedioArtesyEdfisica() << endl;
        }
        archivo.close();
    }
    if (opcion == 3)                                                                            //Opcion de los 100 mejores estudiantes humanistas
    {
        string ubicacion = url.append("humanismo.csv");
        fstream CreateFile(ubicacion, ios::out);
        CreateFile << "ID;Nombre;promedio lengua e historia" << endl;
        archivo.open(ubicacion, ios::app);
        for (int i = 0; i < 100; i++)
        {
            archivo << e[i].id << ";" << e[i].nombre << ";" << e[i].getPromedioLenguayHistoria() << endl;
        }
        archivo.close();
    }
    if (opcion == 4)                                                                            //Opcion de los 100 mejores estudiantes tecnicos
    {
        string ubicacion = url.append("tecnicos.csv");
        fstream CreateFile(ubicacion, ios::out);
        CreateFile << "ID;Nombre;promedio tecnologia, matematicas y ciencias naturales" << endl;
        archivo.open(ubicacion, ios::app);
        for (int i = 0; i < 100; i++)
        {
            archivo << e[i].id << ";" << e[i].nombre << ";" << e[i].getPromedioTecMateCiencias() << endl;
        }
        archivo.close();
    }
}

string obtener_ruta(string ruta)                    //Permite obtener la ruta
{
    int cantidad = ruta.size() - 1;
    int estudiantescsv = ruta.size() - 16;
    for(int i = cantidad; i > estudiantescsv; i--)
    {
        ruta.pop_back();
    }
    return ruta;
}

/*string obtener_url(string url_completa)
{
    string url;
    for(int i = url_completa.length(); i<0; i--)
    {
        if(url_completa[i] == "/" )
        {
            url = url_completa;
            break;
        }
        else
        {
            url_completa.pop_back();
        }
    }
    return url;
}*/
