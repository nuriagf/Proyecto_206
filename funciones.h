#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <iomanip> 
#include <vector>

//Inicio de sesion
bool validarNombreUsuario(std::string& usuario);
bool validarUsuario(std::string& usuario, std::string& contrasena);
bool inicioSesion(std::string& usuario, std::string& contrasena);
bool comprobarUsuario(std:: string& usuario);

//Registro
bool registrarUsuario(std::string& usuario, std::string& contrasena);

//Crear evento
void crearEvento();
void introducirNombre(std::string &nombre);
bool comprobarEvento(std::string& nombre);
void introducirTipoEvento(std::string& tipo);
bool comprobarTipoEvento(std::string& tipo);
bool comprobarFechas (std::string& fechaInicio, std::string& fechaFin);
void introducirFechas(std::string& fechaInicio, std::string& fechaFin);
bool guardarEvento(std::string& nombre, std::string& tipo, std::string& descripcion, int precio, int aforo, std::string& fechaInicio, std::string& fechaFin, int duracion); 

//Inscribirse
void preinscribirEvento(std::string& usuario, std::string& nombreEvento);
int obtenerPrecio(std::string& nombreEvento);
int obtenerAforo(std::string& nombreEvento);
int contarAforoInscritos (std::string &nombreEvento);
bool inscripcionSinTarifa(std::string& usuario, std::string& nombreEvento, int aforo);
bool inscripcionConTarifa(std::string& usuario, std::string& nombreEvento, int precio, int aforo);

//Cuenta bancaria
bool insertarCuentaBancaria(std::string usuario);
bool buscarCuenta(std::string& usuario);
int obtenerSaldo(std::string& usuario);
void cobrarEvento(std::string& usuario, int saldo, int precio);

//Eliminar evento
void eliminarEvento(std::string& nombre);

//Modificar evento
void modificarEvento(std::string& nombre);

//Listar evento
void listarEvento();

//Comprobar tipo de usuario
int comprobarCorreo(std::string& correo);

//Menús
void menu();
void inicioAdministrador(); 
void menuAdministrador(); 
void inicioUsuario(); 
void menuUsuario(); 

#endif
