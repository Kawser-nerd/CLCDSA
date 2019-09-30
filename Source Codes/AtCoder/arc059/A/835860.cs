using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace a
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int max = int.MaxValue;
            for (int i = -100; i <= 100; i++)
            {
                int tmp = 0;
                for (int j = 0; j < n; j++)
                {
                    tmp += (int)Math.Pow((i - a[j]), 2);
                }
                if(tmp<max)
                {
                    max = tmp;
                }
            }
            Console.WriteLine(max);
        }
    }
}