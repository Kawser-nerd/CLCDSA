using System;
using System.Linq;
class Program
{
    static void Main()
    {
        var inp = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        var st = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        long ans = inp[0] * st[0] + inp[1] * st[1];
        if (st.Sum() >= inp[3]) ans -= st.Sum() * inp[2];
        Console.WriteLine(ans);
    }
}