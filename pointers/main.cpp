#include <iostream>

int main() {
  auto num = 0x1234LL;

  auto ptr = &num;
  std::cout << std::hex << "*ptr = " << *ptr << std::endl;

  return 0;
}