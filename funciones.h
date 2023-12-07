#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <iomanip> 

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

bool validarUsuario(std::string& usuario, std::string& contrasena);
bool inicioSesion(std::string& usuario, std::string& contrasena);
bool comprobarUsuario(std:: string& usuario);

void registrarUsuario(const std::string& usuario, const std::string& contrasena);

void crearEvento();
void introducirNombre(std::string &nombre);
bool comprobarEvento(std::string& nombre);
void introducirTipoEvento(std::string& tipo);
bool comprobarTipoEvento(std::string& tipo);
bool comprobarFechas (std::string& fechaInicio, std::string& fechaFin);
void introducirFechas(std::string& fechaInicio, std::string& fechaFin);
bool guardarEvento(std::string& nombre, std::string& tipo, std::string& descripcion, std::string& fechaInicio, std::string& fechaFin, int duracion); 

void preinscribirSinTarifa(Usuario usuario, Evento& evento);
void cancelarPreinscripcion();
void manejarErrorPago();
void sinAforoDisponible();
bool verificarDetallesPago(const std::string& numeroTarjeta);

// Función para preinscribirse en un evento
void preinscribirEvento(Usuario usuario, Evento& evento);

#endif
