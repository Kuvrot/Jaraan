#include "Jaraan/Jaraan.h"

void select(int n , Label lb) {

    switch (n) {

        case 1: lb.setText("¡Hola amigo!"); break;
        case 2: lb.setText("Hello friend!"); break;
        case 3: lb.setText("Hallo freund!"); break;
        case 4: lb.setText("Salve amici!"); break;
    }
}

int main()
{   

    Window window(800, 600, "Jaraan");
    Label label(10, 2, "Select a language", 24);
    Button btn1(1, 1, "Spanish", 12, [label]() {select(1 , label); });
    Button btn2(1, 2, "English", 12, [label]() {select(2, label); });
    Button btn3(1, 3, "Deutsch", 12, [label]() {select(3 , label); });
    Button btn4(1, 4, "Latin  ", 12, [label]() {select(4 , label); });

    window.Update();

    return 0;
}



