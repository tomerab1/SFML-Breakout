#pragma once

#include <queue>

#include "GameEvent.h"

class EventEmitter {
 public:
  EventEmitter() = delete;
  ~EventEmitter() = delete;

  static void emit(const GameEvent& event);
  static bool pollEvent(GameEvent& event);

 private:
  static std::queue<GameEvent> m_eventQueue;
};
