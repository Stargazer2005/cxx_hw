#include "array_set.hpp"

#include "hash_set.hpp"

std::unique_ptr<SetImplementation> ArraySet::GetOptimizedImplementation()
    const {
  if (Size() > SWITCH_THRESHOLD) {
    auto optimized = std::make_unique<HashSet>();
    for (int elem : elements) optimized->Add(elem);

    return optimized;
  }
  return nullptr;
}
