#pragma once

#include "streamable.h"

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////                    Color                    ////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @brief Color class to manage the components and it's output
 **/
struct Color : public Streamable
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

	// Methods

	/**
	 * @brief Implementation of the pure virtual function from Streamable
	 * @brief Outputs the Color to the stream parameter 
	 * @param os The output stream
	 **/
	void print(std::ostream & os) const;

	// Members
	unsigned short m_red;		// Red color component
	unsigned short m_green;		// Green color component
	unsigned short m_blue;		// Blue color component
};