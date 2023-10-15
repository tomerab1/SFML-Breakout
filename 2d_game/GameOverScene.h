#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

#include "Scene.h"

class GameOverScene : public Scene {
 public:
  explicit GameOverScene(uint32_t score);

  void update(float dt) override;
  void render(sf::RenderWindow& window) override;

 private:
  std::unique_ptr<sf::Font> m_font;
  sf::Text m_text;
};
