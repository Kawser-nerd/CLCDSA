using System;
using System.Linq;

namespace abc038_c
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            long ret = 1;
            int up = 1;
            for (int i = 1; i < n; i++)
            {
                up = x[i - 1] < x[i] ? up + 1 : 1;
                ret += up;
            }
            Console.WriteLine(ret);
        }
    }
}