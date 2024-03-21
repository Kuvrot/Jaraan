#include "Jaraan/Jaraan.h"
#define HEIGHT 800u
#define WIDTH 600u


void Mem(Label l1) {

    l1.setText("This is a string");
}

void Mom() {

    Button btn3(8, 6, "Soy un botón", 12, nullptr);     
    
}

int main()
{   
    Window window(800, 600, "Jaraan");
    Button btn(1, 1, "Soy un botón", 12, Mom);
    Button btn3(8, 1, "Soy un botón", 12, nullptr);
    Label l1(10, 8, "Esto es un texto", 24);
    Button btn2(6, 1, "boton", 12, [l1]() {Mem(l1); });

    
    window.Update();


    return 0;

    
}



