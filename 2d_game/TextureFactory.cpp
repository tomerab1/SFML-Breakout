#include "TextureFactory.h"

std::unordered_map<std::string, std::shared_ptr<sf::Texture>>
    TextureFactory::m_textureMap;

void TextureFactory::loadTexture(std::string&& texturePath,
                                 std::string&& textureName) {
  sf::Texture texture;

  if (!texture.loadFromFile(texturePath))
    throw new std::runtime_error("Could not load texture from " + texturePath);

  TextureFactory::m_textureMap[textureName] =
      std::make_shared<sf::Texture>(texture);
}

std::shared_ptr<sf::Texture> TextureFactory::getTexture(
    std::string&& textureName) {
  if (TextureFactory::m_textureMap.find(textureName) ==
      TextureFactory::m_textureMap.end())
    throw std::runtime_error("Invalid texture name " + textureName);
  return TextureFactory::m_textureMap[textureName];
}
