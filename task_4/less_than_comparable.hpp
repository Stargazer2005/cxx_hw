#pragma once

template <typename Derived>
class less_than_comparable {
 public:
  friend bool operator>(const Derived& lhs, const Derived& rhs) {
    return rhs < lhs;
  }

  friend bool operator<=(const Derived& lhs, const Derived& rhs) {
    return !(rhs < lhs);
  }

  friend bool operator>=(const Derived& lhs, const Derived& rhs) {
    return !(lhs < rhs);
  }

  friend bool operator==(const Derived& lhs, const Derived& rhs) {
    return !((lhs < rhs) || (rhs < lhs));
  }

  friend bool operator!=(const Derived& lhs, const Derived& rhs) {
    return (lhs < rhs) || (rhs < lhs);
  }
};