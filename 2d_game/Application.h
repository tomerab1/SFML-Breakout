#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>
#include <string>

#include "Scene.h"

class Application {
 public:
  explicit Application(const std::string& title);

  int exec();

 private:
  void render();
  void update(float dt);
  void loadAssets() const;
  void loadScenes();
  void onPause();
  void onKeypress(const sf::Event& event);
  void handleUserInput();
  void handleGameEvent();

  sf::RenderWindow m_window;
  std::stack<std::unique_ptr<Scene>> m_scenes;

  bool m_isPaused = false;
  bool m_isRunning = false;
};
