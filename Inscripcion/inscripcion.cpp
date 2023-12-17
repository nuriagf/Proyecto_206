#include "../funciones.h"

//dentro de inscribirse a un evento están los eventos que cuestan algo y los que no
void preinscribirEvento(std::string& usuario, std::string& nombreEvento) {

    int aforo=obtenerAforo(nombreEvento); //obtenemos el aforo
    
    inscripcion(usuario, nombreEvento, aforo);
}

//funcion de inscripcion
bool inscripcion(std::string& usuario, std::string &nombreEvento, int aforo) {
    std::ofstream archivo("inscripciones.txt", std::ios::app);  

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de registro." << std::endl;
        return false;
    }

    if(comprobarInscripcion(usuario, nombreEvento)) {
        std::cout << "La persona ya esta inscrita" << std::endl; 
        return false; 
    }

    int contador = contarAforoInscritos(nombreEvento); //contamos los eventos del fichero, para saber si nos pasamos de aforo
    
    if(contador < aforo ) { //se comrprueba que el aforo del evento no se haya superado
        // Escribe el nuevo usuario y contraseña en el archivo
        archivo << usuario << "-->" << nombreEvento << "\n";
        std::cout << "Inscripcion exitosa." << std::endl; 
    }
    else {
        std::cout << "El aforo esta completo. " << std::endl; 
    }

    archivo.close();
}

//comprobamos que el usuario no se haya inscrito ya en el evento
bool comprobarInscripcion(std::string& usuario, std::string& nombreEvento) {
    std::ifstream archivo("inscripciones.txt");  

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de registro." << std::endl;
        return false;
    }

    std::string linea; 
    std::string inscrip = usuario + "-->" + nombreEvento;

    while (std::getline(archivo, linea)) {
        if (linea == inscrip) {
            archivo.close();
            return true; // Evento encontrado
        }
    }

    archivo.close();
    return false; 
}

//obtemos el aforo del evento
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

//contamos los eventos, que tienen el nombre indicado, en el fichero de inscripciones
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