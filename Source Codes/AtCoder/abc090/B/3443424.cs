using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int a = arr[0];
    int b = arr[1];
    int ans = 0;
    for (int i = a; i <= b; i++) {
      string s = i.ToString();
      if (s[0] == s[4] && s[1] == s[3]) ans++;
    }
    Console.WriteLine(ans);
  }
}