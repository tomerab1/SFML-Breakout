#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Scene.h"

class PauseScene : public Scene {
 public:
  PauseScene();

  virtual void update(float dt) override;
  virtual void render(sf::RenderWindow& window) override;

 private:
  sf::Text m_text;
  std::unique_ptr<sf::Font> m_font;
};
