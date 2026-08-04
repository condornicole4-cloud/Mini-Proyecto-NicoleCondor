/*
PROYECTO BIBLIOTECA DE VIDEOJUEGOS
    Nombre: Nicole Condor
    Fecha: 03/08/2026
    
Entrada:
Opciones del menú principal (1 al 6)
Títulos de los juegos, horas de juego y calificaciones
Títulos ingresados específicamente para la búsqueda de juegos

Proceso:
El sistema evalúa qué opción eligió el usuario en el menú y restringe los errores
Suma las horas acumuladas, identifica el valor máximo de calificación mediante comparaciones, y filtra el inventario aplicando condiciones lógicas combinadas

Salida:
Visualización del menú principal, alertas de error, y confirmaciones de éxito.
Listado ordenado de toda la colección y visualización de la ficha de un juego específico buscado.
Estadísticas globales (total de horas y juego top) y la lista de recomendaciones especiales./*



#include <iostream>
#include <string>

using namespace std;

// Prototipos de funciones
void registrarJuego(string titulos[], float horas[], int calificacion[], int &total);
void mostrarJuegos(string titulos[], float horas[], int calificacion[], int total);
void buscarJuego(string titulos[], float horas[], int calificacion[], int total);
void reporteGeneral(string titulos[], float horas[], int calificacion[], int total);
void detectorDeJoyas(string titulos[], float horas[], int calificacion[], int total);

int main() {
    string titulos[20];
    float horasJugadas[20];
    int calificacion[20];
    int totalJuegos = 0; 
    
    int opcion = 0;

    do {
        cout << "\n=== GESTOR DE BIBLIOTECA DE VIDEOJUEGOS ===\n";
        cout << "1. Registrar un nuevo juego\n";
        cout << "2. Mostrar todos los juegos\n";
        cout << "3. Buscar un juego por titulo\n";
        cout << "4. Ver reporte de mi cuenta\n";
        cout << "5. Descubrir Joyas Abandonadas (Componente Creativo)\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        bool opcionInvalida = false;
        
        if (opcion < 1) {
            opcionInvalida = true;
        } else if (opcion > 6) {
            opcionInvalida = true;
        }

        if (opcionInvalida == true) {
            cout << "Error: Opcion invalida. Intente de nuevo.\n";
            continue;
        }

        switch (opcion) {
            case 1:
                registrarJuego(titulos, horasJugadas, calificacion, totalJuegos);
                break;
            case 2:
                mostrarJuegos(titulos, horasJugadas, calificacion, totalJuegos);
                break;
            case 3:
                buscarJuego(titulos, horasJugadas, calificacion, totalJuegos);
                break;
            case 4:
                reporteGeneral(titulos, horasJugadas, calificacion, totalJuegos);
                break;
            case 5:
                detectorDeJoyas(titulos, horasJugadas, calificacion, totalJuegos);
                break;
            case 6:
                cout << "Cerrando la biblioteca. ¡A jugar!\n";
                break;
        }
    } while (opcion != 6);

    return 0;
}

void registrarJuego(string titulos[], float horas[], int calificacion[], int &total) {
    if (total >= 20) {
        cout << "\nError: Limite de 20 juegos alcanzado. Memoria llena.\n";
        return;
    }
    
    cout << "\nIngrese el titulo del juego (Escribir todo junto, en forma CamelCase, Ej: SuperMario): ";
    cin >> titulos[total]; 
    
    do {
        cout << "Ingrese las horas jugadas (Ej. 2.5): ";
        cin >> horas[total];
        if (horas[total] < 0) {
            cout << "Las horas no pueden ser negativas.\n";
        }
    } while (horas[total] < 0);
    
    bool calificacionValida;
    do {
        calificacionValida = true; 
        
        cout << "Ingrese la calificacion (1 al 10): ";
        cin >> calificacion[total];
        
        if (calificacion[total] < 1) {
            cout << "Error: La calificacion no puede ser menor a 1.\n";
            calificacionValida = false; 
        } else if (calificacion[total] > 10) {
            cout << "Error: La calificacion no puede ser mayor a 10.\n";
            calificacionValida = false; 
        }
        
    } while (calificacionValida == false);
    
    total++; 
    cout << "Juego registrado exitosamente.\n";
}

void mostrarJuegos(string titulos[], float horas[], int calificacion[], int total) {
    if (total == 0) {
        cout << "\nTu biblioteca esta vacia. ¡Registra algunos juegos primero!\n";
        return;
    }
    
    cout << "\n--- MI COLECCION ---\n";
    for (int i = 0; i < total; i++) {
        cout << i+1 << ". Titulo: " << titulos[i] 
             << " | Horas: " << horas[i] 
             << "h | Calificacion: " << calificacion[i] << "/10\n";
    }
}

void buscarJuego(string titulos[], float horas[], int calificacion[], int total) {
    if (total == 0) {
        cout << "\nNo hay juegos para buscar.\n";
        return;
    }

    string tituloBuscado;
    cout << "\nIngrese el titulo del juego a buscar (todo junto sin espacios): ";
    cin >> tituloBuscado; 

    bool encontrado = false;
    for (int i = 0; i < total; i++) {
        if (titulos[i] == tituloBuscado) {
            cout << "\n--- JUEGO ENCONTRADO ---\n";
            cout << "Titulo: " << titulos[i] << "\n";
            cout << "Horas jugadas: " << horas[i] << "h\n";
            cout << "Calificacion: " << calificacion[i] << "/10\n";
            encontrado = true;
            break; 
        }
    }

    if (encontrado == false) {
        cout << "\nEl juego '" << tituloBuscado << "' no se encuentra en la biblioteca.\n";
    }
}

void reporteGeneral(string titulos[], float horas[], int calificacion[], int total) {
    if (total == 0) {
        cout << "\nNo hay datos para generar el reporte.\n";
        return;
    }

    float totalHoras = 0;
    int maxCalificacion = calificacion[0];
    string juegoTop = titulos[0];

    for (int i = 0; i < total; i++) {
        totalHoras += horas[i];
        
        if (calificacion[i] > maxCalificacion) {
            maxCalificacion = calificacion[i];
            juegoTop = titulos[i];
        }
    }

    cout << "\n--- REPORTE GENERAL ---\n";
    cout << "Total de horas jugadas en todos los juegos: " << totalHoras << "h\n";
    cout << "Juego mejor calificado: " << juegoTop << " (" << maxCalificacion << "/10)\n";
}

void detectorDeJoyas(string titulos[], float horas[], int calificacion[], int total) {
    if (total == 0) {
        cout << "\nNo hay juegos registrados para analizar.\n";
        return;
    }

    cout << "\n--- DETECTOR DE JOYAS ABANDONADAS ---\n";
    cout << "Juegos excelentes (Calificacion >= 8) con poco tiempo de juego (< 5 horas):\n";
    
    bool joyaEncontrada = false;
    for (int i = 0; i < total; i++) {
        if (calificacion[i] >= 8) {
            if (horas[i] < 5.0) {
                cout << "- " << titulos[i] << " (Calificacion: " << calificacion[i] 
                     << " | Horas: " << horas[i] << "h)\n";
                joyaEncontrada = true;
            }
        }
    }

    if (joyaEncontrada == false) {
        cout << "No tienes joyas abandonadas. ¡Le has dedicado buen tiempo a tus mejores juegos!\n";
    }
}

