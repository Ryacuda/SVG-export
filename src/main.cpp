#include "svg_elements.h"

void test_rect()
{
	SVGLine l;		// line at the origin, 0 thickness and rgb(0,0,0) color (black)

	std::cout << "test_line : " << std::endl << l << std::endl;
}



void test_line()
{
	SVGRect r;		// rect at the origin, 0 width and height and rgb(0,0,0) color (black)

	std::cout << "test_rect : " << std::endl << r << std::endl;
}


void test_svg()
{
	SVGSvg svg(0,0,120,120);		// svg width and height 120

	Color red(255,0,0);				// RGB values

	// SVGAnimatedElement pointer to a SVGRect of top-left corner pos (10, 10) and width and height 110, colored red
	std::shared_ptr<SVGAnimatedElement> ptr_r = std::make_shared<SVGRect>(10,10, 110, 110, red);

	svg.addElement(ptr_r);			// add the element to the svg

	// output the svg
	std::cout << "test_svg :" << std::endl << svg << std::endl;
}


void test_file()
{
	Color red(255,0,0);				// RGB values
	// SVGAnimatedElement pointer to a SVGRect of top-left corner pos (10, 10) and width and height 100, colored red
	std::shared_ptr<SVGAnimatedElement> ptr_r = std::make_shared<SVGRect>(10,10, 100, 100, red);

	Color blue(0,0,255);			// RGB values
	// SVGAnimatedElement pointer to a SVGLine starting at (5, 5), ending at (115, 115)
	// of thickness 5, colored blue
	std::shared_ptr<SVGAnimatedElement> ptr_l = std::make_shared<SVGLine>(5,5, 115, 115, 5, blue);

	SVGSvg svg(0,0,120,120);		// svg width and height 120
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
}


int main()
{
	test_rect();

	test_line();

	test_svg();

	test_file();

	return 0;	
}