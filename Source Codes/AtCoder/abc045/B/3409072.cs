using System;

class Program {
  static void Main() {
    var s = new string[3];
    int t = 0;
    for (int i = 0; i < 3; i++) {
      s[i] = Console.ReadLine();
    }
    while (true) {
      if (s[t].Length == 0) break;
      int u = s[t][0] - 'a';
      s[t] = s[t].Substring(1);
      t = u;
    }
    Console.WriteLine((char)('A' + t));
  }
}