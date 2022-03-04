#include "Command.h"

Command::Command(){}

Command::Command(std::string new_operator, std::string new_o1, std::string new_o2){
    assem_operator = new_operator;
    operand1 = new_o1;
    operand2 = new_o2;
    result = "0x";
    Calculate();
}


std::string Command::get_operator(){
    return assem_operator;
}

std::string Command::get_operand1(){
    return operand1;
}

std::string Command::get_operand2(){
    return operand2;
}

std::string Command::get_result(){
    return result;
}


void Command::Calculate(){
    uint32_t hexval1;
    uint32_t hexval2;
    uint32_t hex_result;

    hexval1 = std::stoul(operand1, nullptr, 16);
    hexval2 = std::stoul(operand2, nullptr, 16);

    if(this->get_operator() == "ADD"){
        hex_result = hexval1 + hexval2;
    }

    else if(this->get_operator() == "AND"){
        hex_result = hexval1 & hexval2;
    }

    else if(this->get_operator() == "ASR"){
        int32_t shex_val = hexval1;
        hex_result = shex_val >> 1;
    }

    else if(this->get_operator() == "LSR"){
        hex_result = hexval1 >> 1;
    }

    else if(this->get_operator() == "LSL"){
        hex_result = hexval1 << 1;
    }

    else if(this->get_operator() == "NOT"){
        hex_result = ~hexval1;
    }

    else if(this->get_operator() == "ORR"){
        hex_result = hexval1 | hexval2;
    }

    else if(this->get_operator() == "SUB"){
        hex_result = hexval1 - hexval2;
    }

    else if(this->get_operator() == "XOR"){
        hex_result = hexval1 ^ hexval2;
    }

    else{
        result = "ERROR";
    }


    std::stringstream sstream;
    sstream << std::hex << hex_result;
    result.append(sstream.str());
    
    int i = 0;
    while(result[i] != '\0'){
        result[i] = std::toupper(result[i]);
        i++;
        result[1] = 'x';
    }

}