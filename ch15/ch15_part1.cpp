/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

double slope(double x) { return x/2; }

int main()
{
    using namespace Graph_lib;

    int xmax = 600;
    int ymax = 600;

    int x_orig = xmax/2;
    int y_orig = ymax/2;

    int rmin = -10;
    int rmax = 10;
    
    int n_points = 400;

    Simple_window win {Point{100,100}, xmax, ymax, "Function graphing"};

	Point origo {x_orig, y_orig};

	int xlength = xmax - 200;
	int ylength = ymax - 200;

	int xscale = 20, yscale = 20;

	
	Function s (one, rmin, rmax, origo, n_points, xscale, yscale);
	Function linear (slope, rmin, rmax, origo, n_points, xscale, yscale);
	Function sq (square, rmin, rmax, origo, n_points, xscale, yscale);
	Function cos_func ( [] (double x) { return cos(x); },
						rmin, rmax, origo, n_points, xscale, yscale);
	Function sloping_cos ( [] (double x) { return cos(x)+slope(x); },
						rmin, rmax, origo, n_points, xscale, yscale);					
	

	Axis x {Axis::x, Point{xlength-300, y_orig}, xlength, xlength/xscale, "1 == 20 pixels"};
	Axis y {Axis::y, Point{x_orig, ylength+100}, ylength, ylength/yscale, "1 == 20 pixels"};

	Text ts {Point{300,y_orig-40},"one"};
	Text ts2 {Point{300,y_orig+70},"cos(x)"};
	Text ts3 {Point{x_orig-100,20},"x*x"};
	Text ts4 {Point{x_orig-200,y_orig+90},"x/2"};
	win.set_label("Function graphing: label functions");
	
	x.set_color(Color::red);
	y.set_color(Color::red);
	cos_func.set_color(Color::blue);

	win.attach(s);
	win.attach(sq);
	win.attach(cos_func);
	win.attach(x);
	win.attach(y);
	win.attach(linear);
	win.attach(sloping_cos);
	
	win.attach(ts);
	win.attach(ts2);
	win.attach(ts3);
	win.attach(ts4);
	
	win.wait_for_button();

}































