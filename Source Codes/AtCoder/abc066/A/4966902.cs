using System;
using System.Linq;

namespace A___ringring
{
    class Program
    {
        static void Main(string[] args)
        {
            var a_b_c = Console.ReadLine().Split().Select(int.Parse).OrderBy(x => x).ToArray();

            Console.WriteLine(a_b_c.Where((e, i) => i < 2).Sum());
        }
    }
}