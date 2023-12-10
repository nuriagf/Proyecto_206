#include "../funciones.h"

//dentro de inscribirse a un evento están los eventos que cuestan algo y los que no
void preinscribirEvento(std::string& usuario, std::string& nombreEvento) {

    Puedo comprobar si el usuario ya se ha inscrito de antes o no

    int precio=obtenerPrecio(nombreEvento); //primero obtenemos el precio del evento

    int aforo=obtenerAforo(nombreEvento); //y obtenemos el aforo

    if (precio == 0) { //si el precio es cero solo se tienen que guardar los datos
        inscripcionSinTarifa(usuario, nombreEvento, aforo);
    }
    else { //sino pues hay que pagar
        inscripcionConTarifa(usuario, nombreEvento, precio, aforo);
    }
}

//si es sin precio se guardan los datos directamente en el fichero
bool inscripcionSinTarifa(std::string& usuario, std::string &nombreEvento, int aforo) {
    std::ofstream archivo("inscripciones.txt", std::ios::app);  

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de registro." << std::endl;
        return false;
    }

    int contador = contarAforoInscritos(nombreEvento); //contamos los eventos del fichero, para saber si nos pasamos de aforo
    
    if(contador < aforo ) { //se comrprueba que el aforo del evento no se haya superado
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

//inscripción con tarifa
bool inscripcionConTarifa(std::string& usuario, std::string &nombreEvento, int precio, int aforo) {
    std::ofstream archivo("inscripciones.txt", std::ios::app);  

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de registro." << std::endl;
        return false;
    }

    int saldo=obtenerSaldo(usuario); //queremos saber el saldo para saber si puede pagarlo o no

    if(saldo < precio) {
        std::cout << "Saldo insuficiente. " << std::endl; 
    }
    else {
        int contador = contarAforoInscritos(nombreEvento); //comprobamos también el aforo
        
        if(contador < aforo ) {
            // Escribe el nuevo usuario y contraseña en el archivo
            insertarCuentaBancaria(usuario);
            archivo << usuario << "-->" << nombreEvento << "\n";
            cobrarEvento(usuario, saldo, precio);
            std::cout << "Inscripcion exitosa." << std::endl; 
            aforo++; 
        }
        else {
            std::cout << "El aforo esta completo. " << std::endl; 
        }
    }
    archivo.close();
}

//obtenemos el precio del evento
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

Faltaria una función, ahora mismo no me acuerdo el qué xd