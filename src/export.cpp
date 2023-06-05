#include "export.h"

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


// Operator overload

std::ostream& operator<<(std::ostream & os, const Color & color)
{
	os << "rgb(" << color.m_red << "," << color.m_green << "," << color.m_blue << ")";

	return os;
}



/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////                 SVGElement                  ////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////



// Constructors

SVGElement::SVGElement()
{
	//
}


// Operator overloads

std::ostream& operator<<(std::ostream & os, const SVGElement & element)
{
	element.print(os);
	return os;
}


/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////                   SVGRect                   ////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////



// Constructors

SVGRect::SVGRect()
	: m_x(), m_y(), m_width(), m_height(), m_fill_color()
{

}

SVGRect::SVGRect(double x, double y, double width, double height, const Color & fill_color)
	: m_x(x), m_y(y), m_width(width), m_height(height), m_fill_color(fill_color)
{
	//
}


// Methods

void SVGRect::print(std::ostream & os) const
{
	os  << "<rect ";
	streamAttribute(os, "x", m_x);	
	streamAttribute(os, "y", m_y);
	streamAttribute(os, "width", m_width);
	streamAttribute(os, "height", m_height);
	streamAttribute(os, "fill", m_fill_color);
	os << "/>\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////                   SVGLine                   ////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////



// Constructors

SVGLine::SVGLine()
	: m_x1(), m_y1(), m_x2(), m_y2(), m_thickness(), m_stroke_color()
{
	//
}


SVGLine::SVGLine(double x1, double y1, double x2, double y2, double thickness, const Color & stroke_color)
	: m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2), m_thickness(thickness), m_stroke_color(stroke_color)
{
	//
}


// Methods

void SVGLine::print(std::ostream & os) const
{
	os  << "<line ";
	streamAttribute(os, "x1", m_x1);	
	streamAttribute(os, "y1", m_y1);
	streamAttribute(os, "x2", m_x2);	
	streamAttribute(os, "y2", m_y2);
	streamAttribute(os, "stroke-width", m_thickness);
	streamAttribute(os, "stroke", m_stroke_color);
	streamAttribute(os, "style", "stroke-linecap:round;stroke-linejoin:miter");
	os << "/>\n";
}



/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////               Other functions               ////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void streamAttribute(std::ostream & os, const std::string& attribute_name, const T & attribute_value)
{
	os << attribute_name << "=\"" << attribute_value << "\" ";
}