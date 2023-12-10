#include "../funciones.h"  

bool registrarUsuario(std::string& usuario, std::string& contrasena) {
    if (validarUsuario(usuario, contrasena)) {
        std::cout << "Este usuario ya existe." << std::endl; 
        return false;
    }
    else {
        std::ofstream archivo("registro.txt", std::ios::app);  

        if (!archivo.is_open()) {
            std::cerr << "Error al abrir el archivo de registro." << std::endl;
            return false;
        }

        // Escribe el nuevo usuario y contraseña en el archivo
        archivo << usuario << " " << contrasena << "\n";
        std::cout << "Registro exitoso." << std::endl; 

        archivo.close();
        return true;
    }
}