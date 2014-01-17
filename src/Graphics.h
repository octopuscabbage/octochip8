/*
 * Graphics.h
 *
 *  Created on: Jan 16, 2014
 *      Author: octopuscabbage_
 */


#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "CPU.h"
#include <vector>
using std::vector;

class Graphics {
public:
	void initalize();
	void draw(std::vector<unsigned char> screen);
	Graphics();
	virtual ~Graphics();
};
#endif