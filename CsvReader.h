#pragma once
#include <iostream>
#include <string>
#include <locale>//see utilizan para definir información específica de la configuración regional
#include <fstream>//para leer los datos del archivo

class CsvReader
{
private:
    int cursor;
    std::string content;
public:
    CsvReader(std::string path);//la ruta del archivo
    bool Read(std::string &data);////los cambios que se hagan a la variable  data dentro de la clase csv  se vean reflejados en el formulario se utiliza el &->indica que esas dos variables van a ser iguales, ya que la variable data viene del formulario
};
