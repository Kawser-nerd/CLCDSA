using System;
using System.Linq;

namespace Streamline
{
    class Program
    {
        static void Main(string[] args)
        {
            var nm = Console.ReadLine().Split().Select(int.Parse);
            var input = Console.ReadLine().Split().Select(int.Parse).OrderBy(i => i).ToArray();
            int fullLenght = input[input.Length - 1] - input[0];
            var diffrences = new int[input.Length - 1];
            for (int i = 0, j = 1; i < input.Length - 1; i++, j++)
            {
                diffrences[i] = input[j] - input[i];
            }
            Console.WriteLine(fullLenght - diffrences.OrderBy(d => -d).Take(nm.ElementAt(0) - 1).Sum());
        }
    }
}