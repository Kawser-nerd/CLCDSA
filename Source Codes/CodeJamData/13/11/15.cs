using System;

public sealed class Program {

  public Program() {
    Int32 tests = Int32.Parse(Console.ReadLine()), i;
    Int64 r, paint, lo, hi, mi;
    for (Int32 t = 1; t <= tests; ++t) {
      var token = Array.ConvertAll<String, Int64>(Console.ReadLine().Split(), Int64.Parse);
      r = token[0];
      paint = token[1];
      lo = 0;
      hi = paint + 1;
      while (lo + 1 != hi) {
        mi = (lo + hi) / 2;
        try {
          checked {
            if ((r + mi - 1L) * mi * 2L + mi > paint) {
              hi = mi;
            } else {
              lo = mi;
            }
          }
        } catch {
          hi = mi;
        }
      }
      Console.WriteLine("Case #{0}: {1}", t, lo);
    }
  }

  // stuff cutline

  public static void Main() {
#if DEBUG
    Console.SetIn(new System.IO.StreamReader("..\\..\\in.txt"));
#else
    Console.SetIn(new System.IO.StreamReader(@"C:\Users\anonymous\Downloads\A-large.in"));
    Console.SetOut(new System.IO.StreamWriter(@"..\\..\\out.txt"));
#endif
    new Program();
    Console.Out.Flush();
  }

  static Int32 ReadInt() {
    Boolean neg = false;
    Int32 ch, ans = 0;
    do {
      ch = Console.Read();
      neg |= ch == (Int32)'-';
    } while (!Char.IsDigit((Char)ch));
    do {
      ans = ans * 10 + (ch & 0xf);
      ch = Console.Read();
    } while (Char.IsDigit((Char)ch));
    return neg ? -ans : ans;
  }

  static Int32[] ReadArray() {
    return Array.ConvertAll<String, Int32>(Console.ReadLine().Split(), Int32.Parse);
  }

}