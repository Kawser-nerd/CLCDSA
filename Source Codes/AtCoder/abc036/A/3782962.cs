using System;
using System.Collections.Generic;
using System.Linq;

namespace hoge
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
            Console.WriteLine(n[1] % n[0] == 0 ? n[1] / n[0] : n[1] / n[0] + 1);
        }
    }
}