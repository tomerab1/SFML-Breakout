#include "GameOverScene.h"

#include "Globals.h"
#include "ResourceLocator.h"

GameOverScene::GameOverScene(uint32_t score) {
	m_text.setFont(ResourceLocator<FontFactory>::getFont(FONT_PATH));
	m_text.setCharacterSize(50);
	m_text.setString(R"(
		 GAME OVER
       YOUR SCORE IS: )" + std::to_string(score));

	m_text.setPosition({ SCREEN_WIDTH / 2 - 750, SCREEN_HEIGHT / 2 - 125 });

	m_firework01.reset({ SCREEN_WIDTH / 4, SCREEN_HEIGHT - 100 });
	m_firework02.reset({ SCREEN_WIDTH - SCREEN_WIDTH / 4, SCREEN_HEIGHT });
}

void GameOverScene::update(float dt) {
	m_firework01.update(dt);
	m_firework02.update(dt);
}

void GameOverScene::render(sf::RenderWindow& window) {
	window.draw(m_text);
	m_firework01.render(window);
	m_firework02.render(window);
}
