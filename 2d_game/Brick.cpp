#include "Brick.h"

#include <iostream>

#include "Ball.h"
#include "Globals.h"
#include "TextureFactory.h"

Brick::Brick(std::string&& brickType, sf::Vector2f pos, uint32_t health)
    : m_health{health} {
  m_texture = TextureFactory::getTexture(std::move(brickType));
  m_brick.setTexture(m_texture.get());
  m_brick.setPosition(pos);
  m_brick.setSize(sf::Vector2f(BRICK_WIDTH, BRICK_LENGTH));
}

void Brick::render(sf::RenderWindow& window) { window.draw(m_brick); }

void Brick::update(float dt) {}

void Brick::update(float dt, GameEntity& entity) {
  CollisionType collisionType = checkCollisions(entity.getEntity());
  Ball& ball = (Ball&)entity;
  auto [ballVelX, ballVelY] = ball.getVelocity();
  auto [ballPosX, ballPosY] = ball.getPosition();

  switch (collisionType) {
    case CollisionType::BRICK_RIGHT:
      ball.setVelocity(ballVelX * -1, ballVelY);
      ball.setPosition(ballPosX + SCREEN_COLLISION_PADDING, ballPosY);
      m_health -= ball.getDamage();
      break;
    case CollisionType::BRICK_LEFT:
      ball.setVelocity(ballVelX * -1, ballVelY);
      ball.setPosition(ballPosX - SCREEN_COLLISION_PADDING, ballPosY);
      m_health -= ball.getDamage();
      break;
    case CollisionType::BRICK_UPPER:
      ball.setVelocity(ballVelX, ballVelY * -1);
      ball.setPosition(ballPosX, ballPosY - SCREEN_COLLISION_PADDING);
      m_health -= ball.getDamage();
      break;
    case CollisionType::BRICK_LOWER:
      ball.setVelocity(ballVelX, ballVelY * -1);
      ball.setPosition(ballPosX, ballPosY + SCREEN_COLLISION_PADDING);
      m_health -= ball.getDamage();
      break;
    default:
      break;
  }

  if (collisionType != CollisionType::NONE) {
    m_texture = TextureFactory::getTexture("blueBrickBreaking");
    m_brick.setTexture(m_texture.get());
  }
}

CollisionType Brick::checkCollisions() { return CollisionType::NONE; }

CollisionType Brick::checkCollisions(sf::Shape& shape) {
  sf::CircleShape& circle = ((sf::CircleShape&)shape);
  auto [circleX, circleY] =
      circle.getPosition() + sf::Vector2f(BALL_RADIUS, BALL_RADIUS);
  auto [brickX, brickY] =
      m_brick.getPosition() + sf::Vector2f(BRICK_WIDTH / 2, BRICK_LENGTH / 2);

  if (circle.getGlobalBounds().intersects(m_brick.getGlobalBounds())) {
    if (circleY > brickY)
      return CollisionType::BRICK_LOWER;
    else if (circleY < brickY)
      return CollisionType::BRICK_UPPER;
    else if (circleX < brickX)
      return CollisionType::BRICK_LEFT;
    else
      return CollisionType::BRICK_RIGHT;
  }

  return CollisionType::NONE;
}

sf::Shape& Brick::getEntity() { return m_brick; }

uint32_t Brick::getHealth() { return m_health; }

void Brick::setTexture(std::shared_ptr<sf::Texture> texture) {
  m_texture = texture;
}
