#pragma once

#include <SFML/Audio.hpp>
#include <unordered_map>
#include <memory>

class AudioFactory
{
public:
	static void loadAudio(const std::string& path, const std::string& name);
	static void play(const std::string& name, sf::Time offset);
	static void stop(const std::string& name);

	AudioFactory() = delete;
	~AudioFactory() = delete;

private:
	static std::unordered_map<std::string, std::unique_ptr<sf::Sound>> m_audioMap;
	static std::unordered_map<std::string, std::unique_ptr<sf::SoundBuffer>> m_bufferMap;
};

