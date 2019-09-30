using System;
using System.Linq;

class A
{
    static void Main()
    {
        int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] a = new int[n[0] + 1];
        for (int i = 0; i < n[1]; i++)
        {
            int[] d = Console.ReadLine().Split().Select(int.Parse).ToArray();
            a[d[0] - 1]++;
            a[d[1]]--;
        }
        Console.Write(Math.Abs(a[0] % 2));
        for (int i = 1; i < n[0]; i++)
        {
            a[i] = a[i - 1] + a[i];
            Console.Write(Math.Abs(a[i] % 2));
        }
        Console.WriteLine();
        Console.ReadLine();

    }
}