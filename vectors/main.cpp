#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
  for (auto& n : v) {
    os << n << " ";
  }
  return os;
}

void operator<<(std::vector<int>& v, const std::vector<int>& in_vec) {
  for (auto& n : in_vec) {
    v.push_back(n);
  }
}

int main() {
  std::vector v = {1, 2, 3, 4, 5};

  v.reserve(100);

  std::cout << v << std::endl;
  std::cout << "capacity: " << v.capacity() << std::endl;
  std::cout << "size: " << v.size() << std::endl;

  v.push_back(6);

  std::cout << v << std::endl;
  std::cout << "capacity: " << v.capacity() << std::endl;
  std::cout << "size: " << v.size() << std::endl;

  v << std::vector({7, 8, 9, 10, 11});

  std::cout << v << std::endl;
  std::cout << "capacity: " << v.capacity() << std::endl;
  std::cout << "size: " << v.size() << std::endl;

  v << std::vector({12, 13, 14, 15, 16, 17, 18, 19, 20, 21});

  std::cout << v << std::endl;
  std::cout << "capacity: " << v.capacity() << std::endl;
  std::cout << "size: " << v.size() << std::endl;

  v.shrink_to_fit();

  std::cout << v << std::endl;
  std::cout << "capacity: " << v.capacity() << std::endl;
  std::cout << "size: " << v.size() << std::endl;

  return 0;
}