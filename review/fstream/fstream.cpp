// 파일에서의 입출력
#include <fstream>
#include <iostream>
#include <string>

int main() {
  // 파일 읽기 준비
  std::ifstream sin("test.txt");// 경로를 지정해줘야 한다. "C:\a\b\c.txt" 사실은 이렇게 전달해야한다.
  std::string s;

  if (sin.is_open()) {//파일이 열렸는지 여부를 확인하는 함수
    sin >> s;// in 객체를 이용해서 파일로 부터 읽을 수 있습니다. (cin에서 >> 로 읽을 때 공백 문자가 나올 까지 읽었던 것처럼 여기도 동일하다.
    std::cout << "입력 받은 문자열 :: " << s << std::endl;
  } else {
    std::cout << "파일을 찾을 수 없습니다!" << std::endl;
  }
  return 0;
}
