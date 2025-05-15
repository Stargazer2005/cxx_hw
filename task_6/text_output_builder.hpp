#pragma once

#include <iostream>
#include <vector>

#include "builder.hpp"

class TextOutputBuilder : public CheckpointBuilder {
 public:
  void AddCheckpoint(const Checkpoint& cp) override {
    checkpoints.push_back(cp);
  }

  void GetResult() const override {
    std::cout << "Checkpoint list:\n";
    int index = 1;
    for (const auto& cp : checkpoints) {
      std::cout << index++ << ". " << cp.Name() << " (" << cp.Latitude() << ", "
                << cp.Longitude() << ") - ";

      if (cp.IsMandatory())
        std::cout << "Stage DQ\n";
      else
        std::cout << std::setprecision(2) << std::fixed << cp.Penalty()
                  << " hrs\n";
    }
  }

 private:
  std::vector<Checkpoint> checkpoints;
};