#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include <iostream>
#include <fstream>

bool validarUsuario(std::string& usuario, std::string& contrasena);
bool inicioSesion(std::string& usuario, std::string& contrasena);
bool comprobarUsuario(std:: string& usuario);
void crearEvento();
bool comprobarEvento(std::string& nombre), 
bool guardarEvento(std::string& nombre, std::string& tipo, std::string& descripcion, std::string& fechaInicio, std::string& fechaFin, int duracion); 

#endif
