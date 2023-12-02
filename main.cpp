#include "funciones.h"


int main(){

    std::string usuario1, contrasena1;

    while (true){
        std::cout << "Ingrese el nombre de usuario: ";
        std::cin >> usuario1;
        if(comprobarUsuario(usuario1)){
            std::cout << "Ingrese la contraseña: ";
            std::cin >> contrasena1;
            if(inicioSesion(usuario1, contrasena1)){
                break;
            }
        }
    }
    return 0;
}