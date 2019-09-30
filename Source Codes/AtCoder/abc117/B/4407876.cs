// Undone
using System;
using System.Linq;
using System.Collections.Generic;
using System.Collections;
public class Program {
  public static void Main() {
    ReadLine();
    int[] line = ReadIntArray();
    if (line.Max()*2 < line.Sum()) {
      Console.WriteLine("Yes");
    } else {
      Console.WriteLine("No");
    }
  }

  private static string ReadLine() { return Console.ReadLine(); }
  private static int ReadInt() { return int.Parse(Console.ReadLine()); }
  private static double ReadDouble() { return double.Parse(Console.ReadLine()); }
  private static long ReadLong() { return long.Parse(Console.ReadLine()); }
  private static char ReadChar() { return Console.ReadLine()[0]; }
  private static string[] ReadStringArray() { return Console.ReadLine().Split(' '); }
  private static int[] ReadIntArray() { return Console.ReadLine().Split(' ').Select(int.Parse).ToArray(); }
  private static double[] ReadDoubleArray() { return Console.ReadLine().Split(' ').Select(double.Parse).ToArray(); }
  private static long[] ReadLongArray() { return Console.ReadLine().Split(' ').Select(long.Parse).ToArray(); }
  private static char[] ReadCharArray() { return Console.ReadLine().ToArray(); }
  private static string[] ReadCharStringArray() { return Console.ReadLine().ToCharArray().Select(c => c.ToString()).ToArray(); }
}