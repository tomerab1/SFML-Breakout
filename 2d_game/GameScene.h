#pragma once
#include <memory>
#include <vector>

#include "Ball.h"
#include "Brick.h"
#include "GameEntity.h"
#include "Health.h"
#include "Paddle.h"
#include "Scene.h"

class GameScene : public Scene {
public:
	GameScene();

	void update(float dt) override;
	void render(sf::RenderWindow& window) override;
	uint32_t getScore() const;

private:
	void generateBricks();

	Ball m_ball;
	Paddle m_paddle;
	Health m_health;

	uint32_t m_score{ 0u };

	sf::Text m_text;
	std::unique_ptr<sf::Font> m_font{ std::make_unique<sf::Font>() };
	std::vector<Brick> m_bricks;
};
