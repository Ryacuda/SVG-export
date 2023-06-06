#include "svg_attributes.h"



/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////                    Color                    ////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


// Constructors


Color::Color()
	: m_red(0), m_green(0), m_blue(0)
{
	//
}


Color::Color(unsigned short r, unsigned short g, unsigned short b)
	: m_red(r), m_green(g), m_blue(b)
{
	//
}


// Methods

void Color::print(std::ostream & os) const
{
	os << "rgb(" << m_red << "," << m_green << "," << m_blue << ")";
}