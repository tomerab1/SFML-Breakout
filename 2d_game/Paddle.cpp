#include "Paddle.h"

#include <iostream>

Paddle::Paddle() {
  m_paddle.setPosition((SCREEN_WIDTH / 2) - PADDLE_WIDTH / 2,
                       SCREEN_HEIGHT - PADDLE_HEIGHT * 2);
  m_paddle.setSize(sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT));
}

void Paddle::render(sf::RenderWindow& window) { window.draw(m_paddle); }

void Paddle::update(float dt, GameEntity& entity) {
  auto [posX, posY] = m_paddle.getPosition();

  resolveCollisionPaddleWall(posX, posY);

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) posX -= m_velocity.x * dt;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    posX += m_velocity.x * dt;

  m_paddle.setPosition(posX, posY);

  CollisionType collisionType = checkCollisions(entity.getEntity());
  resolveCollisionPaddleBall(dynamic_cast<Ball&>(entity), collisionType);
}

void Paddle::resolveCollisionPaddleWall(float& posX, float& posY) {
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
}

void Paddle::resolveCollisionPaddleBall(Ball& ball,
                                        CollisionType collisionType) {
  auto [ballVelX, ballVelY] = ball.getVelocity();
  auto [ballPosX, ballPosY] = ball.getPosition();

  switch (collisionType) {
    case CollisionType::PADDLE_RIGHT:
      ball.setVelocity(ballVelX * -1, ballVelY);
      ball.setPosition(ballPosX + SCREEN_COLLISION_PADDING, ballPosY);
      break;
    case CollisionType::PADDLE_LEFT:
      ball.setVelocity(ballVelX * -1, ballVelY);
      ball.setPosition(ballPosX - SCREEN_COLLISION_PADDING, ballPosY);
      break;
    case CollisionType::PADDLE_UPPER:
      ball.setVelocity(ballVelX, ballVelY * -1);
      ball.setPosition(ballPosX, ballPosY - SCREEN_COLLISION_PADDING);
      break;
    case CollisionType::PADDLE_LOWER:
      ball.setVelocity(ballVelX, ballVelY * -1);
      ball.setPosition(ballPosX, ballPosY + SCREEN_COLLISION_PADDING);
      break;
    default:
      break;
  }
}

void Paddle::setTexture(std::shared_ptr<sf::Texture> texture) {}

CollisionType Paddle::checkCollisions() {
  auto [posX, posY] = m_paddle.getPosition();

  if (posX < SCREEN_COLLISION_PADDING) return CollisionType::LEFT_WALL;
  if (posX + PADDLE_WIDTH > SCREEN_WIDTH - SCREEN_COLLISION_PADDING)
    return CollisionType::RIGHT_WALL;
  return CollisionType::NONE;
}

CollisionType Paddle::checkCollisions(sf::Shape& shape) {
  const sf::CircleShape& circle = ((sf::CircleShape&)shape);

  auto [circleX, circleY] =
      circle.getPosition() + sf::Vector2f(BALL_RADIUS, BALL_RADIUS);
  auto [brickX, brickY] =
      m_paddle.getPosition() + sf::Vector2f(BRICK_WIDTH / 2, BRICK_LENGTH / 2);

  if (circle.getGlobalBounds().intersects(m_paddle.getGlobalBounds())) {
    if (circleY > brickY)
      return CollisionType::PADDLE_LOWER;
    else if (circleY < brickY)
      return CollisionType::PADDLE_UPPER;
    else if (circleX < brickX)
      return CollisionType::PADDLE_LEFT;
    else
      return CollisionType::PADDLE_RIGHT;
  }

  return CollisionType::NONE;
}

void Paddle::update(float dt) {}

sf::Shape& Paddle::getEntity() { return m_paddle; }
