using System;
using System.Linq;
class Program
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        string[] str = Console.ReadLine().Split(' ');
        int a = int.Parse(str[0]);
        int b = int.Parse(str[1]);
        int k = int.Parse(Console.ReadLine());
        int[] t = new int[k + 2];
        t[0] = a;
        t[k + 1] = b;
        str = Console.ReadLine().Split(' ');
        for (int i = 1; i <= k; i++)
            t[i] = int.Parse(str[i - 1]);
        Array.Sort(t);
        bool f = true;
        for (int i = 0; i < k + 1; i++)
        {
            f = f && (t[i] != t[i + 1]);
        }
        Console.WriteLine(f ? "YES" : "NO");
    }
}