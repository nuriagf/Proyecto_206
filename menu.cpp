#include "funciones.h"

//Hacer que no hagan break, sino que vuelvan al menú principal (aún hay que cambiar algunos)

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
                menu(); //A veces no funciona//cuando salga del menú adeministrador lleva al menú principañ
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
        std::cout << "3- Eliminar evento. " << std::endl; //HAY QUE MIRAR PARA QUE LAS OPCIONES DE ELIMINAR Y MODIFCAR DESPUÉS DE TERMINAR VUELVAN AL MENÚ ADMINISTRADOR
        std::cout << "4- Modificar evento. " << std::endl; 
        std::cout << "5- Salir." << std::endl; //COMPROBAR QUE FUNCIONA EL SALIRSE
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
                    while (true) {
                        std::string linea;
                        std::getline(std::cin, linea); 
                            
                        if (linea.empty()) { //cuando haya un enter en la linea vacia se saldrá 
                            break;
                        }

                        nombre += linea + " "; 
                    }

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
                    std::cin.ignore();
                    while (true) {
                        std::string linea;
                        std::getline(std::cin, linea); 
                            
                        if (linea.empty()) { //cuando haya un enter en la linea vacia se saldrá 
                            break;
                        }

                        nombre += linea + " "; 
                    }
                    if(comprobarEvento(nombre) == true) { //NO SE POR QUÉ PERO NO BUSCA BIEN EL EVENTO Y ESTA FUNCIÓN SE SUPONE QUE FUNCIONA, CREO QUE ES EL FICHERO
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
                return;  //vuelve a la función que le llamó

            default: 
                std::cout << "Opcion no valida. " << std::endl; 
            //borrar Evento
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
        
        default: 
                std::cout << "Opcion no valida. " << std::endl; 
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
        std::cout << "3- Salir. " << std::endl; //COMPROBAR QUE FUNCIONA
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
                            std::cout << "Introduce nombre del evento (pulsa -enter- en una linea vacia para fianlizar)." << std::endl; 
                            std::string nombreEvento; 

                            std::cin.ignore();//limpiar buffer

                            while (true) {
                                std::string linea;
                                std::getline(std::cin, linea); 
                                        
                                if (linea.empty()) { //cuando haya un enter en la linea vacia se saldrá 
                                    break;
                                }

                                nombreEvento += linea + " "; 
                            } 

                            if(comprobarEvento(nombreEvento)) { //Parece que no sale de este bucle ni aunque le des a salir// comprueba que el evento existe
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
                return;  //vuelve a la función que le llamó
                
            default: 
                std::cout << "Opcion no valida. " << std::endl; 
        }
    }
}