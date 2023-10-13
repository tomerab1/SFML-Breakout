#include "Paddle.h"

#include <iostream>

#include "Ball.h"

Paddle::Paddle() : m_velocity{PADDLE_VELOCITY, PADDLE_VELOCITY} {
  m_paddle.setPosition((SCREEN_WIDTH / 2) - PADDLE_WIDTH / 2,
                       SCREEN_HEIGHT - PADDLE_HEIGHT * 2);
  m_paddle.setSize(sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT));
}

void Paddle::render(sf::RenderWindow& window) { window.draw(m_paddle); }

void Paddle::update(float dt, GameEntity& ball) {
  auto [posX, posY] = m_paddle.getPosition();

  switch (checkCollisions()) {
    case CollisionType::LEFT_WALL:
      posX += SCREEN_COLLISION_PADDING;
      break;
    case CollisionType::RIGHT_WALL:
      posX -= SCREEN_COLLISION_PADDING;
      break;
    default:
      break;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) posX -= m_velocity.x * dt;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    posX += m_velocity.x * dt;

  m_paddle.setPosition(posX, posY);

  switch (checkCollisions(ball.getEntity())) {
    case CollisionType::PADDLE: {
      auto [ballVelX, ballVelY] = ((Ball&)ball).getVelocity();
      auto [ballPosX, ballPosY] = ((Ball&)ball).getPosition();

      ((Ball&)ball).setVelocity(ballVelX, ballVelY * -1);
    } break;
    default:
      break;
  }
}

void Paddle::setTexture(std::shared_ptr<sf::Texture> texture)
{
}

CollisionType Paddle::checkCollisions() {
  auto [posX, posY] = m_paddle.getPosition();

  if (posX  < SCREEN_COLLISION_PADDING)
    return CollisionType::LEFT_WALL;
  if (posX + (PADDLE_WIDTH) > SCREEN_WIDTH - SCREEN_COLLISION_PADDING)
    return CollisionType::RIGHT_WALL;
  return CollisionType::NONE;
}

CollisionType Paddle::checkCollisions(sf::Shape& shape) {
  return shape.getGlobalBounds().intersects(m_paddle.getGlobalBounds())
             ? CollisionType::PADDLE
             : CollisionType::NONE;
}

void Paddle::update(float dt) {}

sf::Shape& Paddle::getEntity() { return m_paddle; }
