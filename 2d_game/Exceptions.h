#pragma once

#include <exception>

class LoadFontException : public std::exception {
	explicit LoadFontException(const std::string& msg) : m_msg{ msg } {}
	const char* what() const override { return m_msg.c_str(); }

private:
	std::string m_msg;
};

class LoadTextureException : public std::exception {
public:
	explicit LoadTextureException(const std::string& msg) : m_msg{ msg } {}
	const char* what() const override { return m_msg.c_str(); }

private:
	std::string m_msg;
};

class LoadSoundException : public std::exception {
public:
	explicit LoadSoundException(const std::string& msg) : m_msg{ msg } {}
	const char* what() const override { return m_msg.c_str(); }

private:
	std::string m_msg;
};