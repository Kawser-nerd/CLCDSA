using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        var s = ReadInt();

        var hash = new HashSet<int>();
        hash.Add(s);

        while (true)
        {
            if (s % 2 == 0)
            {
                s /= 2;
            }
            else
            {
                s = 3 * s + 1;
            }

            if (hash.Contains(s)) break;
            hash.Add(s);
        }

        Console.WriteLine(hash.Count + 1);
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