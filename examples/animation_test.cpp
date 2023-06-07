#include "svg_elements.h"
#include "svg_attributes.h"

int main()
{
	SVGSvg svg(0,0,120,120);		// svg width and height 120

	Color c(120,180,70);			// RGB values

	// SVGAnimatedElement pointer to a SVGLine starting at (5, 5), ending at (115, 115)
	// of thickness 5, colored blue
	std::shared_ptr<SVGAnimatedElement> ptr_l1 = std::make_shared<SVGLine>(5, 5, 115, 115, 5, c);
	std::shared_ptr<SVGAnimatedElement> ptr_l2 = std::make_shared<SVGLine>(5, 115, 115, 5, 5, c);

	// animation for the line 1
	Timeline tl(4000, true);			// duration 4s, spline calcMode
	tl.addKeyTime(0.0, 5);
	tl.addKeyTime(1.0, 115);
	SVGAnimate a1("x1", tl, 1, true);

	tl.addKeyTime(0.0, 115);
	tl.addKeyTime(1.0, 5);
	SVGAnimate a2("x2", tl, 1, true);

	ptr_l1->addAnimation(a1);
	ptr_l1->addAnimation(a2);

	// animation for the line 2
	// y1 follows same timeline as x2
	SVGAnimate a3("y1", tl, 1, true);

	tl.addKeyTime(0.0, 5);
	tl.addKeyTime(1.0, 115);
	SVGAnimate a4("y2", tl, 1, true);
	
	ptr_l2->addAnimation(a3);
	ptr_l2->addAnimation(a4);

	svg.addElement(ptr_l1);			// add the element to the svg
	svg.addElement(ptr_l2);			// add the element to the svg


	std::ofstream file;
	file.open("test_animation.svg");

	if(file.is_open())
	{
		file << svg;				// Write SVG to file

		file.close();	
	}
	else
	{
		std::cout << "Couldn't open test_animation.svg" << std::endl;
	}

	return 0;
}