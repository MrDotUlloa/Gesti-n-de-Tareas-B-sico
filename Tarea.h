#ifndef TAREA_H
#define TAREA_H

#include<string>
#include<stdexcept>

enum Estado { Pendiente, EnProgreso, Completada };

class Tarea {
	private: 
	int id;
	std::string titulo;
	std::string descripcion;
	std::string fechaVencimiento;
	Estado estado;
	
	public:
		Tarea(int id, const std::string& titulo, const std::string& descripcion, const std::string& fechaVencimiento, Estado estado):
			id(id), titulo(titulo), fechaVencimiento(fechaVencimiento), estado(ESTADO){
				if(titulo.empty()){
					throw std::invalid_argument("El título no debe estar vacío");
				}
			}
	
	int getId() const { return id; }
	std::string getTitulo() const { return titulo; }
	std::string getDescripcion() const { return descripcion; }
	std::string getFechaVencimiento() const { return fechaVencimiento; }
    Estado getEstado() const { return estado; }
    
    void setTitulo(const std::string& nuevoTitulo) { titulo = nuevoTitulo; }
    void setDescripcion(const std::string& nuevaDescripcion) { descripcion = nuevaDescripcion; }
    void setFechaVencimiento(const std::string& nuevaFecha) { fechaVencimiento = nuevaFecha; }
    void setEstado(Estado nuevoEstado) { estado = nuevoEstado; }
    
    std::string estadoToString() const {
	switch(estado){
		case Pendiente: return "Pendiente";
		case EnProgreso: return "En Progreso";
		case Completada: return "Completada";
	}
	}
	
    
    #endif
};
