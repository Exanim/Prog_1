#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;

	int win_x = 100, win_y = 100;
	const Point top_left{ win_x, win_y };
	int win_width = 800, win_height = 1000;
	Simple_window win{ top_left, win_width, win_height, "grid-image drill" };

	Lines grid;
	int col_count = 8;
	int row_count = 8;
	int row_height = 100;
	int col_width = 100;
	int grid_width = col_count * col_width;
	int grid_height = row_height * row_count;
	for (int x = 0; x < grid_width; x += col_width)
	{
		for (int y = 0; y < grid_height; y += row_height)
		{
			grid.add(Point{ x, 0 }, Point{ x, grid_height });
			grid.add(Point{ 0, y }, Point{ grid_width, y });
		}
	}
	grid.set_color(Color::black);
	win.attach(grid);

	int rect_width = 100;
	int rect_height = 100;
	int num_rects = 8;
	Vector_ref<Graph_lib::Rectangle> rect_vr;
	for (int i = 0, x = 0, y = 0; i < num_rects; ++i, x += rect_width, y += rect_height)
	{
		rect_vr.push_back(new Graph_lib::Rectangle{ Point{ x, y }, rect_width, rect_height });
		rect_vr[i].set_color(Color::black);
		rect_vr[i].set_fill_color(Color::red);
		win.attach(rect_vr[i]);
	}

	Image cat1{ Point{200, 400}, "cat.jpg" };
	win.attach(cat1);

	Image cat2{ Point{400, 600}, "cat.jpg" };
	win.attach(cat2);

	Image cat3{ Point{0, 200}, "cat.jpg" };
	win.attach(cat3);

	Image apple{ Point{0, 0}, "apple.jpg" };
	win.attach(apple);

	for (int j = 0; j < 7; ++j)
	{
		if (win.wait_for_button()) { apple.move(100, 100); }
	}
		
	
	
	win.wait_for_button();
}















