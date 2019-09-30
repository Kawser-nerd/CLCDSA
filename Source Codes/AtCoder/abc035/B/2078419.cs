using System;
using System.Linq;
class Program
{
    public static void Main()
    {
        char[] s = Console.ReadLine().ToCharArray();
        int t = int.Parse(Console.ReadLine());
        int l, r, u, d, q, x, y;
        l = s.Count(a => a == 'L');
        r = s.Count(a => a == 'R');
        u = s.Count(a => a == 'U');
        d = s.Count(a => a == 'D');
        q = s.Count(a => a == '?');
        x = r - l;
        y = u - d;
        if (t == 1)
        {
            Console.WriteLine(Math.Abs(x) + Math.Abs(y) + q);
        }
        else
        {
            if (Math.Abs(x) + Math.Abs(y) >= q) Console.WriteLine(Math.Abs(x) + Math.Abs(y) - q);
            else if ((Math.Abs(x) + Math.Abs(y) - q) % 2 == 0) Console.WriteLine(0);
            else Console.WriteLine(1);
        }
    }
}