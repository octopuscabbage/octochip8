/*
 * CPU.h
 *
 *  Created on: Jan 16, 2014
 *      Author: octopuscabbage_
 */
#include <string>
#include <vector>
#pragma once

using std::vector;

class CPU {
public:
	const static int SCREEN_SIZE = 64 * 32;
	const static int SCREEN_WIDTH = 64;
	const static int SCREEN_HEIGHT = 32;
	CPU();
	virtual ~CPU();
	void initalize();;
	void loadGame(std::string filenamne);
	void emulateCycle();
	bool getDrawFlag();
	void seteys();
	vector<unsigned char> getGFX();
private:
	//The current operation code
			unsigned short opcode;
			//The virtual memory - 8k memory
			vector<unsigned char> memory(4096);
			//The CPU registers
			/*CPU registers: The Chip 8 has 15 8-bit general purpose registers named V0
			 * ,V1 up to VE. The 16th register is used  for the ‘carry flag’.
			 * Eight bits is one byte so we can use an unsigned char for this purpose:
			 */
			vector<unsigned char> V  (16);
			//Index register
			unsigned short I;
			//Program counter
			unsigned short pc;
			//graphics array array
			vector<unsigned char> gfx (SCREEN_SIZE);

			//The stack and the pointer to the current position
			vector<unsigned short> stack (16,100); //ha pancakes
			unsigned short sp;

			//the current state of the key
			unsigned char key[16];
};

#endif /* CPU_H_ */
