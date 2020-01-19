
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
  auto [u, v] = ms;
  std::cout << u;

  assert(&((MyStruct *)&u)->s == &v);
}
