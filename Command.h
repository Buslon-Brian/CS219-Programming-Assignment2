#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <sstream>

class Command{
    private:
    std::string assem_operator;
    std::string operand1;
    std::string operand2;
    std::string result;

    void Calculate();

    public:
    Command();
    Command(std::string, std::string, std::string);

    std::string get_operator();
    std::string get_operand1();
    std::string get_operand2();
    std::string get_result();

   
    };
#endif