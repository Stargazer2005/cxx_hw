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

  CheckpointDirector director(std::make_unique<TextOutputBuilder>());
  std::cout << director.Construct(checkpoints);

  director.SetBuilder(std::make_unique<PenaltyCalculatorBuilder>());
  std::cout << director.Construct(checkpoints);

  return 0;
}