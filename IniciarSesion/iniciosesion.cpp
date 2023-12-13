#include "../funciones.h"

//esta funcion nos permite saber si se trata de un usuario o de un administrador
int comprobarCorreo(std::string& correo){
    if (correo.length() != 15) { //si no tiene el correo una longitud de 15 es que está mal 
        return 0;
    }
    char tipoUsuario = correo[2];
    if (tipoUsuario == '1') {
        return 1; //1 es administrador
    }
    if(tipoUsuario == '2') {
        return 2; //2 es usuario
    }
    return 0; 
}

//comrpobamos que el usurio exista en el fichero
bool validarNombreUsuario(std::string& usuario) {
    std::ifstream archivo("registro.txt");

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de registro." << std::endl;
        return false;
    }

    std::string usuarioGuardado;

    while (archivo >> usuarioGuardado) {
        if (usuario == usuarioGuardado) {
            archivo.close();
            return true; // Usuario y contraseña coinciden
        }
    }

    std::cout << "Nombre de usuario no encontrado. Intentalo otra vez." << std::endl;
    archivo.close();
    return false; // Usuario o contraseña incorrectos
}

//comprobamos que los datos existan en el fichero
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

//comprobamos si el usuario es un administrador o usuario, en caso de no ser ni uno ni otro no es válido el usuario introducido
bool comprobarUsuario(std::string& usuario){
    bool correcto=true;
    if (usuario.length() != 8) {
        std::cout << "El nombre de usuario es incorrecto. Intente nuevamente." << std::endl;
        correcto=false;
        return correcto;
    }
    char tipoUsuario = usuario[2];
    if (tipoUsuario != '1' && tipoUsuario != '2') {
        std::cout << "Tipo de usuario no reconocido. El tercer caracter debe ser '1' o '2'. Intente nuevamente." << std::endl;
        correcto=false;
    }
    return correcto;
}

//despues de validar si el usuairo y la contraseña son correctos se inicia sesión
bool inicioSesion(std::string& usuario, std::string& contrasena) {

    bool correcto;
    if (validarUsuario(usuario, contrasena)) {
        std::cout << "Inicio de sesion exitoso." << std::endl;
        correcto=true;
    } else {
        std::cout << "Usuario o contrasena incorrectos. Intente nuevamente." << std::endl;
        correcto=false;
    }
    return correcto;  
}
