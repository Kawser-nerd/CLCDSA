using System;
using System.Linq;

namespace ConsoleApp115
{
    class Program
    {
        static void Main(string[] args)
        {
            var a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

            var min = int.MaxValue;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        if (i != j && j != k && k != i)
                        {
                            min = Math.Min(min,
                                Math.Abs(a[j] - a[i]) + Math.Abs(a[k] - a[j]));
                        }
                    }
                }
            }

            Console.WriteLine(min);
        }
    }
}