using System;

class Program {
  static void Main(string[] args) {
    string s = Console.ReadLine();
    for (int i=0; i<s.Length; i++) {
      int n =  int.Parse("" + s[i]);
      if (n == 9) {
        Console.WriteLine("Yes");
        return;
      }
    }
    Console.WriteLine("No");
  }
}