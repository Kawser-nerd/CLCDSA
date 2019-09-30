using System;
using System.Linq;

class Program
{
  public static void Main(string[] args)
  {
    int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int n = s[0];
    int a = s[1];
    int b = s[2];
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
      if (i < 10) {
        if (i >= a && i <= b) sum += i;
      }
      else {
        char[] Tmp = i.ToString().ToCharArray();
        int[] tmp = new int[Tmp.Count()];
        for (int j = 0; j < Tmp.Count(); j ++) {
          tmp[j] = int.Parse(Tmp[j].ToString());
        }
        if (tmp.Sum() >= a && tmp.Sum() <= b) sum += i;
      }
    }
    Console.WriteLine(sum);
  }
}