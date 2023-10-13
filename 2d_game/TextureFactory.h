#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>

class TextureFactory {
public:
	static std::shared_ptr<sf::Texture> getTexture(std::string&& textureName);
	static void loadTexture(std::string&& texturePath, std::string&& textureName);

private:
	TextureFactory();
	TextureFactory(TextureFactory&);
	TextureFactory(TextureFactory&&);

private:
	static std::unordered_map<std::string, std::shared_ptr<sf::Texture>> m_textureMap;
};