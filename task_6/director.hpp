#pragma once

#include <memory>
#include <vector>

#include "builder.hpp"

class CheckpointDirector {
 public:
  explicit CheckpointDirector(std::unique_ptr<CheckpointBuilder> b)
      : builder(std::move(b)) {}

  void SetBuilder(std::unique_ptr<CheckpointBuilder> b) {
    builder = std::move(b);
  }

  void Construct(const std::vector<Checkpoint>& checkpoints) {
    for (const auto& cp : checkpoints) builder->AddCheckpoint(cp);
    builder->GetResult();
  }

 private:
  std::unique_ptr<CheckpointBuilder> builder;
};