//SerialBox. Serial Read and Write Terminal
//Licensed under MIT License (https://opensource.org/license/MIT)
//Copyright (c) 2025 Valorie Barela
//References:
//https://cool-emerald.blogspot.com/2017/05/serial-port-programming-in-c-with.html
//https://github.com/yan9a/serial/blob/ed8889851e4969496e0057a3d94b191e1a817613/ceserial.h

#include "ceserial.h"
#include <iostream>

int main(int argc, char *argv[]) {
	
	std::string comPortStr1(argv[1]);
    std::string comSpeedStr(argv[2]);
    int comSpeedInt = std::stoi(comSpeedStr);
	std::string termMode(argv[3]);

    #ifdef _WIN32
        std::cout << "Windows Detected" << std::endl;
        std::string comPortStr2 = "\\\\.\\" + comPortStr1;
	    ceSerial com(comPortStr2,comSpeedInt,8,'N',1); // Windows
    #else
        std::cout << "Linux Detected" << std::endl;
	    ceSerial com(comPortStr1,comSpeedInt,8,'N',1); // Linux
    #endif

	    std::cout << "Opening Port" << comPortStr1 << std::endl;
	    if (com.Open() == 0) {
			std::cout << "Port Opened Successfully " << std::endl;
	    }
	    else {
			std::cout << "Error Opening Port " << std::endl;
			while (std::cin.get() != '\n');
		    return 1;
	    }

	    bool successFlag;
        int loopVar = 1;

		if (termMode == "r"){
			std::cout << "Begin Reading." << std::endl;

        	while (loopVar == 1){
	        	char c=com.ReadChar(successFlag); // read a char
            	if(successFlag) std::cout << c;
			}
		} else if (termMode == "w"){
			std::cout << "Begin Writing." << std::endl;

			while (loopVar == 1){
				std::string writeInput = "";
				std::getline (std::cin,writeInput);
					if (writeInput.length() > 1){
						successFlag=com.Write(writeInput.c_str());
						if(successFlag == 0) std::cout << "Message Send Fail";
					}
			}
		} else {
			std::cout << "Invalid Mode" << std::endl;
			while (std::cin.get() != '\n');
		}

		std::cout << "Closing Port " << comPortStr1 << std::endl;
	    com.Close();
	    return 0;
}
