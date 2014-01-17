/*
 ============================================================================
 Name        : octochip8.cpp
 Author      : 
 Version     :
 Copyright   : Included in lisense.
 Description : A chip8 emulator for practice
 ============================================================================
 */

#include "CPU.h"
#include "Graphics.h"
#include "Input.h"
using namespace std;
CPU cpu; /**<The CPU object to be used */
Graphics gpu; /**The GPU object to be used */
Input input; /**The input object to be used */
/**
 * The main function to start it all off.
 * @return Exit code. 0 is normal.
 */
int main(void) {
    gpu.initalize();
    input.initalize();
    cpu.initalize();
    cpu.loadGame("pong");
    while(cpu.running){
        cpu.emulateCycle();
        if(cpu.getDrawFlag()){
            gpu.draw(cpu.getGFX());
        }
        cpu.setDrawFlag(false);
        cpu.setKeys();
    }
	return 0;
}
