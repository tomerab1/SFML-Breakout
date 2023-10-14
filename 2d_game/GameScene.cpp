#include "GameScene.h"

#include <algorithm>
#include <iostream>

#include "FontFactory.h"
#include "EventEmitter.h"
#include "Globals.h"

GameScene::GameScene() {
  m_text.setFont(FontFactory::getFont(FONT_PATH));
  m_text.setCharacterSize(20);
  m_text.setPosition(SCREEN_WIDTH - 200, SCREEN_COLLISION_PADDING);
  m_text.setString("SCORE: " + std::to_string(m_score));

  generateBricks();
}

void GameScene::update(float dt) {
  m_ball.update(dt);

  if (m_ball.checkCollisions() == CollisionType::LOWER_WALL) {
    uint32_t numOfLifes = m_health.onBallHitFloor();
    if (numOfLifes == 0) {
      GameEvent event{GameEventTypes::GAME_OVER};
      EventEmitter::emit(event);
    }
  }

  auto it = m_bricks.begin();
  while (it != m_bricks.end()) {
    if (it->getHealth() <= 0) {
      it = m_bricks.erase(it);
      m_score++;
      m_text.setString("SCORE: " + std::to_string(m_score));
    } else {
      it->update(dt, m_ball);
      ++it;
    }
  }

  m_health.update(dt);
  m_paddle.update(dt, m_ball);
}
void GameScene::render(sf::RenderWindow& window) {
  m_ball.render(window);
  m_paddle.render(window);
  m_health.render(window);
  window.draw(m_text);

  for (auto&& brick : m_bricks) {
    brick.render(window);
  }
}

void GameScene::generateBricks() {
  for (int i = 0; i < BRICKS_IN_ROW; i++) {
    for (int j = 0; j < BRICKS_COLS; j++) {
      float posX = (SCREEN_COLLISION_PADDING / 2.f + BRICK_WIDTH) * i;
      float posY = 100 + (SCREEN_COLLISION_PADDING / 2.f + BRICK_LENGTH) * j;

      m_bricks.emplace_back("blueBrick", sf::Vector2f(posX, posY), 100);
    }
  }
}
