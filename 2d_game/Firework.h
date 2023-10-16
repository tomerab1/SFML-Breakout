#pragma once

#include "ParticleEmitter.h"
#include "ResourceLocator.h"


class Firework {
public:
	explicit Firework(const sf::Color& color);

	void render(sf::RenderWindow& window);
	void update(float dt);
	void reset(const sf::Vector2f& pos);

private:
	ParticleEmitter m_particles;

	bool m_isFirst{ true };
	float m_fireworkTimer{ 3.f };

	sf::Vector2f m_emitterPos;
	sf::Vector2f m_fireworkVel{ 0, 300.f };
	sf::RectangleShape m_firework;
};