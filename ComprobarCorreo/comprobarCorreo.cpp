#include "../funciones.h"

//esta funcion no permite saber si se trata de un usuario o de un administrador
int comprobarCorreo(std::string& correo){
    if (correo.length() != 15) { //si no tiene el correo una longitud de 15 es que está mal 
        std::cout << "El correo es incorrecto. Intente nuevamente." << std::endl;
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