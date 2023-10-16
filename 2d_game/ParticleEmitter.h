#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class ParticleEmitter {
public:
	explicit ParticleEmitter(std::size_t numOfParticles, const sf::Color& color);

	void render(sf::RenderWindow& window);
	void update(float dt);
	void reset();
	void setEmitterPos(const sf::Vector2f& pos);

private:
	struct Particle {
		sf::Vector2f velocity;
		float lifetime;
	};

	float m_lifetime{ 2.f };
	std::size_t m_numOfParticles;
	sf::Vector2f m_emitterPos;
	sf::Color m_color;

	std::vector<Particle> m_particles;
	std::vector<sf::RectangleShape> m_rects;
};