#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <string>
#include <vector>

struct Evento
{
    std::string nombreEvento;
    bool tieneTarifa;
    int aforo;
    std::vector<std::string> usuariosPreinscritos;
};

struct Usuario
{
    std::string nombreUsuario;
    bool haIniciadoSesion;
};

void preinscribirSinTarifa(Usuario usuario, Evento& evento);
void cancelarPreinscripcion();
void manejarErrorPago();
void sinAforoDisponible();
bool verificarDetallesPago(const std::string& numeroTarjeta);

// Función para preinscribirse en un evento
void preinscribirEvento(Usuario usuario, Evento& evento);

#endif

