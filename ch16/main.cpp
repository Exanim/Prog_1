// g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`

#include "GUI.h"
#include "Lines_window.h"

using namespace Graph_lib;
int main()
{
	Lines_window win{ Point{100,100}, 800, 600, "lines" };
	
	return gui_main();
	
}
