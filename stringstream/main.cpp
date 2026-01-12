#include <iostream>
#include <sstream>

int main() {
  // ask the user to type in one of two things:
  // a command "L 100 200"
  // or just text "hello world"
  // the program will determine if they typed a command or text

  std::string user_input;
  std::string command;

  std::cout << "Enter text or a command: ";
  std::getline(std::cin, user_input);

  std::stringstream ss(user_input);

  ss >> command;

  if (command.length() > 1) {
    std::cout << "This might be some text." << std::endl;
  } else {
    // try to extract a start parameterf
    auto start = -1;
    ss >> start;
    if (ss.fail()) {
      ss.clear();
      std::cout << "No start number exists." << std::endl;
    } else {
      auto end = -1;
      ss >> end;

      if (ss.fail()) {
        ss.clear();
        std::cout << "No end number exists." << std::endl;

        // is there stuff still in the stream?
        std::string stuff;
        ss >> stuff;
        if (stuff.length() > 1) {
          std::cout << "This might be some text." << std::endl;
        }

      } else {
        std::cout << "This might be a command." << std::endl;

        std::cout << "command: " << command;
        std::cout << ", start: " << start;
        std::cout << ", end: " << end << std::endl;
      }
    }
  }

  std::cout << "The user typed: " << user_input << std::endl;

  return 0;
}