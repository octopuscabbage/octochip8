/*
 * Graphics.h
 *
 *  Created on: Jan 16, 2014
 *      Author: octopuscabbage_
 */
#include "CPU.h"
#pragama once

class Graphics {
public:
	void initalize();
	void draw(char screen[CPU.SCREEN_SIZE]);
	Graphics();
	virtual ~Graphics();
};


