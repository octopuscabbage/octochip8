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
	const static int SCREEN_SIZE = 64 * 32; /**< The amount of pixels for the screen */
	const static int SCREEN_WIDTH = 64; /**The width of the screen in pixels. */
	const static int SCREEN_HEIGHT = 32; /** The height of the screen in pixels. */
	
        /**
         * The constructor for the class, initalise must be called after this to be used.
         */
        CPU();
	virtual ~CPU();
        /**
         * Called after construction, sets up all registers and memory.
         */
	void initalize(); 
        /**
         * Load a game into the emulator. 
         * @param filenamne The file to load. Type will probably change later.
         */
	void loadGame(std::string filenamne);
        /**
         * Emulate a cycle of the CPU
         */
	void emulateCycle();
        /**
         * Gets the current draw flag determining wether or not to draw during this cpu cycle.
         * @return A bool of the current draw flag. True = Draw screen. False = Don't draw screen.
         */
	bool getDrawFlag();
        /**
         * Sets the keys for the current screen.
         */
	void setKeys();
	vector<unsigned char> getGFX();
        
private:
    
        unsigned short opcode; /**<The current operation code. */

                        
			vector<unsigned char> memory(4096); /**<The virtual memory - 8k memory*/
			
			vector<unsigned char> V  (16); /** < The CPU registers. CPU registers: The Chip 8 has 15 8-bit general purpose registers named V0,V1 up to VE. The 16th register is used  for the ‘carry flag’.*/
                        
			
                        
                        unsigned short I; /**<The index register, counts down from value to 0 when in use. */

                        
			unsigned short pc; /**< The program counter, counts down from value to 0 when in use.*/
                        
			vector<unsigned char> gfx (CPU::SCREEN_SIZE); /**< A vector representing the current screen */

                        
                        
			vector<unsigned short> stack (16); /**< The stack. Has 16 levels. ha pancakes */
			unsigned short sp; /**The pointer to the current level in the stack */

			
			vector<unsigned char> key (16); /** < The current state of the key */
			
};

#endif /* CPU_H_ */
