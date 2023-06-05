#include "export.h"

void test_rect()
{
	SVGLine l;

	std::cout << "test_line : " << std::endl << l << std::endl;
}



void test_line()
{
	SVGRect r;

	std::cout << "test_rect : " << std::endl << r << std::endl;
}


void test_svg()
{
	SVGSvg svg(0,0,120,120);

	Color red(255,0,0);

	std::shared_ptr<SVGElement> ptr_r = std::make_shared<SVGRect>(10,10, 110, 110, red);

	svg.addElement(ptr_r);

	std::cout << "test_svg :" << std::endl << svg << std::endl;
}


void test_file()
{
	Color red(255,0,0);
	std::shared_ptr<SVGElement> ptr_r = std::make_shared<SVGRect>(10,10, 110, 110, red);

	SVGSvg svg(0,0,120,120);
	svg.addElement(ptr_r);

	std::ofstream file;
	file.open("test_svg.svg");

	file << svg;

	file.close();
}


int main()
{
	test_rect();

	test_line();

	test_svg();

	test_file();

	return 0;	
}