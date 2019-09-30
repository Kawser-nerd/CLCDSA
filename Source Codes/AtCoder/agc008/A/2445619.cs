using System;
using System.Linq;
namespace AGC008A
{
    class Program
    {
        static long Calc(int a, int b)
        {
            if (a > b)
                return 11451419194545810;
            return b - a;
        }
        static void Main()
        {
            string[] s = Console.ReadLine().Split(' ');
            int x, y;
            x = int.Parse(s[0]);
            y = int.Parse(s[1]);
            long ans = 11451419194545810;
            ans = Math.Min(ans, Calc(x, y));
            ans = Math.Min(ans, Calc(-x, y) + 1);
            ans = Math.Min(ans, Calc(x, -y) + 1);
            ans = Math.Min(ans, Calc(-x, -y) + 2);
            Console.WriteLine(ans);
        }
    }
}