using System;
using System.Linq;

namespace A___One_out_of_Three
{
    class Program
    {
        static void Main(string[] args)
        {
            var A_B_C = Console.ReadLine().Split();

            Console.WriteLine(A_B_C.GroupBy(x => x).Single(x => x.Count() == 1).First());
        }
    }
}