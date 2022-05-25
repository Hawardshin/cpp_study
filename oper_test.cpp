//#include <iostream>
//using namespace std;
//int main() {
//  int t;
//  while (true) {
//    std::cin >> t;
//    std::cout << "입력 :: " << t << std::endl;
//    if (t == 0) break;
//  }
//}

#include <iostream>
#include <string>

int main() {
  int t;
  std::cin >> t;  // 고의적으로 문자를 입력하면 failbit 가 켜진다
  std::cout << "fail 비트가 켜진 상태이므로, 입력받지 않는다" << std::endl;
  std::string s;
  std::cin >> s;
}
