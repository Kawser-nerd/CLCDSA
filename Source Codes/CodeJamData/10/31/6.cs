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
            var n = int.Parse(Console.ReadLine());
            var edges = Enumerable.Range(0, n).Select(j => Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray()).ToArray();
            output.Add(string.Format("Case #{0}: {1}", i + 1, CountThem(edges)));
        }
        foreach (string line in output)
        {
            Console.WriteLine(line);
        }
    }

    private static int CountThem(int[][] edges)
    {
        int count = 0;


        for (int i = 0; i < edges.Length; i++)
        {
            var edge = edges[i];
            var a = edge[0];
            var b = edge[1];
            for (int j = i + 1; j < edges.Length; j++)
            {
                edge = edges[j];
                var A = edge[0];
                var B = edge[1];
                if ((A < a && B > b) || (A > a && B < b))
                    count++;
            }
        }
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