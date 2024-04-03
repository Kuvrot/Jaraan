#include "Jaraan/Jaraan.h"


int main() {

	Window window(800 , 600, "Hello program");
	Label label(10 , 10 , "Hello world!" , 24);
	Button btn(10, 15, "Click me!", 12, []() {std::cout << "xd \n" ; });
	window.Update();
	return 0;

}

















