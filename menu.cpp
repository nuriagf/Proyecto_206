#include "funciones.h"

//hacer que no hagan break, sino que vuelvan al menú principal

void menu() {
    int op; 
    std::cout << "Escoge una opcion: " << std::endl; 
    std::cout << "1- Visitante." << std::endl; 
    std::cout << "2- Usuario." << std::endl; 
    std::cin >> op; 

    switch (op) {
        case 1:
            listarEvento();
            break;
        
        case 2: 
            std::string correo;
            while (true){ //mirar esto de true, porque no vamos a ser bool
                std::cout << "Ingrese correo de la UCO: ";
                std::cin >> correo;
                if(comprobarCorreo(correo)==1){
                    inicioAdministrador();
                    break;
                }
                if(comprobarCorreo(correo)==2){
                    inicioUsuario();
                    break;
                }
            }
            break; 
    }
}


void inicioAdministrador() {
    std::cout <<"Inicio Sesion." << std::endl; 
    std::string usuario1, contrasena1;

    while (true){
        std::cout << "Ingrese el nombre de usuario: ";
        std::cin >> usuario1;
        if(comprobarUsuario(usuario1)){
            std::cout << "Ingrese la contrasena: ";
            std::cin >> contrasena1;
            if(inicioSesion(usuario1, contrasena1)){
                menuAdministrador();
                break;
            }
        }
    }
}

void menuAdministrador() {
    int op; 
    std::cout << "Menu Administrador." << std::endl;
    std::cout << "Escoge una opcion: " << std::endl; 
    std::cout << "1- Listar eventos." << std::endl; 
    std::cout << "2- Crear evento. " << std::endl; 
    std::cin >> op; 

    switch (op) {
        case 1:
            listarEvento();
            break;
        
        case 2: 
            crearEvento();
            break; 

        //borrar Evento
    }
}

void inicioUsuario() {
    int op; 
    std::cout << "Escoge una opcion: " << std::endl; 
    std::cout << "1- Iniciar sesion." << std::endl; 
    std::cout << "2- Registrarse. " << std::endl; 
    std::cin >> op; 

    std::string usuario1, contrasena1;

    switch (op) {
        case 1:
            while (true){
                std::cout << "Ingrese el nombre de usuario: ";
                std::cin >> usuario1;
                if(comprobarUsuario(usuario1)){
                    std::cout << "Ingrese la contrasena: ";
                    std::cin >> contrasena1;
                    if(inicioSesion(usuario1, contrasena1)){
                        menuUsuario();
                        break;
                    }
                }
            }
            break;
        
        case 2: 
            while (true){
                std::cout << "Ingrese el nombre de usuario: ";
                std::cin >> usuario1;
                if(comprobarUsuario(usuario1)){
                    std::cout << "Ingrese la contrasena: ";
                    std::cin >> contrasena1;
                    if(registrarUsuario(usuario1, contrasena1)) {
                        menuUsuario();
                        break;
                    }
                }
            }
            break; 

        //borrar Evento
    }
}

void menuUsuario() {
    std::cout << "Menu Usuario" << std::endl; 
    std::cout << "Escoge una opcion: " << std::endl; 
    std::cout << "1- Listar eventos." << std::endl; 
    std::cout << "2- Inscribirse a Evento. " << std::endl; 
    std::cin >> op; 

    switch (op) {
        case 1:
            listarEvento();
            break;
        
        case 2: 
            inscribirseEvento();
            break; 

        //borrar Evento
    }
}