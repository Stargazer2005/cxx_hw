#include <iostream>

#include "type_list.hpp"

// Тесты
int main() {
  using namespace type_list;
  using namespace std;

  cout << "=== Testing TypeList ===\n";

  // Тестовые списки
  using EmptyList = TypeList<>;
  using IntList = TypeList<int>;
  using MyList = TypeList<int, float, double>;
  using ComplexList = TypeList<char, short, int, long>;

  // 1. Тестирование Size
  static_assert(Size<EmptyList>::value == 0, "Empty list size should be 0");
  static_assert(Size<IntList>::value == 1, "IntList size should be 1");
  static_assert(Size<MyList>::value == 3, "MyList size should be 3");
  static_assert(Size<ComplexList>::value == 4, "ComplexList size should be 4");
  cout << "Size tests passed\n";

  // 2. Тестирование TypeAt
  static_assert(is_same_v<TypeAt<0, IntList>::type, int>,
                "IntList[0] should be int");
  static_assert(is_same_v<TypeAt<0, MyList>::type, int>,
                "MyList[0] should be int");
  static_assert(is_same_v<TypeAt<1, MyList>::type, float>,
                "MyList[1] should be float");
  static_assert(is_same_v<TypeAt<2, MyList>::type, double>,
                "MyList[2] should be double");
  static_assert(is_same_v<TypeAt<3, ComplexList>::type, long>,
                "ComplexList[3] should be long");

  // Проверка выхода за границы (должно вызывать ошибку компиляции)
  // static_assert(is_same_v<TypeAt<1, IntList>::type, float>, "This should
  // fail"); static_assert(is_same_v<TypeAt<0, EmptyList>::type, void>, "This
  // should fail");
  cout << "TypeAt tests passed\n";

  // 3. Тестирование Contains
  static_assert(!Contains<int, EmptyList>::value,
                "EmptyList should not contain int");
  static_assert(Contains<int, IntList>::value, "IntList should contain int");
  static_assert(!Contains<float, IntList>::value,
                "IntList should not contain float");
  static_assert(Contains<int, MyList>::value, "MyList should contain int");
  static_assert(Contains<float, MyList>::value, "MyList should contain float");
  static_assert(!Contains<char, MyList>::value,
                "MyList should not contain char");
  static_assert(Contains<short, ComplexList>::value,
                "ComplexList should contain short");
  cout << "Contains tests passed\n";

  // 4. Тестирование IndexOf
  static_assert(IndexOf<int, IntList>::value == 0,
                "int should be at index 0 in IntList");
  static_assert(IndexOf<int, MyList>::value == 0,
                "int should be at index 0 in MyList");
  static_assert(IndexOf<float, MyList>::value == 1,
                "float should be at index 1 in MyList");
  static_assert(IndexOf<double, MyList>::value == 2,
                "double should be at index 2 in MyList");
  static_assert(IndexOf<long, ComplexList>::value == 3,
                "long should be at index 3 in ComplexList");

  // Проверка отсутствующего типа (должно вызывать ошибку компиляции)
  // static_assert(IndexOf<char, IntList>::value == 0, "This should fail");
  cout << "IndexOf tests passed\n";

  // 5. Тестирование Append
  using AppendedEmpty = Append<int, EmptyList>::type;
  static_assert(Size<AppendedEmpty>::value == 1,
                "AppendedEmpty size should be 1");
  static_assert(is_same_v<TypeAt<0, AppendedEmpty>::type, int>,
                "AppendedEmpty[0] should be int");

  using AppendedInt = Append<float, IntList>::type;
  static_assert(Size<AppendedInt>::value == 2, "AppendedInt size should be 2");
  static_assert(is_same_v<TypeAt<0, AppendedInt>::type, int>,
                "AppendedInt[0] should be int");
  static_assert(is_same_v<TypeAt<1, AppendedInt>::type, float>,
                "AppendedInt[1] should be float");

  using AppendedMyList = Append<char, MyList>::type;
  static_assert(Size<AppendedMyList>::value == 4,
                "AppendedMyList size should be 4");
  static_assert(is_same_v<TypeAt<3, AppendedMyList>::type, char>,
                "AppendedMyList[3] should be char");
  cout << "Append tests passed\n";

  // 6. Тестирование Prepend
  using PrependedEmpty = Prepend<int, EmptyList>::type;
  static_assert(Size<PrependedEmpty>::value == 1,
                "PrependedEmpty size should be 1");
  static_assert(is_same_v<TypeAt<0, PrependedEmpty>::type, int>,
                "PrependedEmpty[0] should be int");

  using PrependedInt = Prepend<float, IntList>::type;
  static_assert(Size<PrependedInt>::value == 2,
                "PrependedInt size should be 2");
  static_assert(is_same_v<TypeAt<0, PrependedInt>::type, float>,
                "PrependedInt[0] should be float");
  static_assert(is_same_v<TypeAt<1, PrependedInt>::type, int>,
                "PrependedInt[1] should be int");

  using PrependedMyList = Prepend<char, MyList>::type;
  static_assert(Size<PrependedMyList>::value == 4,
                "PrependedMyList size should be 4");
  static_assert(is_same_v<TypeAt<0, PrependedMyList>::type, char>,
                "PrependedMyList[0] should be char");
  static_assert(is_same_v<TypeAt<1, PrependedMyList>::type, int>,
                "PrependedMyList[1] should be int");
  cout << "Prepend tests passed\n";

  cout << "=== All tests passed ===\n";
  return 0;
}