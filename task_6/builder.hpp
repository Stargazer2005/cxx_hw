#pragma once

#include "checkpoint.hpp"

class CheckpointBuilder {
 public:
  virtual ~CheckpointBuilder() = default;
  virtual void AddCheckpoint(const Checkpoint& cp) = 0;
  virtual std::string GetResult() const = 0;
};