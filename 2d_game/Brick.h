#pragma once
#include <SFML/Graphics.hpp>

#include "GameEntity.h"

class Brick : public GameEntity {
 public:
  Brick() = default;
  Brick(std::string&& brickType, sf::Vector2f pos, uint32_t health);

  virtual void render(sf::RenderWindow& window) override;
  virtual void update(float dt) override;
  virtual void update(float dt, GameEntity& entity) override;
  virtual CollisionType checkCollisions() override;
  virtual CollisionType checkCollisions(sf::Shape& shape) override;
  virtual void setTexture(std::shared_ptr<sf::Texture> texture) override;
  virtual sf::Shape& getEntity() override;

  uint32_t getHealth();

 private:
  sf::RectangleShape m_brick;
  uint32_t m_health;
  std::shared_ptr<sf::Texture> m_texture;

  // Inherited via GameEntity
};
