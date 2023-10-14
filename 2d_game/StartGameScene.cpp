#include "StartGameScene.h"

#include "FontFactory.h"
#include "EventEmitter.h"
#include "Globals.h"

StartGameScene::StartGameScene() {
  m_text.setFont(FontFactory::getFont(FONT_PATH));
  m_text.setCharacterSize(50);
  m_text.setString(R"(
        PRESS 'SPACE' TO
         START THE GAME
    )");

  m_text.setPosition(
      sf::Vector2f(SCREEN_WIDTH / 2 - 800, SCREEN_HEIGHT / 2 - 125));
}

void StartGameScene::update(float dt) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    EventEmitter::emit(GameEvent{GameEventTypes::GAME_START});
  }
}

void StartGameScene::render(sf::RenderWindow& window) { window.draw(m_text); }
