#ifndef GESTORDETAREAS_H
#define GESTORDETAREAS_H

#include<vector>
#include<algorithm>
#include<iostream>
#incude "Tarea.h"

class GestorDeTareas {
	private:
		std::vector<Tarea> tareas;
		int contadorId;
	public:
		GestorDeTareas() : contadorId(1){}
		
		void CrearTarea(const std::string& titulo, const std::string& fechaVencimiento, Estado estado){
			Tarea nuevaTarea(contadorId++, titulo, fechaVencimiento, estado);
			tareas.push_back(nuevaTarea);
		}
		
		void ListarTareas () const {
		std::cout<<"Lista de tareas:"<<std::endl;
		for (const auto& tarea : tareas){
			std::cout << "ID: " << tarea.getId()
			          << "Titulo: " << tarea.getTitulo()
			          << "Estado: " << tarea.estadoToString()
			          << "Fecha de vencimiento: " << tarea.getFechaVencimiento() << std::endl;
		}
		}
		void actualizarTarea(int id, const std::string& nuevoTitulo, const std::string& nuevaDescripcion,
                         const std::string& nuevaFecha, Estado nuevoEstado) {
                for(auto& tarea: tareas){
                	if(tarea.getId() == id){
                		tarea.setTitulo(nuevoTitulo);
                		tarea.setDescripcion(nuevaDescripcion);
                		tarea.setFechaVencimiento(nuevaFecha);
                		tarea.setEstado(nuevoEstado);
					}
				}
        throw std::invalid_argument("Tarea no encontrada.");
	}
	void eliminarTarea (int id){
		auto it = std::remove_if(tareas.begin), tareas.end(), [id](const Tarea& tarea) { return tarea.getId() == id; });
		if (it != tareas.end()){
			tareas.erase(it, tareas.end());
		} else {
			throw std::invalid_argument("Tarea no encontrada.");
		}
		}
	
};
#endif
