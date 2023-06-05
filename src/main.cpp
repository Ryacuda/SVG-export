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



int main()
{
	test_rect();

	test_line();

	return 0;	
}