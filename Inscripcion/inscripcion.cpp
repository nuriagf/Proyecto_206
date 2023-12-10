#include "../funciones.h"

void preinscribirEvento(std::string& usuario, std::string& nombreEvento) {

    //puedo comprobar si el usuario ya se ha inscrito de antes o no

    int precio=obtenerPrecio(nombreEvento);

    int aforo=obtenerAforo(nombreEvento);

    if (precio == 0) {
        inscripcionSinTarifa(usuario, nombreEvento, aforo);
    }
    else {
        inscripcionConTarifa(usuario, nombreEvento, precio, aforo);
    }
}

bool inscripcionSinTarifa(std::string& usuario, std::string &nombreEvento, int aforo) {
    std::ofstream archivo("inscripciones.txt", std::ios::app);  

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de registro." << std::endl;
        return false;
    }

    int contador = contarAforoInscritos(nombreEvento);
    
    if(contador < aforo ) {
        // Escribe el nuevo usuario y contraseña en el archivo
        archivo << usuario << "-->" << nombreEvento << "\n";
        std::cout << "Inscripcion exitosa." << std::endl; 
        aforo++; 
    }
    else {
        std::cout << "El aforo esta completo. " << std::endl; 
    }

    archivo.close();
}

bool inscripcionConTarifa(std::string& usuario, std::string &nombreEvento, int precio, int aforo) {
    std::ofstream archivo("inscripciones.txt", std::ios::app);  

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de registro." << std::endl;
        return false;
    }

    insertarCuentaBancaria(usuario);

    int saldo=obtenerSaldo(usuario);

    if(saldo < precio) {
        std::cout << "Saldo insuficiente. " << std::endl; 
    }
    else {
        int contador = contarAforoInscritos(nombreEvento);
        
        if(contador < aforo ) {
            // Escribe el nuevo usuario y contraseña en el archivo
            archivo << usuario << "-->" << nombreEvento << "\n";
            cobrarEvento(usuario, precio);
            std::cout << "Inscripcion exitosa." << std::endl; 
            aforo++; 
        }
        else {
            std::cout << "El aforo esta completo. " << std::endl; 
        }
    }
    archivo.close();
}


int obtenerPrecio(std::string& nombreEvento) {
    std::ifstream archivo("eventos.txt");

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de registro." << std::endl;
        return -1;
    }

    std::string linea;
    while (getline(archivo, linea)) {
        if (linea.find("Nombre: " + nombreEvento) != std::string::npos) {
            while (getline(archivo, linea)) {
                if (linea.find("Precio: ") != std::string::npos) { //distinto de invalido o no encontrado
                    std::stringstream stream(linea);
                    std::string etiqueta;
                    int precio;

                    // Ignorar la etiqueta y obtener el precio
                    stream >> etiqueta >> precio;

                    archivo.close();
                    return precio;
                }
            }
        }
    }
}

int obtenerAforo(std::string& nombreEvento) {
    std::ifstream archivo("eventos.txt");

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de registro." << std::endl;
        return -1;
    }

    std::string linea;
    while (getline(archivo, linea)) {
        if (linea.find("Nombre: " + nombreEvento) != std::string::npos) {
            while (getline(archivo, linea)) {
                if (linea.find("Aforo: ") != std::string::npos) { //distinto de invalido o no encontrado
                    std::stringstream stream(linea);
                    std::string etiqueta;
                    int aforo;

                    // Ignorar la etiqueta y obtener el aforo
                    stream >> etiqueta >> aforo;

                    archivo.close();
                    return aforo;
                }
            }
        }
    }
}

int contarAforoInscritos (std::string &nombreEvento) { 
    std::ifstream archivo("inscripciones.txt");  

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de registro." << std::endl;
        return -1;
    }

    std::string linea;
    int aforo=0;

    while (getline(archivo, linea)) {
        // Buscar líneas que contienen el evento específico
        if (linea.find("-->" + nombreEvento) != std::string::npos) { //distinto de invalido o no encontrado
            aforo++;
        }
    }

    archivo.close();
    return aforo; 
}