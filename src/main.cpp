#include "svg_elements.h"
#include "svg_attributes.h"

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

void tmp_test()
{
	std::vector<double> v;		// empty vector

	std::cout << "tmp_test 1 :" << std::endl << (v.begin() == v.end()) << std::endl << std::endl;

	v.push_back(1.0);			// one element vector

	std::cout << "tmp_test 2 :" << std::endl << (v.begin() == v.end()) << std::endl << std::endl;

	std::vector<int> v2(100,100);	// 100 elements vector

	std::cout << "tmp_test 2 :" << std::endl << (++v2.begin() - v2.begin()) << std::endl << std::endl;
}

void test_timeline()
{
	Timeline tl(1000, false);

	tl.addKeyTime(0.0, 10);
	tl.addKeyTime(1.0, 10);
	tl.addKeyTime(0.5, 100);

	std::cout << "test_timeline :" << std::endl << tl << std::endl;
}

void test_animatedelement()
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
}

int main()
{
	test_rect();

	test_line();

	test_svg();

	test_file();

	tmp_test();

	test_timeline();

	test_animatedelement();

	return 0;	
}