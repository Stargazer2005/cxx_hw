#include "set_bridge.hpp"

#include "array_set.hpp"

std::unique_ptr<SetImplementation> SetImplementation::CreateDefault() {
  return std::make_unique<ArraySet>();
}

Set::Set(std::unique_ptr<SetImplementation> impl) : impl(std::move(impl)) {}

void Set::Add(int element) {
  impl->Add(element);
  Optimize();
}

void Set::Remove(int element) {
  impl->Remove(element);
  Optimize();
}

bool Set::Contains(int element) const { return impl->Contains(element); }

size_t Set::Size() const { return impl->Size(); }

Set Set::Unite(const Set& other) const {
  if (!impl || !other.impl) throw std::runtime_error("Set not initialized");

  auto result = impl->Clone();
  for (int elem : other.impl->GetElements()) result->Add(elem);

  return Set(std::move(result));
}

Set Set::Intersect(const Set& other) const {
  if (!impl || !other.impl) throw std::runtime_error("Set not initialized");

  auto result = impl->Clone();
  for (int elem : impl->GetElements())
    if (other.Contains(elem)) result->Add(elem);

  return Set(std::move(result));
}

void Set::Optimize() {
  if (auto optimized = impl->GetOptimizedImplementation())
    impl = std::move(optimized);
}