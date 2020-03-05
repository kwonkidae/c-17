
#include <iostream>
#include <filesystem>
#include <cstdlib> // for EXIT_FAILURE
#include <array>
struct MyStruct
{
  int i = 0;
  std::string s;
};

MyStruct getStruct()
{
  return MyStruct{42, "Hello"};
}

struct B
{
  int a = 1;
  int b = 2;
};

struct D1 : B
{
};

struct D2 : B
{
  int c = 3;
};

int main(int argc, char *argv[])
{
  MyStruct ms{42, "Hello"};
  // auto [u, v] = ms;
  // std::cout << u << std::endl;
  // std::cout << &v;
  // assert(&(((MyStruct *)&u)->s) == &v);

  auto &&[v, n] = std::move(ms);
  std::cout << "ms.s: " << ms.s << '\n';

  std::string s = std::move(n);
  std::cout << "ms.s: " << ms.s << '\n';

  auto [z, x] = D1{};

  std::cout << x << " " << z << std::endl;

  int arr[] = {47, 11};
  auto [x1, y1] = arr;

  std::cout << x1 << " " << y1 << std::endl;
  {
    std::array<int, 4> stdarr{1, 2, 3, 4};

    auto &[i, j, k, l] = stdarr;
    i += 20;

    std::cout << stdarr[0] << std::endl;
  }
}
