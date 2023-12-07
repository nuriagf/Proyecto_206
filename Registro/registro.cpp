#include "../funciones.h"  

void registrarUsuario(const std::string& usuario, const std::string& contrasena) {
    std::ofstream archivo("registro.txt", std::ios::app);  

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de registro." << std::endl;
        return;
    }

    // Escribe el nuevo usuario y contraseña en el archivo
    archivo << usuario << " " << contrasena << "\n";

    archivo.close();
}
