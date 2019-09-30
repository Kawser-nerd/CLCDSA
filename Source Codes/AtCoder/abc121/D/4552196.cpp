/// @file

#include <iostream>
#include <limits>
#include <string>

namespace {

bool run(std::istream& is, std::ostream& os);
}  // unnamed namespace

/// @brief ????????
#ifdef _TEST
static int run()
#else
int main()
#endif
{
  try {
    if (run(std::cin, std::cout) == false) {
      std::cerr << "main funciton error.\n";
      return EXIT_FAILURE;
    }
  } catch (const std::exception& e) {
    std::cerr << "catch exception\n";
    std::cerr << e.what() << "\n";
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

namespace {

/// @brief ????
bool run(std::istream& is, std::ostream& os)
{
  using Numeric_t = unsigned long;
  const Numeric_t MAX_VALUE = 1e+12;
  Numeric_t a;
  Numeric_t b;
  is >> a >> b;

  auto f = [](Numeric_t num) -> Numeric_t {
    Numeric_t fxor (0);

    if (((num - 1) / 2) % 2 == 0) fxor |= 0x01;

    for (Numeric_t i = 1, N = sizeof(Numeric_t) * 8, v = 2; i < N; ++i, v = v << 1) {
      if (num < (v - 1)) break;

      const Numeric_t REST = num - (v - 1);
      const Numeric_t DIV_NUM = REST / v;
      const Numeric_t MOD_NUM = REST % v;
      if (DIV_NUM % 2 == 1) continue;
      if (MOD_NUM % 2 == 0) continue;
      fxor |= v;
    }

    return fxor;
  };

  const Numeric_t A_XOR = f(a - 1);
  const Numeric_t B_XOR = f(b);
  const Numeric_t F_XOR = B_XOR ^ A_XOR;

  os << F_XOR << "\n";

  return true;
}
}  // unnamed namespace