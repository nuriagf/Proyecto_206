#include "../funciones.h"

bool insertarCuentaBancaria(std::string usuario) {
    
    if(buscarCuenta(usuario) == false) {
        std::ofstream archivo("listaCuentasBancarias.txt", std::ios::app);  

        if (!archivo.is_open()) {
            std::cerr << "Error al abrir el archivo de registro." << std::endl;
            return false;
        }

        int saldo; 

        std::cout << std::endl; 
        std::cout << "Vamos a crear una cuenta bancaria. " << std::endl; 
        std::cout << "Introduce tu saldo. " << std::endl; 
        std::cin >> saldo; 

        archivo << "Usuario: " << usuario << std::endl; 
        archivo << "Saldo: " << saldo << std::endl; 
        archivo << std::endl; 

        std::cout << "Cuenta bancaria creada. " << std::endl; 
         archivo.close();
        return true;
    }
}

bool buscarCuenta(std::string& usuario) {
    std::ifstream archivo("listaCuentasBancarias.txt");  

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de registro." << std::endl;
        return false;
    }

    std::string linea; 
    while (getline(archivo, linea)) {
        if (linea.find("Usuario: " + usuario) == 0) {
            std::cout << "Cuenta bancaria encontrada. " << std::endl; 
            archivo.close();
            return true;
        }
    }

}

int obtenerSaldo(std::string& usuario) {
    std::ifstream archivo("listaCuentasBancarias.txt");

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de registro." << std::endl;
        return -1;
    }

    std::string linea;
    while (getline(archivo, linea)) {
        if (linea.find("Usuario: " + usuario) != std::string::npos) {
            while (getline(archivo, linea)) {
                if (linea.find("Saldo: ") != std::string::npos) { //distinto de invalido o no encontrado
                    std::stringstream stream(linea);
                    std::string etiqueta;
                    int saldo;

                    // Ignorar la etiqueta y obtener el saldo
                    stream >> etiqueta >> saldo;

                    archivo.close();
                    return saldo;
                }
            }
        }
    }
}

void cobrarEvento(std::string& usuario, int precio) {
    std::ifstream archivo("listaCuentasBancarias.txt");
    std::ofstream aux("auxiliar.txt", std::ios::app); //añadir al final del fichero 

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo auxiliar." << std::endl;
        exit(0);
    }

    if (!aux.is_open()) {
        std::cerr << "Error al abrir el archivo de cuentas bancarias." << std::endl;
        exit(0);
    }

    int saldo;
    std::string linea;
    while (getline(archivo, linea)) {
        if (linea.find("Usuario: " + usuario) != std::string::npos) {
            aux << linea << std::endl; 
            while (getline(archivo, linea)) {
                if (linea.find("Saldo: ") != std::string::npos) { //distinto de invalido o no encontrado
                    std::stringstream stream(linea);
                    std::string etiqueta;

                    // Ignorar la etiqueta y obtener el saldo
                    stream >> etiqueta >> saldo;
                    saldo=saldo-precio; 
                    aux << "Saldo: " << saldo << std::endl; 
                }
            }
        }
        else {
            aux << linea << std::endl; 
        }
    }

    archivo.close();
    aux.close();
    std::remove("listaCuentasBancarias.txt");
    std::rename("auxiliar.txt", "listaCuentasBancarias.txt");
}