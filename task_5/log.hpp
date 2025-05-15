#pragma once

#include <ctime>
#include <iostream>
#include <unordered_map>
#include <vector>

enum LogLevel { LOG_NORMAL, LOG_WARNING, LOG_ERROR };

class Log {
 public:
  static Log* Instance();

  void message(LogLevel level, const std::string& msg);

  void print() const;

  Log(const Log&) = delete;
  Log& operator=(const Log&) = delete;

 private:
  Log() = default;
  ~Log() = default;

  static std::string format_time(time_t timestamp);

  struct LogEntry {
    LogEntry(time_t ts, LogLevel lvl, const std::string& msg)
        : timestamp(ts), level(lvl), message(msg) {}

    time_t timestamp;
    LogLevel level;
    std::string message;
  };

  std::vector<LogEntry> entries;
  static Log* instance;

  static constexpr inline int max_entries = 10;
  static const std::unordered_map<LogLevel, const char*> levelStrings;
};