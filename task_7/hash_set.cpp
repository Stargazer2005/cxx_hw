#include "hash_set.hpp"

#include "array_set.hpp"

std::unique_ptr<SetImplementation> HashSet::GetOptimizedImplementation() const {
  if (Size() <= SWITCH_THRESHOLD) {
    auto optimized = std::make_unique<ArraySet>();
    for (int elem : elements) optimized->Add(elem);

    return optimized;
  }
  return nullptr;
}