#include "PauseScene.h"

#include "FontFactory.h"
#include "Globals.h"

PauseScene::PauseScene() {
  m_text.setFont(FontFactory::getFont(FONT_PATH));
  m_text.setCharacterSize(50);
  m_text.setString(R"(
			GAME PAUSED
       PRESS 'SPACE' TO RESUME
	)");
  m_text.setPosition(
      sf::Vector2f(SCREEN_WIDTH / 2 - 900, SCREEN_HEIGHT / 2 - 225));
}

void PauseScene::update(float dt) {}

void PauseScene::render(sf::RenderWindow& window) { window.draw(m_text); }
