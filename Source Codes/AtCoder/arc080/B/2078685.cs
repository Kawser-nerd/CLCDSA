using System;
using System.Linq;
using System.Collections.Generic;

public class Test
{
    public static void Main()
    {
        int[] hw = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = int.Parse(Console.ReadLine());
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        List<int> res = new List<int>();
        for (int i = 0; i < a.Length; i++)
        {
            res.AddRange(Enumerable.Repeat(i + 1,a[i]));
        }
        for (int i = 0; i < hw[0]; i++)
        {
            int[] arr;
            if (i % 2 == 1) arr = res.Take(hw[1]).Reverse().ToArray();
            else arr = res.Take(hw[1]).ToArray();
            Console.WriteLine(string.Join(" ",arr));
            res.RemoveRange(0, hw[1]);
        }
    }
}