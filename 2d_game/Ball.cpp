#include "Ball.h"

Ball::Ball() {
  m_ball.setFillColor(sf::Color::White);
  m_ball.setPosition(SCREEN_WIDTH / 2 + 200, SCREEN_HEIGHT / 2 + 200);
  m_ball.setRadius(BALL_RADIUS);
}

void Ball::render(sf::RenderWindow& window) { window.draw(m_ball); }

void Ball::update(float dt) {
  auto [posX, posY] = m_ball.getPosition();

  switch (checkCollisions()) {
    case CollisionType::UPPER_WALL:
      posY += SCREEN_COLLISION_PADDING;
      m_velocity.y *= -1;
      break;
    case CollisionType::LOWER_WALL:
      posY -= SCREEN_COLLISION_PADDING;
      m_velocity.y *= -1;
      break;
    case CollisionType::RIGHT_WALL:
      posX -= SCREEN_COLLISION_PADDING;
      m_velocity.x *= -1;
      break;
    case CollisionType::LEFT_WALL:
      posX += SCREEN_COLLISION_PADDING;
      m_velocity.x *= -1;
      break;
    default:
      break;
  }

  posX += m_velocity.x * dt;
  posY += m_velocity.y * dt;

  m_ball.setPosition(posX, posY);
}

void Ball::setVelocity(float x, float y) {
  m_velocity.x = x;
  m_velocity.y = y;
}

void Ball::setPosition(float x, float y) {
  m_ball.setPosition(sf::Vector2f(x, y));
}

sf::Vector2f Ball::getVelocity() const { return m_velocity; }

sf::Vector2f Ball::getPosition() const { return m_ball.getPosition(); }

uint32_t Ball::getDamage() const { return m_damage; }

CollisionType Ball::checkCollisions() {
  auto [posX, posY] = m_ball.getPosition();

  // Check collision against walls.
  if (posY - BALL_RADIUS < SCREEN_COLLISION_PADDING)
    return CollisionType::UPPER_WALL;
  if (posY + BALL_RADIUS > SCREEN_HEIGHT - SCREEN_COLLISION_PADDING)
    return CollisionType::LOWER_WALL;
  if (posX - BALL_RADIUS < SCREEN_COLLISION_PADDING)
    return CollisionType::LEFT_WALL;
  if (posX + BALL_RADIUS > SCREEN_WIDTH - SCREEN_COLLISION_PADDING)
    return CollisionType::RIGHT_WALL;
  return CollisionType::NONE;
}

void Ball::update(float dt, GameEntity& entity) {}

CollisionType Ball::checkCollisions(sf::Shape& shape) {
  return CollisionType::NONE;
}

sf::Shape& Ball::getEntity() { return m_ball; }

void Ball::setTexture(std::shared_ptr<sf::Texture>) {}
