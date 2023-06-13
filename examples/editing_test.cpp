#include "svg_elements.h"
#include "svg_attributes.h"


int main()
{
	SVG::Svg svg(0,0,120,120);		// svg width and height 120

	SVG::Color c(120,180,70);			// RGB values

	std::shared_ptr<SVG::AnimatedElement> ptr_l2 = std::make_shared<SVG::Line>(5, 115, 115, 5, 5, c);	

	// animation for the line 1
	SVG::Timeline tl(4000, true);			// duration 4s, spline calcMode
	tl.addKeyTime(0.0, 5);
	tl.addKeyTime(1.0, 115);
	SVG::Animation a1("x1", tl, 1, true);

	ptr_l2->addAnimation(a1);

	svg.addElement(ptr_l2);

	std::ofstream file;
	file.open("test_editing_1.svg");

	if(file.is_open())
	{
		file << svg;				// Write SVG to file

		file.close();	
	}
	else
	{
		std::cout << "Couldn't open test_editing_1.svg" << std::endl;
	}

	SVG::Animation * p_a2 = ptr_l2->getAnimation("x1");

	if(!p_a2)
	{
		std::cout << "nullptr" << std::endl;
		return 1;
	}

	// editing
	p_a2->getTimelineRef().addKeyTime(0.5, 115);
	p_a2->getTimelineRef().addKeyTime(1.0, 5);

	file.open("test_editing_2.svg");

	if(file.is_open())
	{
		file << svg;				// Write SVG to file

		file.close();	
	}
	else
	{
		std::cout << "Couldn't open test_editing_2.svg" << std::endl;
	}

	return 0;
}