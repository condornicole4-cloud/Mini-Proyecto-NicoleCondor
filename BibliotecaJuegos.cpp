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


