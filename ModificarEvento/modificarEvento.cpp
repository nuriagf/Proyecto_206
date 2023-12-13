#include "../funciones.h"

bool modificarEvento(std::string& nombre) {
    std::ifstream archivo("eventos.txt");
    std::vector <std::string> vector; 
    std::string linea; 

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el fichero de eventos." << std::endl;
        return false;
    }

    while(getline(archivo, linea)) { //mientras haya lineas que seguir leyendo 
        vector.push_back(linea); 
    }

    std:: string tipo, descripcion, fechaInicio, fechaFin; 
    int precio, aforo, duracion; 
    introducirTipoEvento(tipo);

    std::cout << "Introduzce una descripcion del evento (pulsa -enter- en una linea vacia para fianlizar)." << std::endl; 
    std::cin.ignore();//limpiar buffer
    while (true) { //al igual que con el nombre la descripcion tiene espacios
        std::string linea;
        std::getline(std::cin, linea); 
                
        if (linea.empty()) { //cuando haya un enter en la linea vacia se saldrá 
            break;
        }

        descripcion += linea + " "; 
    }

    std::cout << "Introduzca precio del evento." << std::endl; 
    std::cin >> precio;

    std::cout << "Introduzca aforo del evento." << std::endl; 
    std::cin >> aforo;

    introducirFechas(fechaInicio, fechaFin); 

    std::cout << "Introduzca duracion del evento(en minutos)." << std::endl; 
    std::cin >> duracion;

    archivo.close();
    std::remove("eventos.txt");

    guardarNuevosDatos(vector, nombre, tipo, descripcion, precio, aforo, fechaInicio, fechaFin, duracion);
}

bool guardarNuevosDatos(std::vector<std::string> vector, std::string& nombre, std::string& tipo, std::string& descripcion, int precio, int aforo, std::string& fechaInicio, std::string& fechaFin, int duracion) {
    std::ofstream aux("auxiliar.txt");

    if (!aux.is_open()) {
        std::cerr << "Error al abrir el fichero auxiliar." << std::endl;
        return false;
    }

    for (int i=0; i < vector.size(); i++) {
        if(vector[i].find("Nombre: " + nombre) != std::string::npos) {
            vector[i + 1] = "Tipo: " + tipo;
            vector[i + 2] = "Descripcion: " + descripcion;
            vector[i + 3] = "Precio: " + std::to_string(precio);
            vector[i + 4] = "Aforo: " + std::to_string(aforo);
            vector[i + 5] = "Fecha inicio: " + fechaInicio;
            vector[i + 6] = "Fecha fin: " + fechaFin;
            vector[i + 7] = "Duracion: " + std::to_string(duracion);
        }
    }

    for (const auto& lineaAux : vector) {
        aux << lineaAux << std::endl; 
    }

    aux.close();
    std::rename("auxiliar.txt", "eventos.txt");
    return true;
}