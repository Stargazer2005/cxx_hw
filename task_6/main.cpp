#include <iostream>
#include <memory>
#include <optional>
#include <string>
#include <vector>

#include "director.hpp"
#include "penalty_calculator_builder.hpp"
#include "text_output_builder.hpp"

int main() {
  std::vector<Checkpoint> checkpoints = {
      Checkpoint("Start", 55.7522, 37.6156),
      Checkpoint("Mountain Pass", 43.3564, 42.4455).SetPenalty(2.5),
      Checkpoint("River Crossing", 44.1234, 45.6789),
      Checkpoint("Finish", 55.7522, 37.6156),
      Checkpoint("Bonus Stage", 43.2567, 42.8765).SetPenalty(1.8)};

  auto text_builder = std::make_unique<TextOutputBuilder>();
  CheckpointDirector director(std::move(text_builder));
  director.Construct(checkpoints);

  auto penalty_builder = std::make_unique<PenaltyCalculatorBuilder>();
  director.SetBuilder(std::move(penalty_builder));
  director.Construct(checkpoints);

  return 0;
}