#include <iostream>

#include "array_set.hpp"
#include "set_bridge.hpp"

// Пример использования
int main() {
  Set my_set(std::make_unique<ArraySet>());

  for (int i = 0; i < 15; ++i) my_set.Add(i);

  std::cout << "Set size after adding 15 elements: " << my_set.Size()
            << std::endl;

  for (int i = 0; i < 10; ++i) my_set.Remove(i);

  std::cout << "Set size after removing 10 elements: " << my_set.Size()
            << std::endl;

  std::cout << "Contains 12: " << std::boolalpha << my_set.Contains(12)
            << std::endl;
  std::cout << "Contains 5: " << std::boolalpha << my_set.Contains(5)
            << std::endl;

  Set other_set;
  other_set.Add(12);
  other_set.Add(13);
  other_set.Add(14);
  other_set.Add(15);

  auto union_set = my_set.Unite(other_set);
  auto intersection_set = my_set.Intersect(other_set);

  std::cout << "Union size: " << union_set.Size() << std::endl;
  std::cout << "Intersection size: " << intersection_set.Size() << std::endl;

  return 0;
}