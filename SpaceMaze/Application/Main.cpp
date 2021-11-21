#include "Application.h"

int main(int argc, char* argv[])
{
	auto config = ConfigParser::parse(argc, argv);
	auto app = Application::create(config);
	return app.start();
}