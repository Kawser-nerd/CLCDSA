using System;

class Program {
  static void Main() {
    var s = Console.ReadLine();
    int a = 0, z = 0;
    for (int i = 0; i < s.Length; i++) {
      if (s[i] == 'A') {
        a = i;
        break;
      }
    }
    for (int i = s.Length - 1; i >= 0; i--) {
      if (s[i] == 'Z') {
        z = i;
        break;
      }
    }
    Console.WriteLine(z - a + 1);
  }
}