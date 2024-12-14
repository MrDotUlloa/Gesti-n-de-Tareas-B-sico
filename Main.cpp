#include<iostream>
#include "GestorDeTareas.h"

void MostrarMenu() {
	std::cout<< "=== Gestor de Tareas ===" << std::endl;
	std::cout<< "1. Crear tarea" << std::endl;
	std::cout<< "2. Listar tareas" << std::endl;
	std::cout<< "3. Actualizar tarea" << std::endl;
    std::cout<< "4. Eliminar tarea" << std::endl;
    std::cout<< "5. Salir" << std::endl;
    std::cout<< "Seleccione una opción: ";
}

int main(){
	GestorDeTareas gestor;
	int opcion;
	
	do {
		MostrarMenu();
		std::cin>>opcion;
		
		switch(opcion){
			case 1: {
				std::string titulo, descripcion, fechaVencimiento;
				int estado;
				
				std::cout << "Ingrese el título: ";
				std::cin.ignore();
				std::getline(std::cin, titulo);
				
				std::cout << "Ingrese la descripción (opcional): ";
                std::getline(std::cin, descripcion);

                std::cout << "Ingrese la fecha de vencimiento (dd/mm/aaaa): ";
                std::getline(std::cin, fechaVencimiento);

                std::cout << "Seleccione el estado (0: Pendiente, 1: En Progreso, 2: Completada): ";
                std::cin >> estado;
                
                try{
                	gestor.CrearTarea(titulo, fechaVencimiento, static_cast<Estado>(estado));
                	std::cout << "Tarea creada exitosamente. " << std::end;
				} catch (const std::exception& e){
					std::cerr << "Error: " << e.what() << std::endl;
				}
				
				break;
			}
			case 2:
            gestor.listarTareas();
            break;

            case 3: {
               int id;
               std::string nuevoTitulo, nuevaDescripcion, nuevaFechaVencimiento;
               int nuevoEstado;

               std::cout << "Ingrese el ID de la tarea a actualizar: ";
               std::cin >> id;

               std::cout << "Ingrese el nuevo título: ";
               std::cin.ignore();
               std::getline(std::cin, nuevoTitulo);

               std::cout << "Ingrese la nueva descripción: ";
               std::getline(std::cin, nuevaDescripcion);

               std::cout << "Ingrese la nueva fecha de vencimiento (dd/mm/aaaa): ";
               std::getline(std::cin, nuevaFechaVencimiento);

               std::cout << "Seleccione el nuevo estado (0: Pendiente, 1: En Progreso, 2: Completada): ";
               std::cin >> nuevoEstado;

               try {
                gestor.actualizarTarea(id, nuevoTitulo, nuevaDescripcion, nuevaFechaVencimiento, static_cast<Estado>(nuevoEstado));
                std::cout << "Tarea actualizada exitosamente." << std::endl;
                } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
               }
            break;
        }
             case 4: {
             	int id;
             	std::cout<< "Ingrese el ID de la tarea a eliminar: ";
             	std::cin >> id;
             	 
             	 try{
             	 	gestor.eliminarTarea(id);
             	 	std::cout<<" Tarea fue eliminada exitosamente."<<std::endl;
				  } catch (const std::exception& e){
				  	std:cerr << "Error: " << e.what() << std::endl;
				  }
				break;
			 }
			 case 5: 
			 std::cout << "Saliendo del programa, que Dios me lo bendiga, y hasta proontoooooooo."<<std::endl;
			 break;
		}
	}
}
