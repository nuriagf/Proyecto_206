#include <string>
#include <iostream>

void inicioSesion(std::string usuario) {

    while (true) {
        // Verificar si el usuario tiene 8 caracteres
        if (usuario.length() != 8) {
            std::cout << "El nombre de usuario es incorrecto. Intente nuevamente." << std::endl;
            continue;
        }

        // Obtener el tercer carácter del nombre de usuario
        char tipoUsuario = usuario[2];

        // Verificar el tipo de usuario
        if (tipoUsuario == '1') {
            std::cout << "Inicio de sesión exitoso como administrador." << std::endl;
            break;
        } else if (tipoUsuario == '2') {
            std::cout << "Inicio de sesión exitoso como asistente." << std::endl;
            break;
        } else {
            std::cout << "Tipo de usuario no reconocido. Intente nuevamente." << std::endl;
        }
    }
}
