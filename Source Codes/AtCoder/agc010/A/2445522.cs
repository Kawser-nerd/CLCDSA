using System;
using System.Linq;
namespace AGC010A
{
    class Program
    {
        static void Main()
        {
            int n = int.Parse(Console.ReadLine());
            long[] a = Console.ReadLine().Split(' ').Select(s => long.Parse(s)).ToArray();
            string ans = (a.Sum() % 2 == 0) ? "YES" : "NO";
            Console.WriteLine(ans);
        }
    }
}