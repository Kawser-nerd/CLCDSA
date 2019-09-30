using System;
class Program
{
    public static void Main()
    {
        string[] str = Console.ReadLine().Split(' ');
        int n = int.Parse(str[0]);
        int t = int.Parse(str[1]);
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = int.Parse(Console.ReadLine());
        Array.Sort(a);
        int[] time = new int[a[n - 1] + t];
        for (int i = 0; i < time.Length; i++)
            time[i] = 0;
        for (int i = 0; i < n; i++)
            time[a[i]] = t;
        int sum = 0;
        for (int i = 1; i < time.Length; i++)
        {
            if (time[i] == 0)
                time[i] = Math.Max(0, time[i - 1] - 1);
            if (time[i] > 0)
                sum++;
        }
        Console.WriteLine(sum);
    }
}