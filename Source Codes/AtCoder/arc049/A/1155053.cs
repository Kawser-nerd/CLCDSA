using System;
using System.Linq;

namespace arc049_a
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            for (int i = 0; i < 4; i++)
            {
                s = s.Insert(x[i] + i, '"'.ToString());
            }
            Console.WriteLine(s);
        }
    }
}