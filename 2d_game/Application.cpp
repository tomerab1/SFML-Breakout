#include "Application.h"

#include <iostream>

#include "EventEmitter.h"
#include "Exceptions.h"
#include "GameOverScene.h"
#include "GameScene.h"
#include "Globals.h"
#include "PauseScene.h"
#include "ResourceLocator.h"
#include "StartGameScene.h"
#include "Utils.h"

Application::Application(const std::string& title)
	: m_window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), title) {
	loadAssets();
	loadScenes();
}

int Application::exec() {
	try {
		sf::Clock clock;

		while (m_window.isOpen()) {
			sf::Time dt = clock.restart();

			m_window.setFramerateLimit(60);
			m_window.setVerticalSyncEnabled(true);

			handleUserInput();
			handleGameEvent();

			if (!m_isPaused) {
				update(static_cast<float>(dt.asSeconds()));
			}
			render();
		}
		return EXIT_SUCCESS;
	}
	catch (std::exception& ex) {
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
		case GameEventTypes::GAME_OVER: {
			uint32_t score = dynamic_cast<GameScene&>(*m_scenes.top()).getScore();
			m_scenes.emplace(std::make_unique<GameOverScene>(score));
			m_isGameOver = true;
		} break;
		case GameEventTypes::GAME_START:
			m_scenes.emplace(std::make_unique<GameScene>());
			m_isRunning = true;
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
	m_window.clear(sf::Color::Black);

	m_scenes.top()->render(m_window);

	m_window.display();
}

void Application::update(float dt) { m_scenes.top()->update(dt); }

void Application::loadAssets() const {
	try {
		ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\01-Breakout-Tiles.png)", "blueBrick");
		ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\02-Breakout-Tiles.png)", "blueBrickBreaking");
		ResourceLocator<TextureFactory>::loadTexture(R"(.\Res\60-Breakout-Tiles.png)", "heart");
		ResourceLocator<AudioFactory>::loadAudio(R"(.\Res\fireworks-whistle.mp3)", "fireworkWhistle");
		ResourceLocator<AudioFactory>::loadAudio(R"(.\Res\firework_explosion.wav)", "fireworkExplosion");
	}
	catch (LoadTextureException& ex) {
		std::cout << ex.what() << '\n';
	}
	catch (...) {
		std::cout << "Unknown exception" << '\n';
	}
}

void Application::loadScenes() {
	m_scenes.emplace(std::make_unique<StartGameScene>());
}

void Application::onPause() { m_isPaused = !m_isPaused; }

void Application::onKeypress(const sf::Event& event) {
	if (!m_isRunning) return;
	if (m_isGameOver) return;

	if (event.key.scancode == sf::Keyboard::Scan::Space && !m_isPaused) {
		m_scenes.emplace(std::make_unique<PauseScene>());
		onPause();
	}
	else if (event.key.scancode == sf::Keyboard::Scan::Space && m_isPaused) {
		m_scenes.pop();
		onPause();
	}
}
