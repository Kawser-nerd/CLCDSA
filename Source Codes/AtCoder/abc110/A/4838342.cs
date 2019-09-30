using System;
using System.Linq;
using System.Collections.Generic;

namespace atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ');
            var list = new List<int>() {int.Parse(input[0]), int.Parse(input[1]) , int.Parse(input[2]) };
            list.Sort();
            var s = list[2].ToString() + list[1].ToString();
            Console.WriteLine(int.Parse(s) + list[0]);
        }
    }
}