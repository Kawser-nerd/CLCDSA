using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        var inputs = ReadInts();
        Console.WriteLine(inputs[0] * inputs[1] / 2);
    }

    public static string Read() { return Console.ReadLine(); }
    public static int ReadInt() { return int.Parse(Read()); }
    public static long ReadLong() { return long.Parse(Read()); }
    public static double ReadDouble() { return double.Parse(Read()); }

    public static string[] Reads() { return Console.ReadLine().Split(' '); }
    public static int[] ReadInts() { return Reads().Select(_ => int.Parse(_)).ToArray(); }
    public static long[] ReadLongs() { return Reads().Select(_ => long.Parse(_)).ToArray(); }
    public static double[] ReadDoubles() { return Reads().Select(_ => double.Parse(_)).ToArray(); }
}