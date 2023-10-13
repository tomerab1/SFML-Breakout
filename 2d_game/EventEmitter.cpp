#include "EventEmitter.h"

std::queue<GameEvent> EventEmitter::m_eventQueue;

void EventEmitter::emit(const GameEvent& event) { m_eventQueue.push(event); }

bool EventEmitter::pollEvent(GameEvent& event) {
  bool isPolling = false;

  if (!m_eventQueue.empty()) {
    event = m_eventQueue.front();
    m_eventQueue.pop();
    isPolling = true;
  }

  return isPolling;
}
