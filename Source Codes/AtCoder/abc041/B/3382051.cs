using System;
using System.Linq;

namespace ConsoleApplication4
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            ulong a = ulong.Parse(input[0]);
            ulong b = ulong.Parse(input[1]);
            ulong c = ulong.Parse(input[2]);

            ulong remain;
            ulong div = 1000000007;
            remain = (a * b) % div;
            remain = remain * c;
            remain = remain % div;

            Console.WriteLine(remain);
        }
    }
}