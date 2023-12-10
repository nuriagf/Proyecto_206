#include "../funciones.h"

//hemos creado un fichero para el tema de pagos de las actividades que lo necesiten
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
        std::cout << "Introduce tu saldo. " << std::endl; //se le pide el saldo que tendrá la cuenta
        std::cin >> saldo; 

        //se guardan los datos en el fichero
        archivo << "Usuario: " << usuario << std::endl; 
        archivo << "Saldo: " << saldo << std::endl; 
        archivo << std::endl; 

        std::cout << "Cuenta bancaria creada. " << std::endl; 
         archivo.close();
        return true;
    }
}

//antes de crear una cuenta se comprueba si no existe ya una antes 
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

//queremos obtener el saldo de la cuenta para luego comprobar si tiene suficiente para pagar el evento
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

NO FUNCIONA
//pago del evento
void cobrarEvento(std::string& usuario, int saldo, int precio) {
    std::ifstream archivo("listaCuentasBancarias.txt");
    std::ofstream aux("auxiliar.txt", std::ios::app); //añadir al final del fichero 

    if (!archivo.is_open() || !aux.is_open() ) {
        std::cerr << "Error al abrir el archivo auxiliar." << std::endl;
        exit(0); No sé si funcionaría //es void y lo he puesto como exit
    }

    std::string linea;
    while (getline(archivo, linea)) {
        if (linea.find("Usuario: " + usuario) != std::string::npos) {
            aux << linea << std::endl; 
            while (getline(archivo, linea)) {
                if (linea.find("Saldo: ") + saldo ) { //lee hasta encontrar el saldo
                    saldo=saldo-precio; //se le resta el precio
                    aux << "Saldo: " << saldo << std::endl; //se guarda en el nuevo fichero
                }
                else {
                    aux << linea << std::endl; 
                }
            }
        }
        else {
            aux << linea << std::endl; 
        }
    }

    std::cout << "El evento ha sido pagado. " << std::endl; 
    
    archivo.close();
    aux.close();
    std::remove("listaCuentasBancarias.txt"); //se elimina viejo fichero
    std::rename("auxiliar.txt", "listaCuentasBancarias.txt"); //se renombra nuevo fichero
}