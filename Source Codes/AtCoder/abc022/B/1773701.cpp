#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cstdlib>

#include <type_traits>

namespace FastIn {
  static constexpr size_t BUF_SIZE=1<<17, INT_LEN=24, FLT_LEN=400;
  static char buf[BUF_SIZE|1]={}, *pos=buf, *endbuf=nullptr;

  inline bool rebuffer() {
    size_t rest=endbuf-pos;
    if (rest > pos-buf) {
      // not disjoint
      return true;
    }

    // disjoint
    std::memcpy(buf, pos, rest);

    pos = buf;

    size_t len=std::fread(pos+rest, 1, BUF_SIZE-rest, stdin);
    *(endbuf = buf + (rest+len)) = 0;

    return *pos;
  }

  inline bool scan(char &in) {
    if ((in = *pos)) {
      ++pos;
      return true;
    }

    return rebuffer() && (in = *pos++);
  }

  inline bool scan(char *in) {
    if ((*in = *pos) == 0) {
      if (rebuffer() && (*in = *pos) == 0) {
        return false;
      }
    }
    ++in;
    while (true) {
      if ((*in = *pos++) == 0) {
        if (rebuffer() && (*in = *pos++) == 0) {
          return true;
        }
      }
      ++in;
    }
  }

  inline bool scan(double &in) {
    if (pos + FLT_LEN >= endbuf && !rebuffer()) {
      in = 0.0;
      return false;
    }

    char *tmp;
    in = std::strtod(pos, &tmp);
    pos = tmp;
    return true;
  }

  template <class Int>
  inline bool scan(
      Int &in,
      typename std::enable_if<std::is_signed<Int>::value>::type *un=nullptr
  ) {
    in = 0;

    // assume that no redundant whitespace appears
    if (pos + INT_LEN >= endbuf && !rebuffer()) {
      return false;
    }

    // assume that ' ' < '+' < '-' < '0' < '9'
    while (*pos < '-') {
      ++pos;
    }

    bool neg=false;
    if (*pos == '-') {
      ++pos;
      neg = true;
    }

    // assume that numbers are separated by the character whose value is
    // less than '0' (e.g. whitespaces, newlines)
    do {
      in = in*10 + (*pos)-'0';
    } while (*++pos >= '0');

    if (neg) {
      in = -in;
    }
    return true;
  }

  template <class Int>
  inline bool scan(
      Int &in,
      typename std::enable_if<!std::is_signed<Int>::value>::type *un=nullptr
  ) {
    in = 0;

    // assume that no redundant whitespace appears
    if (pos + INT_LEN >= endbuf && !rebuffer()) {
      return false;
    }

    // assume that ' ' < '0' < '9' and minus signs do not appear
    //while (*pos < '0') {
    //  ++pos;
    //}

    // assume that numbers are separated by the character whose value is
    // less than '0' (e.g. whitespaces, newlines)
    do {
      in = in*10 + (*pos)-'0';
    } while (*++pos >= '0');

    ++pos;
    return true;
  }

  inline bool eat() {
    if (*pos > ' ') {
      return true;
    }

    do {
      if (*pos == 0 && !rebuffer()) {
        return false;
      }
    } while (*++pos <= ' ');

    return true;
  }
      
  inline bool eat(char ch) {
    if (*pos == ch) {
      return true;
    }

    do {
      if (*pos == 0 && !rebuffer()) {
        return false;
      }
    } while (*++pos != ch);

    return true;
  }

  class Scanner {
    bool rebuffer() {
      return FastIn::rebuffer();
    }

  public:
    Scanner() {
      endbuf = pos + std::fread(buf, 1, BUF_SIZE, stdin);
    }

    template <class T>
    inline bool scan(T &in) {
      return FastIn::scan(in);
    }

    template <class First, class... Rest>
    inline bool scan(First &in, Rest &...ins) {
      return scan(in) && scan(ins...);
    }
  };
}

namespace FastOut {
  static constexpr size_t BUF_SIZE=1<<17, INT_LEN=24, FLT_LEN=400;
  static char buf[BUF_SIZE|1]={}, *pos=buf, *endbuf=pos+BUF_SIZE;
  class Printer {
    void flush();

  public:
    void print(const char out);
    void print(const char *out);
    template <class Char, size_t Len>
    void print(const Char (&out)[Len]);
    void print(const double out);
    template <class Int>
    void print(
        Int &out,
        std::enable_if<std::is_signed<Int>::value> *un=nullptr
    );
    template <class Int>
    void print(
        Int &out,
        std::enable_if<!std::is_signed<Int>::value> *un=nullptr
    );
    template <class First, class... Rest>
    void print(const First &&out, const Rest &&...outs) {
      print(out);
      print(outs...);
    }
  };
}

FastIn::Scanner cin;
//FastOut::Printer cout;

char X[100010];

int main() {
  size_t N;
  cin.scan(N);

  int res=0;
  for (size_t i=0; i<N; ++i) {
    size_t A;
    cin.scan(A);
    char &tmp=X[A];
    res += tmp;
    tmp = 1;
  }

  printf("%d\n", res);
  return 0;
}