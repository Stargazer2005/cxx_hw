#pragma once

#include <iomanip>
#include <iostream>

#include "builder.hpp"

class PenaltyCalculatorBuilder : public CheckpointBuilder {
 public:
  void AddCheckpoint(const Checkpoint& cp) override {
    if (!cp.IsMandatory()) total_penalty += cp.Penalty();
  }

  void GetResult() const override {
    std::cout << "\nTotal penalty for skipped optional checkpoints: "
              << total_penalty << " hrs\n";
  }

 private:
  double total_penalty = 0.0;
};