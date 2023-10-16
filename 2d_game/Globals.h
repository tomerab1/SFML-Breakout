#pragma once

#include <cstdint>

constexpr const char* FONT_PATH = R"(.\Res\PublicPixel-z84yD.ttf)";

constexpr uint32_t SCREEN_WIDTH = 1920;
constexpr uint32_t SCREEN_HEIGHT = 1080;
constexpr uint32_t SCREEN_COLLISION_PADDING = 10;

constexpr float BALL_VELOCITY = 700.f;
constexpr uint32_t BALL_RADIUS = 10;

constexpr float PADDLE_VELOCITY = 750.f;
constexpr uint32_t PADDLE_HEIGHT = 20;
constexpr uint32_t PADDLE_WIDTH = 200;

constexpr uint32_t BRICK_LENGTH = 50;
constexpr uint32_t BRICK_WIDTH = 100;

constexpr uint32_t BRICKS_IN_ROW = 19;
constexpr uint32_t BRICKS_COLS = 8;

constexpr uint32_t NUM_OF_LIFES = 3;

enum class CollisionType {
  UPPER_WALL,
  LOWER_WALL,
  RIGHT_WALL,
  LEFT_WALL,
  PADDLE_LEFT,
  PADDLE_RIGHT,
  PADDLE_UPPER,
  PADDLE_LOWER,
  BRICK_LEFT,
  BRICK_RIGHT,
  BRICK_UPPER,
  BRICK_LOWER,
  NONE
};