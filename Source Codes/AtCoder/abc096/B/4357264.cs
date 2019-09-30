using System;
using System.Linq;

namespace B.Maximum_Sum
{
    class Program
    {
        static void Main(string[] args)
        {
            var ABC = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var K = int.Parse(Console.ReadLine());
            int ans = 0;

            Array.Sort(ABC);

            for (int i = 0; i < K; i++)
            {
                ABC[ABC.Length - 1] *= 2;
            }

            Console.WriteLine(ABC.Sum());
        }
    }
}