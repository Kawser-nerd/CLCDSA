using System;
using System.Linq;

class Program
{
  public static void Main(string[] args)
  {
    int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int n = s[0];
    int y = s[1];
    int a = 0;
    int b = 0;
    int c = 0;
    for (int i = 0; i <= n; i ++) {
      for (int j = 0; j <= n-i; j ++) {
        if (y == 10000 * i + 5000 * j + 1000 * (n-i-j) && n-i-j >= 0) {
          Console.WriteLine("{0} {1} {2}", i, j, n-i-j);
          goto end;
        }
        if (i == n && j == n-i) Console.WriteLine("-1 -1 -1");
      }
    }
    end:;
  }
}