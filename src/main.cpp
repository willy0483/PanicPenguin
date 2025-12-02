#include "../httplib.h"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, const char* argv[])
{

	std::ifstream file("test.txt");
	if(!file.is_open())
	{
		std::cout << "[ERROR] Could not open file: " << std::endl;
		return 1;
	}
	else
	{
		std::cout << "[INFO] Successfully opened file: " << std::endl;
	}

	std::string line;
	httplib::Client cli("http://jsonplaceholder.typicode.com");

	while(std::getline(file, line))
	{
		if(!line.empty())
		{
			std::cout << "Requesting: " << line << " ";
			httplib::Result result = cli.Get(line.c_str());
			if(result)
			{
				std::cout << " - Status: " << result->status << std::endl;
			}
			else
			{
				std::cout << line << " - Error: " << result.error() << std::endl;
			}
		}
	}
	return 0;
}
