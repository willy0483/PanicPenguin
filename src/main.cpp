#include "../httplib.h"
#include <iostream>

int main()
{
	httplib::Client cli("http://jsonplaceholder.typicode.com");

	if(httplib::Result res = cli.Get("/todos/1"))
	{
		std::cout << "Status: " << res->status << std::endl;
		std::cout << "Body: " << res->body << std::endl;
	}

	return 0;
}
