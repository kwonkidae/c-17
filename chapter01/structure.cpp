
#include <iostream>
#include <filesystem>
#include <cstdlib> // for EXIT_FAILURE

struct MyStruct
{
  int i = 0;
  std::string s;
};

MyStruct getStruct()
{
  return MyStruct{42, "Hello"};
}

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
}
