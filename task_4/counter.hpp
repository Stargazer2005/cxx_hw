#pragma once

template <typename T>
class counter {
 public:
  static size_t count() noexcept { return m_count; }

 protected:
  counter() noexcept { ++m_count; }

  counter(const counter&) noexcept { ++m_count; }
  counter& operator=(const counter&) noexcept = default;

  counter(counter&&) noexcept = default;
  counter& operator=(counter&&) noexcept = default;

  ~counter() { --m_count; }

 private:
  static inline size_t m_count = 0;
};