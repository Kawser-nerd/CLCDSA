using System;

class Program {
  static void Main(string[] args) {
    string s = Console.ReadLine();
    for (int i=0; i<s.Length/2; i++) {
      if (s[i] != s[s.Length-1-i]) {
        Console.WriteLine("No");
        return;
      }
    }
    Console.WriteLine("Yes");
  }
}