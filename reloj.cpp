#include <iostream>
#include <string>
using namespace std;

class Display {
    private:
        string tipo;
    public:
        Display(string = "digital");
        string getTipo();
};

Display :: Display(string t) {
    tipo = t;
}

string Display :: getTipo() {
    return tipo;
}

class Hora {
    private:
        int hora;
        int minutos;
        int segundos;
    public:
        Hora(int, int, int);
        int getHora();
        int getMinutos();
        int getSegundos();
};

Hora :: Hora(int h, int m, int s) {
    hora = h;
    minutos = m;
    segundos = s;
}

int Hora :: getHora() {
    return hora;
}

int Hora :: getMinutos() {
    return minutos;
}

int Hora :: getSegundos() {
    return segundos;
}

class Reloj {
    private:
        Display* pDisplay;
        Hora* pHora;
    public:
        Reloj(int, int, int);
        void asignarDisplay(Display*);
        void mostrarReloj();
};

Reloj :: Reloj(int h, int m, int s) {
    pHora = new Hora(h, m, s); 
    pDisplay = NULL;           
}

void Reloj :: asignarDisplay(Display* pD) {
    pDisplay = pD;            
}

void Reloj :: mostrarReloj() {
    if (pDisplay->getTipo() == "digital") {
        cout << "[" << pHora->getHora() << ":" << pHora->getMinutos() << ":" << pHora->getSegundos() << "]" << endl;
    } 
    else if (pDisplay->getTipo() == "analogico") {
        cout << "-->" << pHora->getHora() << ":" << pHora->getMinutos() << ":" << pHora->getSegundos() << "<--" << endl;
    }
}

int main() {
  
    Display* d1 = new Display("digital");
    Display* d2 = new Display("analogico");

    Reloj reloj1(10, 15, 55);
    Reloj reloj2(10, 15, 55);

    reloj1.asignarDisplay(d1);
    reloj2.asignarDisplay(d2);

    reloj1.mostrarReloj();
    reloj2.mostrarReloj();

    return 0;
}

