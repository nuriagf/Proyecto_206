#include "../funciones.h"

NO FUNCIONA AÚN
void modificarEvento(std::string& nombre) {
    std::ifstream archivo("eventos.txt");
    std::ofstream aux("auxiliar.txt");

    if (!archivo.is_open() || !aux.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        exit(0);
    }

    std::string linea;
    bool encontrado = false;

    while (std::getline(archivo, linea)) {
        if (linea.find("Nombre: " + nombre) != std::string::npos) {
            encontrado = true;

            std::cout << "Nuevo nombre: ";
            std::getline(std::cin, nombre);
            aux << "Nombre: " << nombre << std::endl;

            std::cout << "Nuevo tipo: ";
            std::getline(std::cin, linea);
            aux << "Tipo: " << linea << std::endl;

            std::cout << "Nueva descripción: ";
            std::getline(std::cin, linea);
            aux << "Descripcion: " << linea << std::endl;

            std::cout << "Nuevo precio: ";
            std::getline(std::cin, linea);
            aux << "Precio: " << linea << std::endl;

            std::cout << "Nuevo aforo: ";
            std::getline(std::cin, linea);
            aux << "Aforo: " << linea << std::endl;

            std::cout << "Nueva fecha de inicio: ";
            std::getline(std::cin, linea);
            aux << "Fecha inicio: " << linea << std::endl;

            std::cout << "Nueva fecha de fin: ";
            std::getline(std::cin, linea);
            aux << "Fecha fin: " << linea << std::endl;

            std::cout << "Nueva duración: ";
            std::getline(std::cin, linea);
            aux << "Duracion: " << linea << std::endl;
        } else {
            aux << linea << std::endl;
        }
    }

    archivo.close();
    aux.close();

    if (!encontrado) {
        std::cout << "Evento no encontrado.\n";
    } else {
        std::remove("eventos.txt");
        std::rename("auxiliar.txt", "eventos.txt");
        std::cout << "Evento modificado exitosamente.\n";
    }
}

/*
void modificarEvento( std::string& nombre) {
    std::ifstream archivo("eventos.txt");
    std::ofstream aux("auxiliar.txt");

    if (!archivo.is_open() || !aux.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        exit(0);
    }

    std::string linea;

    while (std::getline(archivo, linea)) {
        if (linea.find("Nombre: " + nombre) != std::string::npos) {

            std::cout << "Nuevo nombre: ";
            std::string nombre; 
            while (true) {
                std::string linea;
                std::getline(std::cin, linea); 
                    
                if (linea.empty()) { //cuando haya un enter en la linea vacia se saldrá 
                    break;
                }

                nombre += linea + " "; 
            }

            if(comprobarEvento(nombre) == false) {
                aux << "Nombre: " << nombre << std::endl;
            }

            std::cout << "Nuevo tipo: ";
            std::string tipo; 
            std::cin >> tipo;
            if(comprobarTipoEvento(tipo)) {
                aux << "Tipo: " << tipo << std::endl;
            }

            std::cout << "Nueva descripción: ";
            std::cin.ignore();
            std::string descripcion;
            while (true) {
                std::string linea;
                std::getline(std::cin, linea); 
                        
                if (linea.empty()) { //cuando haya un enter en la linea vacia se saldrá 
                    break;
                }

                descripcion += linea + " "; 
            }
            aux << "Descripcion: " << descripcion << std::endl;

            std::cout << "Nuevo precio: ";
            std::getline(std::cin, linea);
            aux << "Precio: " << linea << std::endl;

            std::cout << "Nuevo aforo: ";
            std::getline(std::cin, linea);
            aux << "Aforo: " << linea << std::endl;

            std::cout << "Nueva fecha de inicio: ";
            std::getline(std::cin, linea);
            aux << "Fecha inicio: " << linea << std::endl;

            std::cout << "Nueva fecha de fin: ";
            std::getline(std::cin, linea);
            aux << "Fecha fin: " << linea << std::endl;

            std::cout << "Nueva duración: ";
            std::getline(std::cin, linea);
            aux << "Duracion: " << linea << std::endl;
        } else {
            aux << linea << std::endl;
        }
    }

    archivo.close();
    aux.close();

    std::remove("eventos.txt");
    std::rename("auxiliar.txt", "eventos.txt");
    std::cout << "Evento modificado exitosamente.\n";
}*/