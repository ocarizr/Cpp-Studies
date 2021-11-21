#ifndef APPLICATION_H
#define APPLICATION_H

#include <Windows.h>

#include "ConfigParser.h"

class Application
{
public:
	~Application() { close(); }

	static Application create(const GameConfiguration& config);
	
	int start();

private:
	Application() = default;

	void pump();

	int close();

	// Member variables
private:
	WNDCLASS window;
	HWND windowHandle;
};

#endif // APPLICATION_H
