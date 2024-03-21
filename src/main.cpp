#include "Jaraan/Jaraan.h"
#define HEIGHT 800u
#define WIDTH 600u


void Mom() {

    std::cout << "xd";

}

int main()
{
    
    Window window(800 , 600 , "Jaraan");
    Button btn(1, 1, "Soy un botón" , 12 , Mom);
    Button btn2(6, 1, "boton" , 12, Mom);
    Button btn3(8, 1, "Soy un botón", 12, Mom);
    window.Update();


    return 0;

    
}
