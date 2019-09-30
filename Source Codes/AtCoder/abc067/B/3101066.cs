using System;
using System.Linq;

namespace Sample101
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] str = Console.ReadLine().Split(' ');
            int N = int.Parse(str[0]);
            int K = int.Parse(str[1]);
            int[] barLength = Console.ReadLine()
                .Split(' ')
                .Select(s => int.Parse(s))
                .ToArray();
            Array.Sort(barLength);

            int result = 0;
            for (int i = 0; i < K; ++i)
            {
                result += barLength[barLength.Length - 1 - i];
            }

            Console.WriteLine(result);
        }
    }
}