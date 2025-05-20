#pragma once

#include <unordered_set>

#include "array_set.hpp"
#include "set_bridge.hpp"

// Конкретная реализация для большого количества элементов (хэш-таблица)
class HashSet : public SetImplementation {
 public:
  void Add(int element) override { elements.insert(element); }

  void Remove(int element) override { elements.erase(element); }

  bool Contains(int element) const override {
    return elements.find(element) != elements.end();
  }

  size_t Size() const override { return elements.size(); }

  std::unique_ptr<SetImplementation> Clone() const override {
    auto copy = std::make_unique<HashSet>();
    copy->elements = this->elements;
    return copy;
  }

  std::vector<int> GetElements() const override {
    return {elements.begin(), elements.end()};
  }

  std::unique_ptr<SetImplementation> GetOptimizedImplementation()
      const override;

 private:
  std::unordered_set<int> elements;
};