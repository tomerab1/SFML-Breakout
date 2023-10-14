#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>

class TextureFactory {
 public:
  using ret_type = std::shared_ptr<sf::Texture>;

  static ret_type getTexture(const std::string& textureName);
  static void loadTexture(const std::string& texturePath,
                          const std::string& textureName);

 private:
  TextureFactory();
  TextureFactory(TextureFactory&);
  TextureFactory(TextureFactory&&);

  static std::unordered_map<std::string, ret_type> m_textureMap;
};