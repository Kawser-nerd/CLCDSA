using System;
using System.Linq;
 
namespace arc039_a
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int a = 900 + x[0] % 100;
            int b = 100 + x[1] % 100;
            int c = x[0] / 100 * 100 + 90 + x[0] % 10;
            int d = x[1] / 100 * 100 + x[1] % 10;
            int e = x[0] / 10 * 10 + 9;
            int f = x[1] / 10 * 10;
            int max = Math.Max(x[0] - b, a - x[1]);
            max = Math.Max(max, Math.Max(x[0] - d, c - x[1]));
            max = Math.Max(max, Math.Max(x[0] - f, e - x[1]));
            Console.WriteLine(max);
        }
    }
}