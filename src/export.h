#pragma once

#include <cstdint>
#include <iostream>
#include <string>




/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////                    Color                    ////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief Color class to manage the components and it's output
 **/
struct Color
{
	// Constructors

	/**
	 * @brief Constructor, initializes red, green and blue components to 0
	 **/
	Color();

	/**
	 * @brief Constructor, initializes red, green and blue components with parameters
	 * @param r The value of the red component
	 * @param g The value of the green component
	 * @param b The value of the blue component
	 **/
	Color(unsigned short r, unsigned short g, unsigned short b);

	// Operator overload

	/**
	 * @brief operator<< overload for displaying and file writing purpose
	 * @param os The output stream
	 * @param color The color to output
	 * @returns The output stream
	 **/
	friend std::ostream& operator<<(std::ostream & os, const Color & color);

	// Members
	unsigned short m_red;		// Red color component
	unsigned short m_green;		// Green color component
	unsigned short m_blue;		// Blue color component
};



/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////                 SVGElement                  ////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief Abstract class, any SVG element will inherit from SVGElement (makes sense so far)
 **/
class SVGElement
{
public:
	// Constructors
	
	/**
	 * @brief Constructor, initializes all members with default constructor
	 **/
	SVGElement();

	// Methods

	/**
	 * @brief Pure virtual method, output the SVGElement to the stream 
	 * @brief (called by operator<<(std::ostream & os, const SVGElement & element) )
	 * @param os The output stream
	 **/
	virtual void print(std::ostream & os) const = 0;

	// Operator overloads

	/**
	 * @brief operator<< overload for displaying and file writing purpose
	 * @param os The output stream
	 * @param color The SVG element to output
	 * @returns The output stream
	 **/
	friend std::ostream& operator<<(std::ostream & os, const SVGElement & element);
};



/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////                   SVGRect                   ////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief SVG rectangle, inherits from SVGElement
 **/
class SVGRect : public SVGElement
{
public:
	// Constructors

	/**
	 * @brief Constructor, initializes all members with default constructor
	 **/
	SVGRect();

	/**
	 * @brief Constructor, initializes all members with parameters
	 * @param x The x coordinate of the top left corner of the rectangle
	 * @param y The y coordinate of the top left corner of the rectangle
	 * @param width The width of the rectangle
	 * @param height The height of the rectangle
	 * @param fill_color The color of the rectangle
	 **/
	SVGRect(double x, double y, double width, double height, const Color & fill_color);

	// Methods

	/**
	 * @brief Implementation of the pure virtual function from SVGElement
	 * @brief Outputs the SVGRect to the stream parameter 
	 * @param os The output stream
	 **/
	void print(std::ostream & os) const;

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


/**
 * @brief SVG line, inherits from SVGElement
 **/
class SVGLine : public SVGElement
{
public:
	// Constructors

	/**
	 * @brief Constructor, initializes all members with default constructor
	 **/
	SVGLine();

	/**
	 * @brief Constructor, initializes all members with parameters
	 * @param x1 The x coordinate of the first point
	 * @param y1 The y coordinate of the first point
	 * @param x2 The x coordinate of the second point
	 * @param y2 The y coordinate of the second point
	 * @param thickness The thickness of the line
	 * @param stroke_color The color of the line
	 **/
	SVGLine(double x1, double y1, double x2, double y2, double thickness, const Color & stroke_color);

	// Methods

	/**
	 * @brief Implementation of the pure virtual function from SVGElement
	 * @brief Outputs the SVGLine to the stream parameter 
	 * @param os The output stream
	 **/
	void print(std::ostream & os) const;

private:
	// Members
	double m_x1;				// First point x coordinate
	double m_y1;				// First point y coordinate
	double m_x2;				// Second point x coordinate
	double m_y2;				// Second point y coordinate
	double m_thickness;			// Thickness of the line
	Color m_stroke_color;		// 
};

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////               Other functions               ////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Template function to output an SVG attribute to a stream
 * @param os The output stream
 * @param attribute_name The name of the attribute
 * @param attribute_value The value associated to the attribute
 **/
template<class T>
void streamAttribute(std::ostream & os, const std::string& attribute_name, const T & attribute_value);