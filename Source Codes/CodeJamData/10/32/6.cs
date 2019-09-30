using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using System.Numerics;

public class A
{
    public static void Main(string[] args)
    {
        int testCases = int.Parse(Console.ReadLine());

        List<string> output = new List<string>(testCases * 10);
        for (int i = 0; i < testCases; i++)
        {
            var lpc = Console.ReadLine().Split(' ').Select(x=>int.Parse(x)).ToArray();
            output.Add(string.Format("Case #{0}: {1}", i + 1, CountThem(lpc[0], lpc[1], lpc[2])));
        }
        foreach (string line in output)
        {
            Console.WriteLine(line);
        }
    }

    private static int CountThem(int l, int p, int c)
    {
        //l *= c;
        int count = 0;

        double ratio = (double)p / l;
        count = (int)Math.Ceiling(Math.Log(ratio) / Math.Log(c));
        count = (int)Math.Ceiling(Math.Log(count) / Math.Log(2));
        return count;
    }


    #region Read
    private static string[] ReadStrings(int length)
    {
        string[] result = new string[length];
        for (int j = 0; j < length; j++)
        {
            result[j] = Console.ReadLine();
        }
        return result;
    }
    private static int[] ReadInts(int length)
    {
        int[] result = new int[length];
        for (int j = 0; j < length; j++)
        {
            result[j] = int.Parse(Console.ReadLine());
        }
        return result;
    }
    private static long[] ReadLong(int length)
    {
        long[] result = new long[length];
        for (int j = 0; j < length; j++)
        {
            result[j] = long.Parse(Console.ReadLine());
        }
        return result;
    }
    private static float[] ReadFloat(int length)
    {
        float[] result = new float[length];
        for (int j = 0; j < length; j++)
        {
            result[j] = float.Parse(Console.ReadLine());
        }
        return result;
    }
    private static double[] ReadDouble(int length)
    {
        double[] result = new double[length];
        for (int j = 0; j < length; j++)
        {
            result[j] = double.Parse(Console.ReadLine());
        }
        return result;
    }
    #endregion
}