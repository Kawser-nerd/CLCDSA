using System;
using System.Linq;

class Program
{
  public static void Main(string[] args)
  {
    int n = int.Parse(Console.ReadLine());
    int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int count = 0;
    while(true) {
      for (int i = 0; i < n; i ++) {
        if (s[i] % 2 == 1) goto end;
        s[i] /= 2;
      }
      count ++;
    }
    end :;
    Console.WriteLine(count);
  }
}