#include "../funciones.h"

int comprobarCorreo(std::string& correo){
    if (correo.length() != 15) {
        std::cout << "El correo es incorrecto. Intente nuevamente." << std::endl;
        return 0;
    }
    char tipoUsuario = correo[2];
    if (tipoUsuario == '1') {
        return 1; 
    }
    if(tipoUsuario == '2') {
        return 2; 
    }
    return 0; 
}