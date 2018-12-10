#include "pch.h"
#include "Menu.h"


Menu::Menu()
{
}

void Menu::menuPrincipal()
{
	bool salir = false;
	string _opcion;
	while (!salir)
	{
		cout << "Bienvenido al sistema\n";
		cout << "1. Buscar Pokémon" << endl;
		cout << "2. Pokédex" << endl;
		cout << "3. Mochila" << endl;
		cout << "\nPor favor escoge una opcion (-1 para salir): ";
		getline(cin, _opcion);
		if (!validacion(_opcion)) continue;
		int opcion = stoi(_opcion);
		system("CLS");
		switch (opcion) {
		case 1:
			//captura
			continue;

		case 2:
			//pokedex
			continue;

		case 3:
			//mochila
			continue;

		case -1:
			cout << "\nHas salido exitosamente del juego\n" << endl;
			salir = true;
			continue;

		default:
			cout << "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
			cout << "XXX Escoge una opcion valida porfavor XXX" << endl;
			cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n" << endl;
			system("PAUSE");
			system("CLS");
			continue;
		}


	}
}


bool Menu::validacion(string str)
{
	try
	{
		stoi(str);

	}
	catch (const std::exception&)
	{
		cout << "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
		cout << "XXX Escoge un numero porfavor XXX" << endl;
		cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n" << endl;
		system("PAUSE");
		system("CLS");
		return false;
	}
	return true;
}

Menu::~Menu()
{
}
