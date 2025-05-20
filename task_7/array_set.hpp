#pragma once

#include <algorithm>
#include <vector>

#include "set_bridge.hpp"

// Конкретная реализация для малого количества элементов (массив)
class ArraySet : public SetImplementation {
 public:
  void Add(int element) override {
    if (!Contains(element)) elements.push_back(element);
  }

  void Remove(int element) override {
    auto it = std::find(elements.begin(), elements.end(), element);
    if (it != elements.end()) elements.erase(it);
  }

  bool Contains(int element) const override {
    return std::find(elements.begin(), elements.end(), element) !=
           elements.end();
  }

  size_t Size() const override { return elements.size(); }

  std::unique_ptr<SetImplementation> Clone() const override {
    auto copy = std::make_unique<ArraySet>();
    copy->elements = this->elements;
    return copy;
  }

  std::vector<int> GetElements() const override { return elements; }

  std::unique_ptr<SetImplementation> GetOptimizedImplementation()
      const override;

 private:
  std::vector<int> elements;
};
