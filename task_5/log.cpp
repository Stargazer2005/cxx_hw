#include "log.hpp"

#include <iomanip>
#include <iostream>
#include <string>


Log* Log::instance = nullptr;

const std::unordered_map<LogLevel, const char*> Log::levelStrings = {
    {LOG_NORMAL, "NORMAL: "},
    {LOG_WARNING, "WARNING: "},
    {LOG_ERROR, "ERROR: "}};

Log* Log::Instance() {
  if (!instance) instance = new Log();

  return instance;
}

void Log::message(LogLevel level, const std::string& msg) {
  time_t now = time(nullptr);

  entries.emplace_back(now, level, msg);
  if (entries.size() > max_entries) entries.erase(entries.begin());
}

void Log::print() const {
  std::cout << "=== Last " << max_entries << " events ===" << std::endl;

  for (const auto& entry : entries) {
    std::cout << "[" << format_time(entry.timestamp) << "] "
              << levelStrings.at(entry.level) << entry.message << std::endl;
  }

  std::cout << "======================" << std::endl;
}

std::string Log::format_time(time_t timestamp) {
  char timeStr[20];
  strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S",
           localtime(&timestamp));
  return std::string(timeStr);
}
