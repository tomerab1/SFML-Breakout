#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Globals.h"

class GameEntity {
 public:
  virtual void render(sf::RenderWindow& window) = 0;
  virtual void update(float dt) = 0;
  virtual void update(float dt, GameEntity& entity) = 0;
  virtual void setTexture(std::shared_ptr<sf::Texture> texture) = 0;
  virtual CollisionType checkCollisions() = 0;
  virtual CollisionType checkCollisions(sf::Shape& shape) = 0;
  virtual sf::Shape& getEntity() = 0;
  virtual ~GameEntity() {}
};