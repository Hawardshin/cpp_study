#include<iostream>

template <int N, int NN = N - 1>
class Is_Prime
{
    typedef Is_Prime<N, NN - 1> t;
    static const bool result = N % NN && t::result;
};

template <int N>
class Is_Prime<N, 1>
{
    static const bool result = true;
};

int main() {
  std::cout << boolalpha;
  std::cout << "Is prime ? :: " << is_prime<2>::result << std::endl;   // true
  std::cout << "Is prime ? :: " << is_prime<10>::result << std::endl;  // false

  std::cout << "Is prime ? :: " << is_prime<11>::result << std::endl;  // true
  std::cout << "Is prime ? :: " << is_prime<61>::result << std::endl;  // true
}
