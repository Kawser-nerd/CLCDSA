using System;
using System.Linq;
class Program
{
    public static void Main()
    {
        string[] str = Console.ReadLine().Split(' ');
        int n, m;
        n = int.Parse(str[0]);
        m = int.Parse(str[1]);
        double ans = 0.5 * Math.Min(Math.Abs(11 * m - (n % 12) * 60), 720 - Math.Abs(11 * m - (n % 12) * 60));
        Console.WriteLine(ans);
    }
}