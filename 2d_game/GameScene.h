#pragma once
#include <memory>
#include <vector>

#include "Ball.h"
#include "Brick.h"
#include "GameEntity.h"
#include "Health.h"
#include "Paddle.h"
#include "Scene.h"

class GameScene : public Scene {
 public:
  GameScene();

  void update(float dt) override;
  void render(sf::RenderWindow& window) override;

 private:
  void generateBricks();

  Ball m_ball;
  Paddle m_paddle;
  Health m_health;

  uint32_t m_score;

  sf::Text m_text;
  std::unique_ptr<sf::Font> m_font;
  std::vector<Brick> m_bricks;
};
