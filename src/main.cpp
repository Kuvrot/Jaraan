#include "Jaraan/Jaraan.h"
#define HEIGHT 800u
#define WIDTH 600u

int main()
{
    
    Window window(800 , 600 , "Jaraan");
    Button btn(1, 1, "Soy un botón" , 12);
    Button btn2(8, 1, "boton" , 12);
    Button btn3(1, 2, "Soy un botón" , 12);
    window.Update();

    
}
