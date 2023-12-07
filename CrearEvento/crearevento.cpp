#include "../funciones.h"

void crearEvento() {
    std:: string nombre, tipo, descripcion, fechaInicio, fechaFin; 
    int duracion; 

    introducirNombre(nombre);
    
    introducirTipoEvento(tipo);
    //prueba de que solo se ponga taller congreso ponencia y seminario

    std::cout << "Introduzce una descripcion del evento (pulsa -enter- en una linea vacia para fianlizar)." << std::endl; 

    std::cin.ignore();//limpiar buffer

    while (true) {
        std::string linea;
        std::getline(std::cin, linea); 
                
        if (linea.empty()) { //cuando haya un enter en la linea vacia se saldrá 
            break;
        }

        descripcion += linea + " "; 
    }
    //prueba de que fecha de inicio no puede ser después de fecha final 
    introducirFechas(fechaInicio, fechaFin);
    
    std::cout << "Introduzca duracion del evento(en minutos)." << std::endl; 
    std::cin >> duracion;

    if(guardarEvento(nombre, tipo, descripcion, fechaInicio, fechaFin, duracion)) 
        std::cout << "Guardado evento con exito." << std::endl; 
    
}

void introducirNombre(std::string &nombre) {

    while(true) {
        std::cout << "Introduzca el nombre del evento (pulsa -enter- en una linea vacia para fianlizar)." << std::endl; 
        std::cin >> nombre;

        while (true) {
            std::string linea;
            std::getline(std::cin, linea); 
                
            if (linea.empty()) { //cuando haya un enter en la linea vacia se saldrá 
                break;
            }

            nombre += linea + " "; 
        }

        if(comprobarEvento(nombre)) {
            std::cout << "El nombre del evento ya existe. Introduce otro." << std::endl; 
        }
        else {
            break;
        }
    }
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
            archivo.close();
            return true; // Evento encontrado 
        }
    }

    archivo.close();
    return false; 
}

void introducirTipoEvento(std::string& tipo) {
    while(true) {
        std::cout << "Introduzca el tipo de evento (congreso, ponencia, taller, seminario)." << std::endl; 
        std::cin >> tipo;

        if (comprobarTipoEvento(tipo)) { //si el tipo de evento no es ninguno de los cuatro lo vuelve a pedir
            break;
        }
        else {
            std::cout << "No es congreso, ni ponencia, ni taller, ni seminario. Intentalo de nuevo." << std::endl;
        }
    }
}

bool comprobarTipoEvento(std::string& tipo) {
    for (int i=0; i<tipo.length(); i++) {
        tipo[i] = tolower(tipo[i]);
    }

    return (tipo=="taller" || tipo=="seminario" || tipo=="congreso" || tipo=="ponencia");
}

void introducirFechas(std::string& fechaInicio, std::string& fechaFin) {
    while(true) {
        std::cout << "Introduzca fecha de inicio (AAAA-MM-DD)." << std::endl; 
        std::cin >> fechaInicio;

        std::cout << "Introduzca fecha de fin (AAAA-MM-DD)." << std::endl; 
        std::cin >> fechaFin;

        if (comprobarFechas(fechaInicio, fechaFin)){
            break; 
        }
        else {
            std::cout << "Intentalo otra vez." << std::endl; 
        }
    }
}

bool comprobarFechas (std::string& fechaInicio, std::string& fechaFin) {
    std::tm tmInicio = {}; 
    std::tm tmFin = {}; 

    // Convierte la fecha de inicio de std::string a std::tm
    std::istringstream ssInicio(fechaInicio); //se utiliza std::istringstream para convertir la cadena de fechaInicio a una estructura std::tm
    ssInicio >> std::get_time(&tmInicio, "%Y-%m-%d"); //se usa get_time para interpretar la cadena con el formato que tiene

    // Convierte la fecha de fin de std::string a std::tm
    std::istringstream ssFin(fechaFin); 
    ssFin >> std::get_time(&tmFin, "%Y-%m-%d");

    if (std::mktime(&tmFin) >= std::mktime(&tmInicio)) { //mktime convierte estructura std::tm a time_t 
        return true; 
    } else {
        std::cout << "La fecha de fin es anterior a la fecha de inicio." << std::endl;
        return false;
    }
}

bool guardarEvento(std::string& nombre, std::string& tipo, std::string& descripcion, std::string& fechaInicio, std::string& fechaFin, int duracion) {
    std::ofstream archivo("eventos.txt", std::ios::app); //añadir al final del fichero 

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
    archivo << std::endl; 
    return true; 

    archivo.close();
}