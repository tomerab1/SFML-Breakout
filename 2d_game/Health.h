#pragma once
#include <SFML/Graphics.hpp>
#include <array>

#include "GameEntity.h"
#include "Globals.h"

class Health : public GameEntity {
 public:
  Health();

  virtual void render(sf::RenderWindow& window) override;
  virtual void update(float dt) override;
  virtual void update(float dt, GameEntity& entity) override;
  virtual void setTexture(std::shared_ptr<sf::Texture> texture) override;
  virtual CollisionType checkCollisions() override;
  virtual CollisionType checkCollisions(sf::Shape& shape) override;
  virtual sf::Shape& getEntity() override;

 private:
  std::array<sf::RectangleShape, NUM_OF_LIFES> m_hearts;
};
