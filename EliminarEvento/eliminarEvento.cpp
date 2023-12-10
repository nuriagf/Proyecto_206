#include "../funciones.h"

void eliminarEvento() {
    std::string nombre; 

    std::cout << "Inserte el nombre." << std::endl; 
    std::cin >> nombre; 

    if(comprobarEvento(nombre)) {
        auto it = std::remove_if((eventos.txt).begin(), (eventos.txt).end(),
                             [nombre](const std::vector<std::string>& evento) {
                                 return !evento.empty() && evento[0] == nombre;
                             });

    // Elimina realmente los elementos que cumplen la condición
    eventos.txt.erase(it, eventos.txt.end());
    }

}