#pragma once

#include <SFML/Graphics.hpp>

class Scene {
 public:
  virtual void update(float dt) = 0;
  virtual void render(sf::RenderWindow& window) = 0;

  virtual ~Scene() {}
};