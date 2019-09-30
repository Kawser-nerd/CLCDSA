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
            Array.Reverse(barLength);

            int result = 0;
            for (int i = 0; i < K; ++i)
            {
                result += barLength[i];
            }

            Console.WriteLine(result);
        }
    }
}