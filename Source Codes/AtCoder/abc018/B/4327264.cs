using System;
using System.Linq;

class Program
{
  public static void Main(string[] args)
  {
    char[] s = Console.ReadLine().ToCharArray();
    int n = int.Parse(Console.ReadLine());
    for (int i = 0; i < n; i ++) {
      int[] line = Console.ReadLine().Split().Select(int.Parse).ToArray();
      int l = line[0]-1;
      int r = line[1]-1;
      while(r > l) {
        Swap<char>(ref s[l], ref s[r]);
        r --;
        l ++;
      }
    }
    string ans = new String(s);
    Console.WriteLine(ans);
  }
  public static void Swap<T>(ref T a, ref T b) {
    var t = a;
    a = b;
    b = t;
    }
}