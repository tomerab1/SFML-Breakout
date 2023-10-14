#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>

class FontFactory
{
public:
	static const sf::Font& getFont(const std::string& fontPath);

private:
	static std::unordered_map<std::string, std::unique_ptr<sf::Font>> m_fontsMap;
};

