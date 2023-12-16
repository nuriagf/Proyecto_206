#include "../funciones.h"

//esta funcion nos permite crear un evento
void crearEvento() {
    std:: string nombre, tipo, descripcion, fechaInicio, fechaFin; 
    int precio, aforo, duracion; 

    introducirNombre(nombre); //como eran funciones muy largas se ha creado una función especifica para el nombre
    
    introducirTipoEvento(tipo); //función que además de dar valor al tipo de evento también comprueba si el tipo es correcto
    //prueba de que solo se ponga taller congreso ponencia y seminario

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

    //prueba de que fecha de inicio no puede ser después de fecha final
    introducirFechas(fechaInicio, fechaFin); 

    std::cout << "Introduzca duracion del evento(en minutos)." << std::endl; 
    std::cin >> duracion;

    if(guardarEvento(nombre, tipo, descripcion, precio, aforo, fechaInicio, fechaFin, duracion)) 
        std::cout << "Guardado evento con exito." << std::endl; 
    
}

//sirve para que el usuario pueda nombrar a la actividad
void introducirNombre(std::string& nombre) {

    while(true) {
        std::cout << "Introduzca el nombre del evento (pulsa -enter- en una linea vacia para fianlizar)." << std::endl; 
        //como las actividades pueden tener espacios con este método se recogerá toda la cadena de nombre
        std::cin.ignore();
        while (true) {
            std::string linea;
            std::getline(std::cin, linea); 
                
            if (linea.empty()) { //cuando haya un enter en la linea vacia se saldrá 
                break;
            }

            nombre += linea + " "; //se unen lo que ya hay de nombre más lo que se va leyendo (linea) y se le añaden espacios
        }

        if(comprobarEvento(nombre)) { //una vez añadido el nombre se comprueba si no existe ya
            std::cout << "El nombre del evento ya existe. Introduce otro." << std::endl; 
        }
        else { //si todo está bien se sale
            break;
        }
    }
}

//función que comprueba en el fichero si existe un evento con ese nombre
bool comprobarEvento(std::string& nombre) {
    std::ifstream archivo("eventos.txt");

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de eventos." << std::endl;
        return false;
    }

    std::string linea; 
    std::string nombreEvento = "Nombre: " + nombre;

    while (getline(archivo, linea)) {
        if (linea == nombreEvento) {
            archivo.close();
            return true; // Evento encontrado
        }
    }
    
    archivo.close();
    return false; //si no se ha encontrado
}

void introducirTipoEvento(std::string& tipo) {
    while(true) {
        std::cout << "Introduzca el tipo de evento (congreso, ponencia, taller, seminario)." << std::endl; 
        std::cin >> tipo;

        if (comprobarTipoEvento(tipo)) { //si el tipo de evento no es ninguno de los cuatro lo vuelve a pedir
            break; //si el tipo de evento es correcto se sale
        }
        else {
            std::cout << "No es congreso, ni ponencia, ni taller, ni seminario. Intentalo de nuevo." << std::endl; //si no es correcto se vuelve a pedir
        }
    }
}

//se comprueba si es taller, seminario, congreso o ponencia
bool comprobarTipoEvento(std::string& tipo) {
    for (int i=0; i<tipo.length(); i++) {
        tipo[i] = tolower(tipo[i]); //da igual el tamaño en el que lo escriban, lo pasaremos a minuscula para comparar
    }

    return (tipo=="taller" || tipo=="seminario" || tipo=="congreso" || tipo=="ponencia"); //devolver "true" si está correcto
}

//asignar los valores a las fechas
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

//comprobar que la fecha de inicio sea antes que la fecha de fin
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

//por ultimo se guarda todo en el fichero
bool guardarEvento(std::string& nombre, std::string& tipo, std::string& descripcion, int precio, int aforo, std::string& fechaInicio, std::string& fechaFin, int duracion) {
    std::ofstream archivo("eventos.txt", std::ios::app); //añadir al final del fichero 

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de eventos." << std::endl;
        return false;
    }

    archivo << "Nombre: " << nombre << std::endl; 
    archivo << "Tipo: " << tipo << std::endl; 
    archivo << "Descripcion: " << descripcion << std::endl; 
    archivo << "Precio: " << precio << std::endl;
    archivo << "Aforo: " << precio << std::endl;  
    archivo << "Fecha inicio: " << fechaInicio << std::endl; 
    archivo << "Fecha fin: " << fechaFin << std::endl; 
    archivo << "Duracion: " << duracion << std::endl; 
    archivo << std::endl; 

    return true; 

    archivo.close();
}