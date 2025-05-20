#pragma once

#include <memory>
#include <vector>

class SetImplementation {
 public:
  static constexpr size_t SWITCH_THRESHOLD = 10;

  virtual ~SetImplementation() = default;

  virtual void Add(int element) = 0;
  virtual void Remove(int element) = 0;
  virtual bool Contains(int element) const = 0;
  virtual size_t Size() const = 0;

  virtual std::unique_ptr<SetImplementation> Clone() const = 0;
  virtual std::vector<int> GetElements() const = 0;

  virtual std::unique_ptr<SetImplementation> GetOptimizedImplementation()
      const = 0;

  static std::unique_ptr<SetImplementation> CreateDefault();
};

class Set {
 public:
  explicit Set(std::unique_ptr<SetImplementation> impl =
                   SetImplementation::CreateDefault());

  void Add(int element);
  void Remove(int element);
  bool Contains(int element) const;
  size_t Size() const;

  Set Unite(const Set& other) const;
  Set Intersect(const Set& other) const;

 private:
  void Optimize();
  std::unique_ptr<SetImplementation> impl;
};