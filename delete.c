// 소멸자 호출 확인하기
#include <string.h>
#include <iostream>

class Test {
  char c;

 public:
  Test(char _c) {
    c = _c;
    std::cout << "생성자 호출 " << c << std::endl;
  }
  ~Test() { std::cout << "소멸자 호출 " << c << std::endl; }
};
void simple_function() { Test b('b'); }

int main() 
{
  Test *k = new Test('a');
  Test c('c');
  simple_function();
  delete k;
}
