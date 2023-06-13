#include "svg_elements.h"
#include "svg_attributes.h"

int main()
{
	SVG::Color red(255,0,0);				// RGB values
	// SVG::AnimatedElement pointer to a SVG::Rect of top-left corner pos (10, 10) and width and height 100, colored red
	std::shared_ptr<SVG::AnimatedElement> ptr_r = std::make_shared<SVG::Rect>(10,10, 100, 100, red);

	SVG::Color blue(0,0,255);			// RGB values
	// SVG::AnimatedElement pointer to a SVG::Line starting at (5, 5), ending at (115, 115)
	// of thickness 5, colored blue
	std::shared_ptr<SVG::AnimatedElement> ptr_l = std::make_shared<SVG::Line>(5,5, 115, 115, 5, blue);

	SVG::Svg svg(0,0,120,120);		// svg width and height 120
	svg.addElement(ptr_r);			// add the element to the svg
	svg.addElement(ptr_l);			// add the element to the svg


	std::ofstream file;
	file.open("test_svg.svg");

	if(file.is_open())
	{
		file << svg;				// Write SVG to file

		file.close();	
	}
	else
	{
		std::cout << "Couldn't open test_svg.svg" << std::endl;
	}

	return 0;
}