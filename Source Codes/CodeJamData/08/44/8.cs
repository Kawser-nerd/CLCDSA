using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;

public class Program
{
    public static void Main()
    {
        using (var reader = new StreamReader("input.txt"))
        using (var writer = new StreamWriter("output.txt"))
        {
            var N = int.Parse(reader.ReadLine());
            for (var i = 0; i < N; i++)
            {
                var n = int.Parse(reader.ReadLine());
                var s = reader.ReadLine();
                var res = f(n, s);
                writer.Write("Case #{0}: {1}", i + 1, res);
                writer.WriteLine();
            }
        }
    }

    static long f(int k, string s)
    {
        long res = long.MaxValue;
        int[] perm = new int[k];
        for (int i = 0; i < k; i++)
        {
            perm[i] = i;
        }
        do
        {
            char[] arr = new char[s.Length];
            int l = 0;
            while (l < s.Length)
            {
                for (int i = 0; i < k; i++)
                {
                    arr[l + i] = s[l + perm[i]];
                }
                l += k;
            }
            long t = 1;
            for (int i = 1; i < arr.Length; i++)
            {
                if (arr[i] != arr[i - 1]) t++;
            }
            res = Math.Min(res, t);
        }
        while (GetNextPermutation(perm));
        return res;
    }

    public static void Swap<T>(T[] array, int index0, int index1)
    {
        var t = array[index0];
        array[index0] = array[index1];
        array[index1] = t;
    }

    /// <summary>
    /// Tries to set array to it's next permutation
    /// </summary>
    /// <param name="array">the array which is to be set to it's next permutation</param>
    /// <returns>
    /// true, if array was set to it's next permutation;
    /// false, if array is already it's last permutation
    /// </returns>
    public static bool GetNextPermutation<T>(T[] array) where T : IComparable<T>
    {
        var n = array.Length;
        var k = n - 1;
        while (k > 0 && array[k].CompareTo(array[k - 1]) <= 0)
        {
            k--;
        }
        if (k > 0)
        {
            var l = n - 1;
            while (array[l].CompareTo(array[k - 1]) <= 0)
            {
                l--;
            }
            Swap(array, k - 1, l);
            Array.Sort(array, k, array.Length - k);
            return true;
        }
        return false;
    }
}