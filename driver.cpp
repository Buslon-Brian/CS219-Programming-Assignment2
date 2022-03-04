/**
 * CS219: program reads from an input file and translates the text from assembly language to execute the commands 
 * and display the results
 * @file driver.cpp
 * @author Brian Basil Buslon (bbuslon@nevada.unr.edu)
 * @version 1.0 03/03/2022
 */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Command.h"
#define A_LIMIT 100

int LoadInstructions(Command InstructionSet[A_LIMIT]);
void DisplayResults(Command InstructionSet[A_LIMIT], int num_commands);

int main(){
    int num_commands;
    
    Command InstructionSet[A_LIMIT];
    num_commands = LoadInstructions(InstructionSet);
    DisplayResults(InstructionSet, num_commands);
    
    return 0; 
}

/**
 * @brief Function initializes a Command object containing a line from the file "inputs.txt" and stores it into 
 * an array
 * @param InstructionSet an array of data type Command
 * @return int which is the number of command objects instantiated
 */

int LoadInstructions(Command InstructionSet[A_LIMIT]){
    int i = 0;
    uint32_t test;
    std::string assem_operator;
    std::string operand1;
    std::string operand2;
    
    std::ifstream Instructions;
    Instructions.open("inputs.txt");
    
    if(Instructions.is_open()){
        while(Instructions >> assem_operator){
            Instructions >>  operand1;
            Instructions >> operand2;

            Command Line(assem_operator, operand1, operand2);
        
            InstructionSet[i] = Line;
            i++;

          
        }
    }

    Instructions.close();
    return i;
    }

/**
 * @brief Function iterates through array and outputs the results calculated internally through the Command Object 
 * 
 * @param InstructionSet An array of data type Command
 * @param num_commands the number of command objects instantiated
 */

void DisplayResults(Command InstructionSet[A_LIMIT], int num_commands){
    for(int i = 0; i < num_commands; i++){
        std::cout << "Command: " << InstructionSet[i].get_operator() << " ";
        std::cout << InstructionSet[i].get_operand1() << " ";
        std::cout << InstructionSet[i].get_operand2() << " ";
        std::cout << "| Result:" << InstructionSet[i].get_result() << std::endl;
    }
}