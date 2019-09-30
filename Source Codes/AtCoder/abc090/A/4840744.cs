using System;
using System.Linq;

namespace A___Diagonal_String
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Enumerable.Repeat(0, 3).Select(_ => Console.ReadLine()).Aggregate((n, e) => n + e).ToArray();

            Console.WriteLine(str[0].ToString() + str[4].ToString() + str[8].ToString());
        }
    }
}