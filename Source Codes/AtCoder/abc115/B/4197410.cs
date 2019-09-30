using System;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine();
            var n = int.Parse(str);

            var ps = new int[n];

            for (int i = 0; i < n; i++)
            {
                str = Console.ReadLine();
                ps[i] = int.Parse(str);
            }

            var output = ps.Sum() - ps.Max() / 2;
            Console.WriteLine(output);
        }
    }
}