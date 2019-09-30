using System;
using System.Linq;

namespace ABC078_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = Console.ReadLine().Split().Select(int.Parse).ToArray();
            Console.WriteLine((N[0] - N[2]) / (N[1] + N[2]));
        }
    }
}