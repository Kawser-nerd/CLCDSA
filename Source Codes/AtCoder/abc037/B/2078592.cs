using System;
class Program
{
    public static void Main()
    {
        string[] str = Console.ReadLine().Split(' ');
        int n, q;
        n = int.Parse(str[0]);
        q = int.Parse(str[1]);
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = 0;
        for (int j = 0; j < q; j++)
        {
            str = Console.ReadLine().Split(' ');
            for (int i = int.Parse(str[0]) - 1; i <= int.Parse(str[1]) - 1; i++)
                a[i] = int.Parse(str[2]);
        }
        for (int i = 0; i < n; i++)
            Console.WriteLine(a[i]);
    }
}