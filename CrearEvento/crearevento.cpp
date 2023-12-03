#include "../funciones.h"

void crearEvento() {
    std:: string nombre, tipo, descripcion, fechaInicio, fechaFin; 
    int duracion; 

    std::cout << "Introduzca el nombre del evento" << std::endl; 
    std::cin >> nombre;

    if(comprobarEvento(nombre)) { //si el evento ya existe se sale
        return; 
    } 

    std::cout << "Introduzca el tipo de evento" << std::endl; 
    std::cin >> tipo;

    std::cout << "Introduzce una descripcion del evento" << std::endl; 
    std::cin >> descripcion;

    std::cout << "Introduzca fecha de inicio (AAAA-MM-DD)" << std::endl; 
    std::cin >> fechaInicio;

    std::cout << "Introduzca fecha de fin (AAAA-MM-DD)" << std::endl; 
    std::cin >> fechaFin;

    std::cout << "Introduzca duracion del evento(en minutos)" << std::endl; 
    std::cin >> duracion;

    if(guardarEvento(nombre, tipo, descripcion, fechaInicio, fechaFin, duracion)) 
        std::cout << "Guardado evento con exito" << std::endl; 
}

bool comprobarEvento(std::string& nombre) {
    std::ifstream archivo("eventos.txt");

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de eventos." << std::endl;
        return false;
    }

    std::string linea; 
    
    while (getline(archivo, linea)) {
        if (linea.find("Nombre: " + nombre) == 0) {
            std::cout << "Ya existe un evento con ese nombre" << std::endl; 
            archivo.close();
            return true; // Evento encontrado 
        }
    }

    archivo.close();
    return false; 
}

bool guardarEvento(std::string& nombre, std::string& tipo, std::string& descripcion, std::string& fechaInicio, std::string& fechaFin, int duracion) {
    std::ofstream archivo("eventos.txt", std::ios::app);

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de eventos." << std::endl;
        return false;
    }

    archivo << "Nombre: " << nombre << std::endl; 
    archivo << "Tipo: " << tipo << std::endl; 
    archivo << "Descripcion: " << descripcion << std::endl; 
    archivo << "Fecha inicio: " << fechaInicio << std::endl; 
    archivo << "Fecha fin: " << fechaFin << std::endl; 
    archivo << "Duracion: " << duracion << std::endl; 
    return true; 

    archivo.close();
}