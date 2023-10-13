#pragma once

#include <SFML/Graphics.hpp>

#include "GameEntity.h"
#include "Globals.h"

class Ball : public GameEntity {
 public:
  Ball();

  void render(sf::RenderWindow& window) override;
  void update(float dt) override;
  CollisionType checkCollisions(sf::Shape& shape) override;
  sf::Shape& getEntity() override;
  void setTexture(std::shared_ptr<sf::Texture>) override;
  void setVelocity(float x, float y);
  void setPosition(float x, float y);
  sf::Vector2f getVelocity() const;
  sf::Vector2f getPosition() const;
  uint32_t getDamage() const;
  CollisionType checkCollisions() override;
  void update(float dt, GameEntity& entity) override;

 private:
  sf::CircleShape m_ball;
  sf::Vector2f m_velocity;
  uint32_t m_damage;
};
