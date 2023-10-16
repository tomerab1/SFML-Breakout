#include "AudioFactory.h"
#include "Exceptions.h"

std::unordered_map<std::string, std::unique_ptr<sf::SoundBuffer>> AudioFactory::m_bufferMap;
std::unordered_map<std::string, std::unique_ptr<sf::Sound>> AudioFactory::m_audioMap;

void AudioFactory::loadAudio(const std::string& path, const std::string& name) {
	if (m_bufferMap.find(path) == m_bufferMap.end()) {
		m_bufferMap[path] = std::make_unique<sf::SoundBuffer>();
	}


	if (!m_bufferMap[path]->loadFromFile(path)) {
		throw LoadSoundException("Failed to load: " + path);
	}

	m_audioMap[name] = std::make_unique<sf::Sound>(*m_bufferMap[path]);
}

void AudioFactory::play(const std::string& name, sf::Time offset) {
	if (m_audioMap.find(name) == m_audioMap.end()) {
		throw LoadSoundException("Failed to load: " + name);
	}

	m_audioMap[name]->play();
	m_audioMap[name]->setPlayingOffset(offset);
}

void AudioFactory::stop(const std::string& name) {
	if (m_audioMap.find(name) == m_audioMap.end()) {
		throw LoadSoundException("Failed to load: " + name);
	}

	m_audioMap[name]->stop();
}