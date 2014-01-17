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
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

CPU cpu; /**<The CPU object to be used */
Graphics gpu; /**The GPU object to be used */
Input input; /**The input object to be used */
/**
 * The main function to start it all off.
 * @return Exit code. 0 is normal.
 */
int main(void) {
	cout << "initalizing gpu" << endl;
    gpu.initalize();

    cout << "initialising input" << std::endl;
    input.initalize();

    cout << "initialising cpu" << std::endl;
    cpu.initalize();

    string game = "pong";
    cout<<"loading game " << game << endl;
    cpu.loadGame(game);
    cout<<"loaded";

    while(cpu.running){
        cpu.emulateCycle();
        if(cpu.getDrawFlag()){
        	cout << "redrawing screen" << endl;
            gpu.draw(cpu.getGFX());
            cpu.setDrawFlag(false);
        }
        cpu.setKeys();
    }
	return 0;
}
