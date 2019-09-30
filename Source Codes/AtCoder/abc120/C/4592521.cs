using System;
using System.Linq;

namespace C
{
    class Program
    {
        static void Main(string[] args)
        {
            // ?????
            var input = Console.ReadLine();

            // 0, 1????????
            var count0 = input.Where(c => c == '0').Count();
            var count1 = input.Where(c => c == '1').Count();

            var result = (count0 > count1) ? count1 * 2 : count0 * 2;
            Console.WriteLine(result);
        }
    }
}