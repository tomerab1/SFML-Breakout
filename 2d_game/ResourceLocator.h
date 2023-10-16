#pragma once

#include <memory>

#include "FontFactory.h"
#include "TextureFactory.h"
#include "AudioFactory.h"

template <typename R>
struct ResourceLocator;

template <>
class ResourceLocator<TextureFactory> {
public:
	static TextureFactory::ret_type getTexture(const std::string& textureName) {
		return TextureFactory::getTexture(textureName);
	}

	static void loadTexture(const std::string& texturePath,
		const std::string& textureName) {
		TextureFactory::loadTexture(texturePath, textureName);
	}
};

template <>
class ResourceLocator<FontFactory> {
public:
	static const sf::Font& getFont(const std::string& fontPath) {
		return FontFactory::getFont(fontPath);
	}
};

template<>
class ResourceLocator<AudioFactory> {
public:
	static void loadAudio(const std::string& path, const std::string& name) {
		AudioFactory::loadAudio(path, name);
	}

	static void play(const std::string& name, sf::Time offset) {
		AudioFactory::play(name, offset);
	}

	static void stop(const std::string& name) {
		AudioFactory::stop(name);
	}
};