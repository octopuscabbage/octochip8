/*
 * CPU.cpp
 *
 *  Created on: Jan 16, 2014
 *      Author: octopuscabbage_
 */
#include <algorithm>
#include "CPU.h"

CPU::CPU() {
	memory.resize(4096);
	V.resize(16);
	gfx.resize(CPU::SCREEN_SIZE);
	stack.resize(16);
	key.resize(16);
}

CPU::~CPU() {
	// TODO Auto-generated destructor stub
}

void CPU::initalize() {
	running=true;
}

void CPU::loadGame(std::string filenamne) {
}

void CPU::emulateCycle() {
	setOpcode();
	executeOpcode();
}


bool CPU::getDrawFlag() {
	return drawFlag;
}

void CPU::setKeys() {
}

vector<unsigned char> CPU::getGFX() {
}

void CPU::setOpcode() {
	opcode = memory[pc] << 8 | memory[pc+1];
}

void CPU::setDrawFlag(bool flag) {
	drawFlag = flag;
}
void CPU::executeOpcode(){ //TODO: optimize. test

	//Used for speedup so that it only has to be computed one time.
	//TODO MAKE SURE THIS IS USEFUL
	unsigned short first_nibble = opcode & 0xF000;
	unsigned short first_byte = opcode & 0xFF00;
	unsigned short last_byte = opcode & 0x00FF;

	switch(first_nibble){
		//Opcodes beggining with 0
		case(0x000):
			switch(opcode){
				//Clear the screen. Sets draw flag
				case(0x00E0):
						std::fill(gfx.begin(),gfx.end(),false);
						drawFlag = true;
						break;
				//Return from subroutine.
				case(0x00EE):
						//TODO: This is probably wrong
						sp +=1;
						break;
				//Calls RCA 1802 at program address NNN.
				//Opcode should be 0x0NNN
				default:
					//TODO what the fuck does that mean?
					break;

			}
			pc+=2;
			break;
		//Jumps to address NNN.
		//Opcode should be 0x1NNN
		case(0x1000):
				pc = opcode && 0x0FFF;
				break;

		//Calls subroutine at NNN.
		//Opcode should be 0x2NNN
		case(0x2000):
				//TODO fill this in.
				pc+=2;
				break;
		//Skips the next instruction if VX equals NN.
		//Opcode should be 0x3XNN
		case(0x3000):
				//TODO this looks fishy
				(V.at(opcode & 0x0F00) == last_byte)? pc+=4 : pc+=2;
				break;
		//Skips the next instruction if VX doesn't equal NN.
		//Opcode should be 4XNN
		case(0x4000):
				//TODO not so confident in this
				(V.at(opcode & 0x0F00) != last_byte)? pc+=4 : pc+=2;
				break;
		//Skips the next instruction if VX equals VY.
		//Opcode should be 5XY0
		case(0x5000):
				//TODO make sure this works
				(V.at(opcode & 0x0F00) == V.at(opcode & 0x00F0))? pc+=4 : pc+=2;
				break;
		//Sets VX to NN.
		//Opcode should be 6XNN
		case(0x6000):
				V.at(opcode & 0x0F00) = opcode & 0x00FF;
				break;
		//Adds NN to VX.
		//Opcode should be 7XNN
		case(0x7000):
				V.at(opcode & 0x0F00) += last_byte;
				break;

	}
}

