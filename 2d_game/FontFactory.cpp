#include "FontFactory.h"

std::unordered_map<std::string, std::unique_ptr<sf::Font>>
    FontFactory::m_fontsMap;

const sf::Font& FontFactory::getFont(const std::string& fontPath) {
  try {
    if (m_fontsMap.find(fontPath) == m_fontsMap.cend()) {
      m_fontsMap[fontPath] = std::make_unique<sf::Font>();
      m_fontsMap[fontPath].get()->loadFromFile(fontPath);
    }

    return *m_fontsMap[fontPath].get();
  } catch (std::exception& ex) {
    throw ex;
  }
}
