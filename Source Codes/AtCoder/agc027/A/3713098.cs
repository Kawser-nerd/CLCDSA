using System;
using System.Linq;
class c
{
    static void Main()
    {
        var nx = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        var a = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        a = a.OrderBy(n => n).ToArray();
        int x = nx[1];
        for (int i = 0; i < a.Length; i++)
        {
            if (x >= a[i])
            {
                x -= a[i];
                a[i] = 0;
            }
            if (i == a.Length - 1) a[i] -= x;
        }
        Console.WriteLine(a.Count(_ => _ == 0));
    }
}