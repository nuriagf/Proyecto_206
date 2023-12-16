#include "funciones.h"

//menu principal 
void menu() {
    int op; 
    std::cout << "Escoge una opcion: " << std::endl; 
    std::cout << "1- Visitante." << std::endl; 
    std::cout << "2- Usuario." << std::endl; 
    std::cout << "3- Salir. " << std:: endl; 
    std::cin >> op; 

    switch (op) {
        case 1:
            std::cout << "Esta opcion solo muestra los eventos disponibles. " << std::endl; 
            std::cout << std::endl; 
            listarEvento();
            menu();
        
        case 2: {
            std::string correo;
            while (true){ 
                std::cout << std::endl;
                std::cout << "Ingrese correo de la UCO: ";
                std::cin >> correo;
                if(comprobarCorreo(correo)==1){ //comprobamos que clase de usuario es para mandarle a un menú o a otro
                    inicioAdministrador();
                    menu();
                }
                if(comprobarCorreo(correo)==2){
                    inicioUsuario();
                    menu();
                }
                else {
                    std::cout << "Correo no valido." << std::endl; 
                }
            }
            break; 
        }

        case 3: 
            exit(0); //sale definitivamente
            break; 

        default: 
            std::cout << "Opcion no valida. " << std::endl; 
            menu(); 
    }
}

//si es administrador inicia sesión directamente, ya que tiene cuenta ya creada
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
                menuAdministrador(); //se le manda al menú admistrador
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
        std::cout << "3- Eliminar evento. " << std::endl; 
        std::cout << "4- Modificar evento. " << std::endl; 
        std::cout << "5- Cerrar sesion." << std::endl; 
        std::cin >> op; 

        switch (op) {
            case 1:
                listarEvento();
                break;
            
            case 2: 
                crearEvento();
                break;

            case 3: {
                std::string nombre; 
                while (true) {
                    std::cout << "Introduce el nombre del evento a eliminar. " << std::endl; 
                    std::cin >> nombre; 

                    if(comprobarEvento(nombre) == true) {
                        eliminarEvento(nombre);
                        break;
                    }
                    else {
                        std::cout << "Nombre no encontrado. Intentalo otra vez. " << std::endl;
                    }
                }
                break; 
            }
            case 4: {
                std::string nombre; 
                while (true) {
                    std::cout << "Introduce el nombre del evento a modificar. " << std::endl; 
                    std::cin >> nombre; 

                    if(comprobarEvento(nombre) == true) {
                        modificarEvento(nombre);
                        break;
                    }
                    else {
                        std::cout << "Nombre no encontrado. Intentalo otra vez. " << std::endl;
                    }
                }
                break; 
            }

            case 5: 
                menu(); 

            default: 
                std::cout << "Opcion no valida. " << std::endl; 
                menuAdministrador(); 
        }
    }
}

//si es usuario o inicia sesion o se registra
void inicioUsuario() {
    int op; 
    std::cout << std::endl; 
    std::cout << "Escoge una opcion: " << std::endl; 
    std::cout << "1- Iniciar sesion." << std::endl; 
    std::cout << "2- Registrarse. " << std::endl; 
    std::cout << "3- Volver atras. " << std::endl;
    std::cin >> op; 

    std::string usuario1, contrasena1;

    switch (op) {
        case 1:
            while (true){
                std::cout << "Ingrese el nombre de usuario: ";
                std::cin >> usuario1;
                if(comprobarUsuario(usuario1) && usuario1[2] == '2'){
                    std::cout << "Ingrese la contrasena: ";
                    std::cin >> contrasena1;
                    if(inicioSesion(usuario1, contrasena1)){
                        menuUsuario();
                        menu();
                    }
                }
                else {
                    std::cout << "Usuario no valido."  << std::endl;
                }
            }
            break;
        
        case 2: 
            while (true){
                std::cout << "Ingrese el nombre de usuario: ";
                std::cin >> usuario1;
                if(comprobarUsuario(usuario1) && usuario1[2] == '2') {
                    std::cout << "Ingrese la contrasena: ";
                    std::cin >> contrasena1;
                    if(registrarUsuario(usuario1, contrasena1)) {
                        inicioUsuario();
                    }
                }
                else {
                    std::cout << "Usuario no valido."  << std::endl;
                }
            }
            break; 

        case 3: 
            menu();
        default: 
            std::cout << "Opcion no valida. " << std::endl; 
            inicioUsuario();
    }
}

void menuUsuario() {
    while(true) { //solo saldrá si el usuario selecciona salir
        int op; 
        std::cout << std::endl;
        std::cout << "Menu Usuario" << std::endl; 
        std::cout << "Escoge una opcion: " << std::endl; 
        std::cout << "1- Listar eventos." << std::endl; 
        std::cout << "2- Inscribirse a evento. " << std::endl; 
        std::cout << "3- Cerrar sesion. " << std::endl; 
        std::cin >> op; 

        switch (op) {
            case 1:
                listarEvento();
                break;
            
            case 2:  {
                std::string usuario, nombreEvento;
                    while(true) {
                        std::cout << "Introduce tu usuario. " << std::endl; 
                        std::cin >> usuario; 
                        if(validarNombreUsuario(usuario)) { //comprueba que el usuario existe
                            std::cout << "Introduce nombre del evento." << std::endl; 
                            std::string nombreEvento; 
                            std::cin >> nombreEvento; 

                            if(comprobarEvento(nombreEvento)) { // comprueba que el evento existe
                                preinscribirEvento(usuario, nombreEvento);
                                break; 
                            }
                            else {
                                std::cout << "No se encuentra el evento" << std::endl; 
                            }
                        }
                    }
                
                break; 
            }
            case 3: 
                menu();
                
            default: 
                std::cout << "Opcion no valida. " << std::endl; 
                menuUsuario();
        }
    }
}