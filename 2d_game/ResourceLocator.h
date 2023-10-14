#pragma once

#include <memory>

#include "FontFactory.h"
#include "TextureFactory.h"

template <typename R>
struct ResourceLocator;

template <>
class ResourceLocator<TextureFactory> {
 public:
  static TextureFactory::ret_type getTexture(const std::string& textureName) {
    return TextureFactory::getTexture(textureName);
  }

  static void loadTexture(const std::string& texturePath,
                          const std::string& textureName) {
    TextureFactory::loadTexture(texturePath, textureName);
  }
};

template <>
class ResourceLocator<FontFactory> {
 public:
  static const sf::Font& getFont(const std::string& fontPath) {
    return FontFactory::getFont(fontPath);
  }
};