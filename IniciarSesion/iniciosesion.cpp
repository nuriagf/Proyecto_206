#include "../funciones.h"


bool validarUsuario(std::string& usuario, std::string& contrasena) {
    std::ifstream archivo("registro.txt");

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de registro." << std::endl;
        return false;
    }

    std::string usuarioGuardado;
    std::string contrasenaGuardada;

    while (archivo >> usuarioGuardado >> contrasenaGuardada) {
        if (usuario == usuarioGuardado && contrasena == contrasenaGuardada) {
            archivo.close();
            return true; // Usuario y contraseña coinciden
        }
    }

    archivo.close();
    return false; // Usuario o contraseña incorrectos
}

bool comprobarUsuario(std::string& usuario){
    bool correcto=true;
    if (usuario.length() != 8) {
        std::cout << "El nombre de usuario es incorrecto. Intente nuevamente." << std::endl;
        correcto=false;
        return correcto;
    }
    char tipoUsuario = usuario[2];
    if (tipoUsuario != '1' && tipoUsuario != '2') {
        std::cout << "Tipo de usuario no reconocido. El tercer carácter debe ser '1' o '2'. Intente nuevamente." << std::endl;
        correcto=false;
    }
    return correcto;
}

bool inicioSesion(std::string& usuario, std::string& contrasena) {

    bool correcto;
    if (validarUsuario(usuario, contrasena)) {
        std::cout << "Inicio de sesión exitoso." << std::endl;
        correcto=true;
    } else {
        std::cout << "Usuario o contraseña incorrectos. Intente nuevamente." << std::endl;
        correcto=false;
    }
    return correcto;  
}
