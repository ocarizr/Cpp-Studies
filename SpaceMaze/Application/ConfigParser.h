#pragma once
class GameConfiguration
{
public:
	int windowWidth;
	int windowHeight;
private:
	GameConfiguration() = default;
	friend class ConfigParser;
};

class ConfigParser
{
public:
	static GameConfiguration parse(int argc, char* argv[]);

private:
	ConfigParser() = default;
};

