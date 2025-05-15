#pragma once

#include "checkpoint.hpp"

class CheckpointBuilder {
 public:
  virtual ~CheckpointBuilder() = default;
  virtual void AddCheckpoint(const Checkpoint& cp) = 0;
  virtual void GetResult() const = 0;
};