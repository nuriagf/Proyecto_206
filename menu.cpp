#include "funciones.h"

//hacer que no hagan break, sino que vuelvan al menú principal

void menu() {
    int op; 
    std::cout << "Escoge una opcion: " << std::endl; 
    std::cout << "1- Visitante." << std::endl; 
    std::cout << "2- Usuario." << std::endl; 
    std::cout << "3- Salir. " << std:: endl; 
    std::cin >> op; 

    switch (op) {
        case 1:
            listarEvento();
            menu();
        
        case 2: {
            std::string correo;
            while (true){ 
                std::cout << std::endl;
                std::cout << "Ingrese correo de la UCO: ";
                std::cin >> correo;
                if(comprobarCorreo(correo)==1){
                    inicioAdministrador();
                    menu();
                }
                if(comprobarCorreo(correo)==2){
                    inicioUsuario();
                    menu();
                }
            }
            break; 
        }

        case 3: 
            exit(0); //sale definitivamente
            break; 

        default: 
            std::cout << "Opcion no valida. " << std::endl; 
    }
}


void inicioAdministrador() {
    std::cout << std::endl; 
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
                menu();
            }
        }
    }
}

void menuAdministrador() {
    while(true) { //solo saldrá si el administrador selecciona salir
        int op; 
        std::cout << std::endl;
        std::cout << "Menu Administrador." << std::endl;
        std::cout << "Escoge una opcion: " << std::endl; 
        std::cout << "1- Listar eventos." << std::endl; 
        std::cout << "2- Crear evento. " << std::endl; 
        std::cout << "3- Salir." << std::endl;
        std::cin >> op; 

        switch (op) {
            case 1:
                listarEvento();
                break;
            
            case 2: 
                crearEvento();
                break;

            case 3: 
                return;  //vuelve a la función que le llamó

            default: 
                std::cout << "Opcion no valida. " << std::endl; 
            //borrar Evento
        }
    }
}

void inicioUsuario() {
    int op; 
    std::cout << std::endl; 
    std::cout << "Escoge una opcion: " << std::endl; 
    std::cout << "1- Iniciar sesion." << std::endl; 
    std::cout << "2- Registrarse. " << std::endl; 
    std::cout << "3- Salir. " << std::endl;
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
                        menu();
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
                        menu();
                    }
                }
            }
            break; 

        case 3: 
            return; //vuelve a la función que le llamó
        //borrar Evento
    }
}

void menuUsuario() {
    while(true) { //solo saldrá si el usuario selecciona salir
        int op; 
        std::cout << std::endl;
        std::cout << "Menu Usuario" << std::endl; 
        std::cout << "Escoge una opcion: " << std::endl; 
        std::cout << "1- Listar eventos." << std::endl; 
        std::cout << "2- Inscribirse a Evento. " << std::endl; 
        std::cout << "3- Salir. " << std::endl; 
        std::cin >> op; 

        switch (op) {
            case 1:
                listarEvento();
                break;
            
            case 2: 
                preinscribirEvento();
                break; 

            case 3: 
                return;  //vuelve a la función que le llamó
                
            default: 
                std::cout << "Opcion no valida. " << std::endl; 
        }
    }
}