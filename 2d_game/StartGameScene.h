#pragma once
#include "Scene.h"

#include <memory>
#include <SFML/Graphics.hpp>

class StartGameScene : public Scene {
public:
	StartGameScene();

	void update(float dt) override;
	void render(sf::RenderWindow& window) override;

private:
	std::unique_ptr<sf::Font> m_font{std::make_unique<sf::Font>()};
	sf::Text m_text;
};