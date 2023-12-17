#include "funciones.h"

void mostrarSeparador() {
    std::cout << "----------------------------------------" << std::endl;
}

void menu() {
    int opcion;
    mostrarSeparador();
    std::cout << "           MENU PRINCIPAL             " << std::endl;
    mostrarSeparador();
    std::cout << "1- Visitante." << std::endl;
    std::cout << "2- Usuario." << std::endl;
    std::cout << "3- Salir." << std::endl;
    mostrarSeparador();
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion;

    switch (opcion) {
        case 1:
            std::cout << "Esta opcion solo muestra los eventos disponibles." << std::endl;
            std::cout << std::endl;
            listarEvento();
            menu();
            break;

        case 2: {
            std::string correo;
            while (true) {
                std::cout << std::endl;
                std::cout << "Ingrese correo de la UCO: ";
                std::cin >> correo;
                if (comprobarCorreo(correo) == 1) {
                    inicioAdministrador();
                    menu();
                } else if (comprobarCorreo(correo) == 2) {
                    inicioUsuario();
                    menu();
                } else {
                    std::cout << "Correo no valido." << std::endl;
                }
            }
            break;
        }

        case 3:
            exit(0); // Sale definitivamente
            break;

        default:
            std::cout << "Opcion no valida." << std::endl;
            menu();
    }
}


//si es administrador inicia sesión directamente, ya que tiene cuenta ya creada
void inicioAdministrador() {
    std::cout << std::endl; 
    std::cout << "----------- INICIO SESION -----------" << std::endl; 
    std::string usuario, contrasena;

    while (true) {
        std::cout << "Ingrese el nombre de usuario: ";
        std::cin >> usuario;

        if (comprobarUsuario(usuario)) {
            std::cout << "Ingrese la contrasena: ";
            std::cin >> contrasena;

            if (inicioSesion(usuario, contrasena)) {
                menuAdministrador();
                menu();
            }
        }
    }
}

void menuAdministrador() {
    while (true) { // solo saldrá si el administrador selecciona salir
        int opcion; 
        mostrarSeparador();
        std::cout << "        MENU ADMINISTRADOR          " << std::endl;
        mostrarSeparador();
        std::cout << "1- Listar eventos." << std::endl; 
        std::cout << "2- Crear evento." << std::endl; 
        std::cout << "3- Eliminar evento." << std::endl; 
        std::cout << "4- Modificar evento." << std::endl; 
        std::cout << "5- Cerrar sesion." << std::endl; 
        mostrarSeparador();
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                listarEvento();
                break;
            
            case 2: 
                crearEvento();
                break;

            case 3: {
                std::string nombre; 
                while (true) {
                    std::cout << "Introduce el nombre del evento a eliminar: "; 
                    std::cin >> nombre; 

                    if (comprobarEvento(nombre)) {
                        eliminarEvento(nombre);
                        break;
                    } else {
                        std::cout << "Nombre no encontrado. Intentalo otra vez." << std::endl;
                    }
                }
                break; 
            }
            
            case 4: {
                std::string nombre; 
                while (true) {
                    std::cout << "Introduce el nombre del evento a modificar: "; 
                    std::cin >> nombre; 

                    if (comprobarEvento(nombre)) {
                        modificarEvento(nombre);
                        break;
                    } else {
                        std::cout << "Nombre no encontrado. Intentalo otra vez." << std::endl;
                    }
                }
                break; 
            }

            case 5: 
                menu(); 
                break;

            default: 
                std::cout << "Opcion no valida." << std::endl; 
                menuAdministrador(); 
        }
    }
}

void inicioUsuario() {
    int opcion; 
    std::cout << std::endl; 
    mostrarSeparador();
    std::cout << "          MENU DE ASISTENTE          " << std::endl;
    mostrarSeparador();
    std::cout << "1- Iniciar sesion." << std::endl; 
    std::cout << "2- Registrarse." << std::endl; 
    std::cout << "3- Volver atras." << std::endl;
    mostrarSeparador();
    std::cout << "Seleccione una opcion: ";
    std::cin >> opcion; 

    std::string usuario, contrasena;

    switch (opcion) {
        case 1:
            while (true){
                std::cout << "Ingrese el nombre de usuario: ";
                std::cin >> usuario;
                if (comprobarUsuario(usuario) && usuario[2] == '2') {
                    std::cout << "Ingrese la contrasena: ";
                    std::cin >> contrasena;
                    if (inicioSesion(usuario, contrasena)) {
                        menuUsuario();
                        menu();
                    }
                } else {
                    std::cout << "Usuario no valido." << std::endl;
                }
            }
            break;
        
        case 2: 
            while (true){
                std::cout << "Ingrese el nombre de usuario: ";
                std::cin >> usuario;
                if (comprobarUsuario(usuario) && usuario[2] == '2') {
                    std::cout << "Ingrese la contrasena: ";
                    std::cin >> contrasena;
                    if (registrarUsuario(usuario, contrasena)) {
                        inicioUsuario();
                    }
                } else {
                    std::cout << "Usuario no valido." << std::endl;
                }
            }
            break; 

        case 3: 
            menu();
            break;

        default: 
            std::cout << "Opcion no valida." << std::endl; 
            inicioUsuario();
    }
}

void menuUsuario() {
    while (true) { // solo saldrá si el usuario selecciona salir
        int opcion; 
        mostrarSeparador();
        std::cout << "          MENU DE ASISTENTE          " << std::endl;
        mostrarSeparador();
        std::cout << "1- Listar eventos." << std::endl; 
        std::cout << "2- Inscribirse a evento." << std::endl; 
        std::cout << "3- Cerrar sesion." << std::endl; 
        mostrarSeparador();
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion; 

        switch (opcion) {
            case 1:
                listarEvento();
                break;
            
            case 2:  {
                std::string usuario, nombreEvento;
                while (true) {
                    std::cout << "Introduce tu usuario: " << std::endl; 
                    std::cin >> usuario; 
                    
                    if (validarNombreUsuario(usuario)) { // comprueba que el usuario existe
                        std::cout << "Introduce nombre del evento: " << std::endl; 
                        std::cin >> nombreEvento; 

                        if (comprobarEvento(nombreEvento)) { // comprueba que el evento existe
                            preinscribirEvento(usuario, nombreEvento);
                            break; 
                        } else {
                            std::cout << "No se encuentra el evento." << std::endl; 
                        }
                    }
                }
                break; 
            }
            case 3: 
                menu();
                break;
                
            default: 
                std::cout << "Opcion no valida." << std::endl; 
                menuUsuario();
        }
    }
}
