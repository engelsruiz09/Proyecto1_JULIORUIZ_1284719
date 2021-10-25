#include "CsvReader.h"

CsvReader::CsvReader(std::string path)
{
    //para la lectura del csv 
    setlocale(LC_ALL, "spanish"); // ANSI Codification
    content = "";//dentro de la variable content se va guardar todo texto de las canciones
    cursor = 0;//un cursor literalmente ;v, que se posiciona en todo el string de canciones

    std::ifstream file(path);

    std::string data;
    while(std::getline(file, data))
        content += data + ",";
    file.close();
}
// content = "cancion1, cancion2, cancion3, cancion4"
bool CsvReader::Read(std::string& data)
{
    data = "";//vacia la variable de entrada

    if (cursor >= content.length())
        return false;//por si no encuentra nada en content o no a podido leer nada

    while (true)
    {
        if (cursor >= content.length())//ha llegado al final de la cadena
            return true;//hasta aqui llega por que ya termino de leer la cadena
        if (content[cursor] == ',') {//si se encuentra una coma
            cursor++;//pasa a la siguiente 
            return true;//lo lee satisfactoriamente y lo devuelve
        }
        data += content[cursor];//agrega la letra a la data actual la primera donde este apuntando cursor y asi sucesivamente
        cursor++;//recorre cada letra del arreglo de nombres
    }
}