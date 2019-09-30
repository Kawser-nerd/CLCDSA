using System;
using System.Linq;

class Program
{
    static void Main()
    {
        string[] array = Console.ReadLine().Split(' ');
        int n = int.Parse(array[0]);
        int x = int.Parse(array[1]);
        int[] a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

        int ans = 0;
        string x_bit = Convert.ToString(x, 2).PadLeft(n, '0');
        for (int i = 0; i < n; i++)
            if (x_bit[n - 1 - i] == '1') ans += a[i];
        Console.WriteLine(ans);
    }
}