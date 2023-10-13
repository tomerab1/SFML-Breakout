#pragma once
#include <SFML/Graphics.hpp>
#include <array>

#include "GameEntity.h"
#include "Globals.h"

class Health : public GameEntity {
 public:
  Health();

  void render(sf::RenderWindow& window) override;
  void update(float dt) override;
  void update(float dt, GameEntity& entity) override;
  void setTexture(std::shared_ptr<sf::Texture> texture) override;
  uint32_t onBallHitFloor();
  uint32_t getNumOfLifes() const;

 private:
  CollisionType checkCollisions() override;
  CollisionType checkCollisions(sf::Shape& shape) override;
  sf::Shape& getEntity() override;

  std::array<sf::RectangleShape, NUM_OF_LIFES> m_hearts;
  uint32_t m_numOfLifes = NUM_OF_LIFES;
};
