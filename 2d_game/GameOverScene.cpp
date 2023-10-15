#include "GameOverScene.h"

#include "Globals.h"
#include "ResourceLocator.h"

GameOverScene::GameOverScene(uint32_t score) {
  m_text.setFont(ResourceLocator<FontFactory>::getFont(FONT_PATH));
  m_text.setCharacterSize(50);
  m_text.setString(R"(
		 GAME OVER
       YOUR SCORE IS: )" + std::to_string(score));

  m_text.setPosition(
      sf::Vector2f(SCREEN_WIDTH / 2 - 750, SCREEN_HEIGHT / 2 - 125));
}

void GameOverScene::update(float dt) {}

void GameOverScene::render(sf::RenderWindow& window) { window.draw(m_text); }
