using System;

class Program {
  static void Main() {
    var s = Console.ReadLine();
    int[] a = new int[26];
    foreach (var c in s) {
      a[c - 97]++;
    }
    var ans = "Yes";
    foreach (var n in a) {
      if ((n & 1) == 1) {
        ans = "No";
        break;
      }
    }
    Console.WriteLine(ans);
  }
}