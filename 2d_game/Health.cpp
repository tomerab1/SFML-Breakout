#include "Health.h"

#include <iostream>

#include "TextureFactory.h"

Health::Health() {
  uint32_t i = SCREEN_COLLISION_PADDING;

  for (auto& heart : m_hearts) {
    heart.setPosition(SCREEN_COLLISION_PADDING * i / 2.f,
                      SCREEN_COLLISION_PADDING);
    heart.setTexture(TextureFactory::getTexture("heart").get());
    heart.setSize(sf::Vector2f(35, 35));

    i += SCREEN_COLLISION_PADDING;
  }
}

void Health::render(sf::RenderWindow& window) {
  for (uint32_t i = 0; i < m_numOfLifes; i++) window.draw(m_hearts[i]);
}

void Health::update(float dt) {
  static float scaleFactor = 1.0f;
  float scaleSpeed = 0.75f;

  for (uint32_t i = 0; i < m_numOfLifes; i++) {
    m_hearts[i].setScale(std::sin(scaleFactor), 1.f);
    scaleFactor += scaleSpeed * dt;
  }
}

void Health::update(float dt, GameEntity& entity) {}

void Health::setTexture(std::shared_ptr<sf::Texture> texture) {
  for (auto& heart : m_hearts) heart.setTexture(texture.get());
}

uint32_t Health::onBallHitFloor() {
  m_numOfLifes = std::max(m_numOfLifes - 1, 0u);
  return m_numOfLifes;
}

uint32_t Health::getNumOfLifes() const { return m_numOfLifes; }

CollisionType Health::checkCollisions() { return CollisionType::NONE; }

CollisionType Health::checkCollisions(sf::Shape& shape) {
  return CollisionType::NONE;
}

sf::Shape& Health::getEntity() { return m_hearts[0]; }
