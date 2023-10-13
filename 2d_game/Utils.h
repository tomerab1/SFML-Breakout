#pragma once

#include <SFML/graphics.hpp>

class Utils
{
public:
	static sf::Color hexStringToColor(std::string&& color)
	{
		uint32_t colorInt = std::stoul(color, nullptr, 16);
		return sf::Color((colorInt & 0xff0000) >> 16, (colorInt & 0x00ff00) >> 8, colorInt & 0x0000ff);
	}
};