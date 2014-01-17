/*
 * CPU.h
 *
 *  Created on: Jan 16, 2014
 *      Author: octopuscabbage_
 */
#include <string>
#include <vector>
#ifndef CPU_H
#define CPU_H

using std::vector;

class CPU {
public:
	const static int SCREEN_SIZE = 64 * 32; /**< The amount of pixels for the screen */
	const static int SCREEN_WIDTH = 64; /**The width of the screen in pixels. */
	const static int SCREEN_HEIGHT = 32; /** The height of the screen in pixels. */

	bool running; /**<A boolean for the running state of the CPU */

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
	 * Sets the draw flag. Should be called at end of every cpu loop.
	 *@param flag The boolean value to set the draw flag.
	 */
	void setDrawFlag(bool flag);
	/**
	 * Sets the keys for the current screen.
	 */
	void setKeys();
	/**
	 * Gets the vector object of pixels for the current screen.
	 */
	vector<unsigned char> getGFX();

private:
	/**
	 * Sets the opcode of the current program to the instruction at PC.
	 */
	void setOpcode();
	/**
	 * Executes the opcode of the current program.
	 * Opcode Table:
	 * Opcode	Explanation
	 * 0NNN		Calls RCA 1802 program at address NNN.
	 * 00E0		Clears the screen.
	 * 00EE		Returns from a subroutine.
	 * 1NNN		Jumps to address NNN.
	 * 2NNN		Calls subroutine at NNN.
	 * 3XNN		Skips the next instruction if VX equals NN.
	 * 4XNN		Skips the next instruction if VX doesn't equal NN.
	 * 5XY0		Skips the next instruction if VX equals VY.
	 * 6XNN		Sets VX to NN.
	 * 7XNN		Adds NN to VX.
	 * 8XY0		Sets VX to the value of VY.
	 * 8XY1		Sets VX to VX or VY.
	 * 8XY2		Sets VX to VX and VY.
	 * 8XY3		Sets VX to VX xor VY.
	 * 8XY4		Adds VY to VX. VF is set to 1 when there's a carry, and to 0 when there isn't.
	 * 8XY5		VY is subtracted from VX. VF is set to 0 when there's a borrow, and 1 when there isn't.
	 * 8XY6		Shifts VX right by one. VF is set to the value of the least significant bit of VX before the shift.[2]
	 * 8XY7		Sets VX to VY minus VX. VF is set to 0 when there's a borrow, and 1 when there isn't.
	 * 8XYE		Shifts VX left by one. VF is set to the value of the most significant bit of VX before the shift.[2]
	 * 9XY0		Skips the next instruction if VX doesn't equal VY.
	 * ANNN		Sets I to the address NNN.
	 * BNNN		Jumps to the address NNN plus V0.
	 * CXNN		Sets VX to a random number and NN.
	 * DXYN		Draws a sprite at coordinate (VX, VY) that has a width of 8 pixels and a height of N pixels. Each row of 8 pixels is read as bit-coded (with the most significant bit of each byte displayed on the left) starting from memory location I; I value doesn't change after the execution of this instruction. As described above, VF is set to 1 if any screen pixels are flipped from set to unset when the sprite is drawn, and to 0 if that doesn't happen.
	 * EX9E		Skips the next instruction if the key stored in VX is pressed.
	 * EXA1		Skips the next instruction if the key stored in VX isn't pressed.
	 * FX07		Sets VX to the value of the delay timer.
	 * FX0A		A key press is awaited, and then stored in VX.
	 * FX15		Sets the delay timer to VX.
	 * FX18		Sets the sound timer to VX.
	 * FX1E		Adds VX to I.[3]
	 * FX29		Sets I to the location of the sprite for the character in VX. Characters 0-F (in hexadecimal) are represented by a 4x5 font.
	 * FX33		Stores the Binary-coded decimal representation of VX, with the most significant of three digits at the address in I, the middle digit at I plus 1, and the least significant digit at I plus 2. (In other words, take the decimal representation of VX, place the hundreds digit in memory at location in I, the tens digit at location I+1, and the ones digit at location I+2.)
	 * FX55		Stores V0 to VX in memory starting at address I.[4]
	 * FX65		Fills V0 to VX with values from memory starting at address I.[4]
	 */
	void executeOpcode();
	unsigned short opcode; /**<The current operation code. */

	vector<unsigned char> memory; /**<The virtual memory - 8k memory*/

	vector<unsigned char> V; /** < The CPU registers. CPU registers: The Chip 8 has 15 8-bit general purpose registers named V0,V1 up to VE. The 16th register is used  for the ‘carry flag’.*/

	unsigned short I; /**<The index register, counts down from value to 0 when in use. */

	unsigned short pc; /**< The program counter, counts down from value to 0 when in use.*/

	vector<bool> gfx; /**< A vector representing the current screen */

	vector<unsigned short> stack; /**< The stack. Has 16 levels. ha pancakes */
	unsigned short sp; /**The pointer to the current level in the stack */

	vector<unsigned char> key; /** < The current state of the key */
	bool drawFlag;
};
#endif
