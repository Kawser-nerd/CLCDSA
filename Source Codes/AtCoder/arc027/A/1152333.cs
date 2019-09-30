using System;
using System.Linq;

namespace arc027_1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int time = x[0] * 60 + x[1];
            Console.WriteLine(1080 - time);
        }
    }
}