using System;

class Program
{
    static void Main()
    {
        string[] array = Console.ReadLine().Split(' ');
        int n = int.Parse(array[0]);
        int t = int.Parse(array[1]);
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = int.Parse(Console.ReadLine());

        int ans = 0;
        for (int i = 0; i < n - 1; i++)
            ans += Math.Min(a[i + 1] - a[i], t);
        ans += t;

        Console.WriteLine(ans);
    }
}