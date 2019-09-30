using System;
using System.Linq;
using System.Collections.Generic;
using System.Collections;
public class Program {
  public static void Main() {
    ReadStr();
    Console.WriteLine(GCD(ReadIntArray()));
  }

  public static int GCD(int[] array) {
    int res = array[0];
    for (int i = 1; i < array.Length; i++) {
      res = GCD(res, array[i]);
    }
    return res;
  }

  public static int GCD(int a, int b) {
    if (a < b) {
      Swap(ref a, ref b);
    }
    int mod = a % b, div = b, temp;
    while (mod != 0) {
      temp = mod;
      mod = div % mod;
      div = temp;
    }
    return div;
  }

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