#include "log.hpp"

int main() {
  Log* log = Log::Instance();

  log->message(LOG_NORMAL, "Program loaded");
  log->message(LOG_WARNING, "Configuration file not found, using defaults");
  log->message(LOG_NORMAL, "Initialization complete");
  log->message(LOG_ERROR, "Error happens! Help me!");

  log->print();

  return 0;
}
