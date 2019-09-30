using System;

class Program {
  static void Main() {
    var s = Console.ReadLine();
    int[] a = new int[26];
    foreach (var c in s) {
      a[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (a[i] == 0) {
        Console.WriteLine((char)(i + 'a'));
        return;
      }
    }
    Console.WriteLine("None");
  }
}