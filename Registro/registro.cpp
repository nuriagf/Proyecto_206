#include "../funciones.h"  

//registrarse 
bool registrarUsuario(std::string& usuario, std::string& contrasena) {
    if (validarUsuario(usuario, contrasena)) { //primero se comprueba que no exista ya el usuario
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
        archivo << usuario << " " << contrasena << "\n"; //si no existen se guardan
        std::cout << "Registro exitoso." << std::endl; 

        archivo.close();
        return true;
    }
}