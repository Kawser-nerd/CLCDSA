using System;

class Program {
  static void Main(string[] args) {
    string s = Console.ReadLine();
    int N = int.Parse(s);

    int ret = 0;
    for (int i=0; i<N; i++) {
      string[] tmp = Console.ReadLine().Split(' ');
      int x = int.Parse(tmp[0]);
      int y = int.Parse(tmp[1]);
      ret += y - x + 1;
    }

    Console.WriteLine(ret);
  }
}