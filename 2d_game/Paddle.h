#pragma once

#include <SFML/Graphics.hpp>

#include "GameEntity.h"
#include "Globals.h"

class Paddle : public GameEntity {
 public:
  Paddle();
  virtual void render(sf::RenderWindow& window) override;
  virtual void update(float dt, GameEntity& ball) override;
  virtual void setTexture(std::shared_ptr<sf::Texture> texture) override;
  virtual sf::Shape& getEntity() override;

 private:
  virtual CollisionType checkCollisions() override;
  virtual CollisionType checkCollisions(sf::Shape& shape) override;

 public:
  sf::RectangleShape m_paddle;
  sf::Vector2f m_velocity;

  // Inherited via GameEntity
  virtual void update(float dt) override;
};
