#include "ParticleEmitter.h"


ParticleEmitter::ParticleEmitter(std::size_t numOfParticles, const sf::Color& color)
	: m_numOfParticles{ numOfParticles }, m_color{ color }, m_particles(numOfParticles), m_rects(numOfParticles) {}

void ParticleEmitter::render(sf::RenderWindow& window) {
	for (const auto& rect : m_rects) {
		window.draw(rect);
	}
}

void ParticleEmitter::update(float dt) {
	for (std::size_t i = 0; i < m_numOfParticles; i++) {
		m_particles[i].lifetime = std::max(0.f, m_particles[i].lifetime - dt);

		m_rects[i].setPosition(m_rects[i].getPosition() - m_particles[i].velocity * dt);

		float ratio = m_particles[i].lifetime / m_lifetime;
		sf::Color newColor = m_rects[i].getFillColor();
		newColor.a = ratio * 255;
		m_rects[i].setFillColor(newColor);
	}
}

void ParticleEmitter::reset() {
	for (std::size_t i = 0; i < m_numOfParticles; i++) {
		float angle = (std::rand() % 360) * 3.14f / 180.f;
		float speed = (std::rand() % 100) + 0.5f;

		m_particles[i].velocity = { std::cos(angle) * speed, std::sin(angle) * speed };
		m_particles[i].lifetime = (std::rand() % 2000) / 1000.f;

		m_rects[i].setPosition(m_emitterPos);
		m_rects[i].setSize({ 5.f, 5.f });
		m_rects[i].setFillColor(m_color);
	}
}

void ParticleEmitter::setEmitterPos(const sf::Vector2f& pos) { m_emitterPos = pos; }