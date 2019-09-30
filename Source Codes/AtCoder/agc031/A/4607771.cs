// Undone
using System;
using System.Linq;
using System.Collections.Generic;
using System.Collections;
public class Program {
  public static void Main() {
    int N = ReadInt();
    char[] S = ReadCharArray();
    int[] count = S.Distinct().Select(c => S.Count(d => d == c)).ToArray();
    long ans = 1L;
    foreach (int i in count) {
      ans *= i + 1;
      ans %= 1000000007;
    }
    Console.WriteLine(ans-1);
  }

  private static List<int> _var;
  public static int cin() { if (_var == null || _var.Count() == 0) { _var = Console.ReadLine().Split(' ').Select(int.Parse).ToList<int>(); } int ans = _var[0]; _var.RemoveAt(0); return ans; }
  public static void Swap<T>(ref T a, ref T b) {T temp = a;a = b;b = temp;}
  public static string ReadStr() { return Console.ReadLine(); }
  public static int ReadInt() { return int.Parse(Console.ReadLine()); }
  public static double ReadDouble() { return double.Parse(Console.ReadLine()); }
  public static long ReadLong() { return long.Parse(Console.ReadLine()); }
  public static char ReadChar() { return Console.ReadLine()[0]; }
  public static string[] ReadStringArray() { return Console.ReadLine().Split(' '); }
  public static int[] ReadIntArray() { return Console.ReadLine().Split(' ').Select(int.Parse).ToArray(); }
  public static double[] ReadDoubleArray() { return Console.ReadLine().Split(' ').Select(double.Parse).ToArray(); }
  public static long[] ReadLongArray() { return Console.ReadLine().Split(' ').Select(long.Parse).ToArray(); }
  public static char[] ReadCharArray() { return Console.ReadLine().ToArray(); }
  public static string[] ReadCharStringArray() { return Console.ReadLine().ToCharArray().Select(c => c.ToString()).ToArray(); }
}