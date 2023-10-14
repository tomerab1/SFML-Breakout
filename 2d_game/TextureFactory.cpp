#include "TextureFactory.h"

#include "Exceptions.h"

std::unordered_map<std::string, std::shared_ptr<sf::Texture>>
    TextureFactory::m_textureMap;

void TextureFactory::loadTexture(const std::string& texturePath,
                                 const std::string& textureName) {
  sf::Texture texture;

  if (!texture.loadFromFile(texturePath))
    throw LoadTextureException("Failed to load texture: " + textureName);

  TextureFactory::m_textureMap[textureName] =
      std::make_shared<sf::Texture>(texture);
}

std::shared_ptr<sf::Texture> TextureFactory::getTexture(
    const std::string& textureName) {
  if (TextureFactory::m_textureMap.find(textureName) ==
      TextureFactory::m_textureMap.end())
    throw LoadTextureException("Failed to load texture: " + textureName);
  return TextureFactory::m_textureMap[textureName];
}
