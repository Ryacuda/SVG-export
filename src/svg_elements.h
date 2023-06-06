#pragma once

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "svg_attributes.h"



/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////                 SVGAnimate                  ////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief SVG animate element, inherits from Streamable
 * @brief Convoluted class structure, but the logic is that an <animate> tag 
 * @brief cannot have <animate> tags nested within
 **/
class SVGAnimate : public Streamable
{
public:
	// Constructors
	
	/**
	 * @brief Constructor, initializes all members with default constructor
	 **/
	SVGAnimate();

	// Methods

	/**
	 * @brief Implementation of the pure virtual function from Streamable
	 * @brief Outputs the SVGAnimate to the stream parameter 
	 * @param os The output stream
	 **/
	void print(std::ostream & os) const;

private:
	bool m_calc_mode_spline;			// Wether the animate attribute clacMode is equal to "spline" or not
	int m_repeat_count;					// Number of animation loops (value < 0 will be treated as "indefinite")
	int m_duration;						// Duration of one animation loop (in milliseconds)

};	



/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////             SVGAnimatedElement              ////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief SVG animated element, inherits from Streamable
 * @brief Abstract class, any SVG element that support animation will inherit from SVGAnimatedElement
 * @brief i.e elements that can have nested <animate> tags
 **/
class SVGAnimatedElement : public Streamable
{
public:
	// Constructors

	/**
	 * @brief Constructor, initializes all members with default constructor
	 **/
	SVGAnimatedElement();

	// Methods

	/**
	 * @brief Pure virtual method, output the SVGAnimatedElement to the stream 
	 * @brief (called by operator<<(std::ostream & os, const Streamable & element) )
	 * @param os The output stream
	 **/
	virtual void print(std::ostream & os) const = 0;

	void addAnimation(const SVGAnimate & animation);

private:
	std::vector<SVGAnimate> m_animations;
};



/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////                   SVGSvg                    ////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief SVG svg, inherits from SVGAnimatedElement
 * @brief Represents the <svg> ... </svg> tag
 * @brief Also acts as a container of other svg elements
 **/
class SVGSvg : public SVGAnimatedElement
{
public:
	// Constructors

	/**
	 * @brief Constructor, initializes all members with default constructor
	 **/
	SVGSvg();

	/**
	 * @brief Constructor, initializes all members with parameters
	 * @param x The x coordinate of the top left corner of the SVG
	 * @param y The y coordinate of the top left corner of the SVG
	 * @param width The width of the SVG
	 * @param height The height of the SVG
	 **/
	SVGSvg(double x, double y, double width, double height);

	// Methods

	/**
	 * @brief Implementation of the pure virtual function from SVGAnimatedElement
	 * @brief Outputs the SVGSvg to the stream parameter 
	 * @param os The output stream
	 **/
	void print(std::ostream & os) const;

	void addElement(const std::shared_ptr<SVGAnimatedElement> & ptr_element);

private:
	// Members
	double m_x;					// Top left corner x coordinate
	double m_y;					// Top left corner y coordinate
	double m_width;				// SVG width
	double m_height;			// SVG height
	std::vector< std::shared_ptr<SVGAnimatedElement> > m_contained_elements;	// svg elements within the svg tags
};



/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////                   SVGRect                   ////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief SVG rectangle, inherits from SVGAnimatedElement
 * @brief Represents the <rect> ... </rect> tag
 **/
class SVGRect : public SVGAnimatedElement
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
	 * @brief Implementation of the pure virtual function from SVGAnimatedElement
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
 * @brief SVG line, inherits from SVGAnimatedElement
 * @brief Represents the <line> ... </line> tag
 **/
class SVGLine : public SVGAnimatedElement
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
	 * @brief Implementation of the pure virtual function from SVGAnimatedElement
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
void streamAttribute(std::ostream & os,
					const std::string& attribute_name,
					const T & attribute_value,
					const std::string & attribute_unit = "");