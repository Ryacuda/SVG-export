#pragma once

#include <cstdint>
#include <iostream>
#include <string>




/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////                    Color                    ////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////



struct Color
{
	// Constructors

	Color();

	Color(unsigned short r, unsigned short g, unsigned short b);

	// Operator overload

	friend std::ostream& operator<<(std::ostream & os, const Color & color);

	// Members
	unsigned short m_red;
	unsigned short m_green;
	unsigned short m_blue;
};



/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////                   SVGRect                   ////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////



class SVGRect
{
public:
	// Constructors

	SVGRect();

	SVGRect(double x, double y, double width, double height, const Color & fill_color);

	// Operator overloads

	friend std::ostream& operator<<(std::ostream & os, const SVGRect & rect);

private:
	// Members
	double m_x;					// Top left corner x coordinate
	double m_y;					// Top left corner y coordinate
	double m_width;				// Rectangle width
	double m_height;			// Rectangle height
	Color m_fill_color;			// RGB color of the rectangle
};



/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////                   SVGLine                   ////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////



class SVGLine
{
public:
	// Constructors

	SVGLine();

	SVGLine(double x1, double y1, double x2, double y2, double thickness, const Color & stroke_color);

	// Operator overloads

	friend std::ostream& operator<<(std::ostream & os, const SVGLine & line);

private:
	// Members
	double m_x1;
	double m_y1;
	double m_x2;
	double m_y2;
	double m_thickness;
	Color m_stroke_color;
};

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////               Other functions               ////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
std::ostream& streamAttribute(std::ostream & os, const std::string& attribute_name, const T & attribute_value);