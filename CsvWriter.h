#pragma once
#include <iostream>
#include <string>
#include <locale>//see utilizan para definir informaci�n espec�fica de la configuraci�n regional
#include <fstream>//para leer los datos del archivo

class CsvWriter
{
	std::string data;
	bool newLine;
public:
	CsvWriter();
	void Write(std::string info);
	void NextLine();
	void Save(std::string path);
};

