using System;
using System.Globalization;

class Program {
  static void Main(string[] args) {
    string s = Console.ReadLine();
    int n = int.Parse(s);
    ulong[] t = new ulong[n];
    for (int i=0; i<n; i++) {
      string tmp = Console.ReadLine();
        t[i] = (ulong)Int64.Parse(tmp);
    }

    ulong max = 1;
    for (int i=0; i<n; i++) {
      max = Euc(max, t[i]);
    }
    Console.WriteLine(max);
  }

  static ulong Euc(ulong a, ulong b) {
    if (a < b) {
      ulong tmp = b;
      b = a;
      a = tmp;
    }

    ulong pa = a;
    ulong pb = b;

    ulong r = a % b;
    while(r != 0) {
      a = b;
      b = r;
      r = a % b;
    }

    return (pa / b) * pb;
  }
}