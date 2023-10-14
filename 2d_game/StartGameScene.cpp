#include "StartGameScene.h"

#include "EventEmitter.h"
#include "Globals.h"

StartGameScene::StartGameScene() {
  if (!m_font->loadFromFile(
          R"(C:\Users\tomer\OneDrive\Desktop\public-pixel-font\PublicPixel-z84yD.ttf)")) {
    throw std::runtime_error("Could not load font");
  }

  m_text.setFont(*m_font.get());
  m_text.setCharacterSize(50);
  m_text.setString(R"(
        PRESS 'SPACE' TO
         START THE GAME
    )");

  m_text.setPosition(
      sf::Vector2f(SCREEN_WIDTH / 2 - 900, SCREEN_HEIGHT / 2 - 225));
}

void StartGameScene::update(float dt) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    EventEmitter::emit(GameEvent{GameEventTypes::GAME_START});
  }
}

void StartGameScene::render(sf::RenderWindow& window) { window.draw(m_text); }
