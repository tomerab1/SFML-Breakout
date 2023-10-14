#include "PauseScene.h"

#include "Globals.h"

PauseScene::PauseScene() {
  if (!m_font->loadFromFile(
          R"(C:\Users\tomer\OneDrive\Desktop\public-pixel-font\PublicPixel-z84yD.ttf)")) {
    throw std::runtime_error("Could not load font");
  }

  m_text.setFont(*m_font.get());
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
