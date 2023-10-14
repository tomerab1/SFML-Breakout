#pragma once

#include <SFML/Graphics.hpp>

#include "Ball.h"
#include "GameEntity.h"
#include "Globals.h"

class Paddle : public GameEntity {
 public:
  Paddle();
  void render(sf::RenderWindow& window) override;
  void update(float dt, GameEntity& ball) override;
  void update(float dt) override;
  void setTexture(std::shared_ptr<sf::Texture> texture) override;
  sf::Shape& getEntity() override;

 private:
  CollisionType checkCollisions() override;
  CollisionType checkCollisions(sf::Shape& shape) override;
  void resolveCollisionPaddleWall(float& posX, float& posY);
  void resolveCollisionPaddleBall(Ball& ball, CollisionType collisionType);

 public:
  sf::RectangleShape m_paddle;
  sf::Vector2f m_velocity{PADDLE_VELOCITY, PADDLE_VELOCITY};
};
