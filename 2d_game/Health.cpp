#include "Health.h"

#include "TextureFactory.h"

Health::Health() {
  int i = SCREEN_COLLISION_PADDING;

  for (auto& heart : m_hearts) {
    heart.setPosition(SCREEN_COLLISION_PADDING * i / 2,
                      SCREEN_COLLISION_PADDING);
    heart.setTexture(TextureFactory::getTexture("heart").get());
    heart.setSize(sf::Vector2f(35, 35));

    i += SCREEN_COLLISION_PADDING;
  }
}

void Health::render(sf::RenderWindow& window) {
  for (auto& heart : m_hearts) window.draw(heart);
}

void Health::update(float dt) {
  static float scaleFactor = 1.0f;
  float scaleSpeed = 0.001f;

  for (auto& heart : m_hearts) {
    heart.setScale(std::sin(scaleFactor), 1.f);
    scaleFactor += scaleSpeed * dt;
  }
}

void Health::update(float dt, GameEntity& entity) {}

void Health::setTexture(std::shared_ptr<sf::Texture> texture) {
  for (auto& heart : m_hearts) heart.setTexture(texture.get());
}

CollisionType Health::checkCollisions() { return CollisionType::NONE; }

CollisionType Health::checkCollisions(sf::Shape& shape) {
  return CollisionType::NONE;
}

sf::Shape& Health::getEntity() { return m_hearts[0]; }
