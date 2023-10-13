#include "Application.h"

#include <iostream>

#include "EventEmitter.h"
#include "GameScene.h"
#include "Globals.h"
#include "PauseScene.h"
#include "TextureFactory.h"
#include "Utils.h"

Application::Application(const std::string& title)
    : m_window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), title) {
  loadAssets();
  loadScenes();
}

int Application::exec() {
  try {
    sf::Clock clock;

    while (m_window.isOpen() && m_isRunning) {
      sf::Time dt = clock.restart();

      m_window.setFramerateLimit(60);
      m_window.setVerticalSyncEnabled(true);

      handleUserInput();
      handleGameEvent();

      if (!m_isPaused) {
        update(static_cast<float>(dt.asMilliseconds()));
      }
      render();
    }
    return EXIT_SUCCESS;
  } catch (std::exception& ex) {
    std::cout << ex.what() << '\n';
    return EXIT_FAILURE;
  }
}

void Application::handleUserInput() {
  sf::Event event;
  while (m_window.pollEvent(event)) {
    switch (event.type) {
      case sf::Event::Closed:
        m_window.close();
        break;
      case sf::Event::KeyPressed:
        onKeypress(event);
        break;
      default:
        break;
    }
  }
}

void Application::handleGameEvent() {
  GameEvent gameEvent;
  while (EventEmitter::pollEvent(gameEvent)) {
    switch (gameEvent.eventType) {
      case GameEventTypes::GAME_OVER:
        m_isRunning = false;
        break;
      case GameEventTypes::GAME_NONE:
      case GameEventTypes::GAME_PAUSED:
        break;
      default:
        break;
    }
  }
}

void Application::render() {
  m_window.clear(Utils::hexStringToColor("0x555555"));

  m_scenes.top()->render(m_window);

  m_window.display();
}

void Application::update(float dt) { m_scenes.top()->update(dt); }

void Application::loadAssets() const {
  TextureFactory::loadTexture(
      R"(C:\Users\tomer\OneDrive\Desktop\Breakout_Tile_Set_Free\Breakout Tile Set Free\PNG\01-Breakout-Tiles.png)",
      "blueBrick");
  TextureFactory::loadTexture(
      R"(C:\Users\tomer\OneDrive\Desktop\Breakout_Tile_Set_Free\Breakout Tile Set Free\PNG\02-Breakout-Tiles.png)",
      "blueBrickBreaking");
  TextureFactory::loadTexture(
      R"(C:\Users\tomer\OneDrive\Desktop\Breakout_Tile_Set_Free\Breakout Tile Set Free\PNG\60-Breakout-Tiles.png)",
      "heart");
}

void Application::loadScenes() {
  m_scenes.emplace(std::make_unique<GameScene>());
}

void Application::onPause() { m_isPaused = !m_isPaused; }

void Application::onKeypress(const sf::Event& event) {
  if (event.key.scancode == sf::Keyboard::Scan::Space && !m_isPaused) {
    m_scenes.emplace(std::make_unique<PauseScene>());
    onPause();
  } else if (event.key.scancode == sf::Keyboard::Scan::Space && m_isPaused) {
    m_scenes.pop();
    onPause();
  }
}
