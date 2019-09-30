using System;
using System.Linq;

namespace Grand_Garden
{
    class Program
    {
        static void Main(string[] args)
        {
            var result = 0;
            int n = int.Parse(Console.ReadLine());
            var input = Console.ReadLine().Split().Select(int.Parse).ToList();
            input.Insert(0, 0);
            for (int i = 1; i < input.Count; i++)
            {
                int a = input[i] - input[i - 1];
                if (a > 0) { result += a; }
            }
            Console.WriteLine(result);
            Console.ReadLine();
        }
    }
}