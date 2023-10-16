#include "Firework.h"

Firework::Firework(const sf::Color& color) : m_particles{ 1000, color } {
	m_firework.setFillColor(sf::Color::White);
	m_firework.setSize({ 5.f, 15.f });
}

void Firework::render(sf::RenderWindow& window) {
	if (m_fireworkTimer > 0) window.draw(m_firework);
	else m_particles.render(window);
}

void Firework::update(float dt) {
	m_fireworkTimer = std::max(0.f, m_fireworkTimer - dt);
	m_emitterPos -= m_fireworkVel * dt;

	if (m_fireworkTimer <= 0) {
		ResourceLocator<AudioFactory>::stop("fireworkWhistle");
		m_particles.setEmitterPos(m_emitterPos);


		if (m_isFirst) {
			ResourceLocator<AudioFactory>::play("fireworkExplosion", sf::seconds(1.f));
			m_particles.reset();
			m_isFirst = false;
		}

		m_particles.update(dt);
	}

	m_firework.setPosition(m_emitterPos);
}

void Firework::reset(const sf::Vector2f& pos) {
	m_fireworkTimer = 2.f;
	m_emitterPos = pos;
	m_firework.setPosition(pos);
	m_particles.reset();
	m_isFirst = true;

	ResourceLocator<AudioFactory>::play("fireworkWhistle", sf::seconds(3.5f));
}