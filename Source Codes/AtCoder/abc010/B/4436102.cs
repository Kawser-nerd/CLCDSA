using System;
class c
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var a = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        var p = new int[10] {0, 0, 1, 0, 1, 2, 3, 0, 1, 0 };
        int ans = 0;
        for (int i = 0; i < n; i++) ans += p[a[i]];
        Console.WriteLine(ans);
    }
}