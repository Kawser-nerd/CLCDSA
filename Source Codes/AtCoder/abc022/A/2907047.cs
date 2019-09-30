using System;

class Program
{
    static void Main(string[] args)
    {
        string[] array = Console.ReadLine().Split(' ');
        int n = int.Parse(array[0]);
        int s = int.Parse(array[1]);
        int t = int.Parse(array[2]);
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = int.Parse(Console.ReadLine());

        int ans = 0;
        if (a[0] >= s && a[0] <= t) ans++;
        for (int i = 1; i < n; i++)
        {
            a[i] += a[i - 1];
            if (a[i] >= s && a[i] <= t) ans++;
        }

        Console.WriteLine(ans);
    }
}