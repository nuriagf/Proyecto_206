#include "inscripcion.hpp"

bool verificarDetallesPago(const std::string& numeroTarjeta, const std::string& nombreUsuario)
{
    return (nombreUsuario.find("Valido") != std::string::npos) && (numeroTarjeta.length() > 10);
}

void preinscribirSinTarifa(Usuario usuario, Evento& evento)
{
    evento.usuariosPreinscritos.push_back(usuario.nombreUsuario);
    std::cout << "Preinscripción sin tarifa realizada. Aforo actual: " << evento.usuariosPreinscritos.size() << "\n";
}

void cancelarPreinscripcion()
{
    std::cout << "Preinscripción cancelada." << "\n";
}

void manejarErrorPago()
{
    std::cerr << "Error en los detalles de pago. Por favor, inténtelo de nuevo." << "\n";
}

void sinAforoDisponible()
{
    std::cerr << "No hay aforo disponible en el evento." << "\n";
}

void preinscribirEvento(Usuario usuario, Evento& evento)
{
    while (!usuario.haIniciadoSesion)
    {
        std::cerr << "Necesita iniciar sesión para preinscribirse" << "\n";
    }

    std::cout << "Listado de eventos disponibles:" << "\n";
    // Función con la lista
    std::cout << "Seleccione el evento en el que desee preinscribirse" << "\n";
    // Usuario selecciona :D

    if (evento.tieneTarifa)
    {
        std::cout << "Introduzca los detalles del pago (o escriba 'Cancelar' para cancelar):" << "\n";
        std::string numeroTarjeta;
        std::cin >> numeroTarjeta;

        if (numeroTarjeta == "Cancelar")
        {
            cancelarPreinscripcion();
        }
        else if (!verificarDetallesPago(numeroTarjeta, usuario.nombreUsuario))
        {
            manejarErrorPago();
        }
        else
        {
            // Verificar aforo disponible
            if (evento.aforo > 0)
            {
                // Realizar la preinscripción
                evento.usuariosPreinscritos.push_back(usuario.nombreUsuario);
                evento.aforo--;
                std::cout << "Preinscripción realizada con éxito. Aforo actual: " << evento.usuariosPreinscritos.size() << "\n";
            }
            else
            {
                sinAforoDisponible();
            }
        }
    }
    else
    {
        preinscribirSinTarifa(usuario, evento);
    }
}
=======
#include "inscripcion.hpp"

bool verificarDetallesPago(const std::string& numeroTarjeta, const std::string& nombreUsuario)
{
    return (nombreUsuario.find("Valido") != std::string::npos) && (numeroTarjeta.length() > 10);
}

void preinscribirSinTarifa(Usuario usuario, Evento& evento)
{
    evento.usuariosPreinscritos.push_back(usuario.nombreUsuario);
    std::cout << "Preinscripción sin tarifa realizada. Aforo actual: " << evento.usuariosPreinscritos.size() << "\n";
}

void cancelarPreinscripcion()
{
    std::cout << "Preinscripción cancelada." << "\n";
}

void manejarErrorPago()
{
    std::cerr << "Error en los detalles de pago. Por favor, inténtelo de nuevo." << "\n";
}

void sinAforoDisponible()
{
    std::cerr << "No hay aforo disponible en el evento." << "\n";
}

void preinscribirEvento(Usuario usuario, Evento& evento)
{
    while (!usuario.haIniciadoSesion)
    {
        std::cerr << "Necesita iniciar sesión para preinscribirse" << "\n";
    }

    std::cout << "Listado de eventos disponibles:" << "\n";
    // Función con la lista
    std::cout << "Seleccione el evento en el que desee preinscribirse" << "\n";
    // Usuario selecciona :D

    if (evento.tieneTarifa)
    {
        std::cout << "Introduzca los detalles del pago (o escriba 'Cancelar' para cancelar):" << "\n";
        std::string numeroTarjeta;
        std::cin >> numeroTarjeta;

        if (numeroTarjeta == "Cancelar")
        {
            cancelarPreinscripcion();
        }
        else if (!verificarDetallesPago(numeroTarjeta, usuario.nombreUsuario))
        {
            manejarErrorPago();
        }
        else
        {
            // Verificar aforo disponible
            if (evento.aforo > 0)
            {
                // Realizar la preinscripción
                evento.usuariosPreinscritos.push_back(usuario.nombreUsuario);
                evento.aforo--;
                std::cout << "Preinscripción realizada con éxito. Aforo actual: " << evento.usuariosPreinscritos.size() << "\n";
            }
            else
            {
                sinAforoDisponible();
            }
        }
    }
    else
    {
        preinscribirSinTarifa(usuario, evento);
    }
}
