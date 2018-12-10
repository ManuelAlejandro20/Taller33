#pragma once
#include <string>
#include <iostream>

using namespace std;

class Menu
{
public:
	Menu();
	void menuPrincipal();
	void submenuCaptura();
	void submenuDex();
	void subemenuMochila();
	bool validacion(string str);
	~Menu();
};

