using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int n = arr[0];
    int m = arr[1];
    var a = new string[n];
    var b = new string[m];
    for (int i = 0; i < n; i++) {
      a[i] = Console.ReadLine();
    }
    for (int i = 0; i < m; i++) {
      b[i] = Console.ReadLine();
    }
    bool incld = false;
    for (int i = 0; i <= n - m; i++) {
      bool f = false;
      for (int j = 0; j <= n - m; j++) {
        var t = a[i].Substring(j, m);
        if (t == b[0]) {
          f = true;
          for (int k = 1; k < m; k++) {
            if (a[i + k].Substring(j, m) != b[k]) {
              f = false;
              break;
            }
          }
        }
      }
      if (f) {
        incld = true;
        break;
      }
    }
    Console.WriteLine(incld ? "Yes" : "No");
  }
}