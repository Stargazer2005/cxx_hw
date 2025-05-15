#pragma once

template <typename T>
class Counter {
 public:
  static size_t Count() noexcept { return m_count; }

 protected:
  Counter() noexcept { ++m_count; }

  Counter(const Counter&) noexcept { ++m_count; }
  Counter& operator=(const Counter&) noexcept = default;

  Counter(Counter&&) noexcept = default;
  Counter& operator=(Counter&&) noexcept = default;

  ~Counter() { --m_count; }

 private:
  static inline size_t m_count = 0;
};