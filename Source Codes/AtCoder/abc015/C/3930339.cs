using System;
using System.Linq;
class c
{
    static void Main()
    {
        var nk = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        var list = new int[nk[0]][];
        for (int i = 0; i < nk[0]; i++)
        {
            list[i] = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        }
        Console.WriteLine(search(0, list, 0) ? "Nothing" : "Found");
    }
    static bool search(int n, int[][] list, int now)
    {
        if (n == list.Count()) { if (now == 0) return false; }
        else
        {
            for (int i = 0; i < list[0].Length; i++)
            {
                if (!search(n + 1, list, now ^ list[n][i])) return false;
            }
        }
        return true;
    }
}