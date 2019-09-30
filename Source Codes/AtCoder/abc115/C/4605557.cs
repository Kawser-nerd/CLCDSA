using System;
using System.Collections.Generic;
using System.Linq;

namespace Christmas_Eve
{
    class Program
    {
        static void Main(string[] args)
        {
            var nk = Console.ReadLine().Split().Select(int.Parse);
            int n = nk.ElementAt(0);
            int k = nk.ElementAt(1);
            var list = new List<int>();
            for (int i = 0; i < n; i++)
            {
                list.Add(int.Parse(Console.ReadLine()));
            }
            list.Sort();
            int result = int.MaxValue;
            for (int i = 0; i < n - k + 1; i++)
            {
                var temp = list[k + i - 1] - list[i];
                result = result < temp ? result : temp;
            }
            Console.WriteLine(result);
            Console.ReadLine();
        }
    }
}