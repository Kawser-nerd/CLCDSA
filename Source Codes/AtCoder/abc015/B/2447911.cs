using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20180502_pra
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = int.Parse(Console.ReadLine());
            string[] b = Console.ReadLine().Split(' ');
            int[] c = b.Select(int.Parse).ToArray();

            int count = 0;
            int sum = 0;
            double abe = 0;

            for(int i = 0; i < c.Length; ++i)
            {
                sum += c[i];

                if (c[i] > 0)
                {
                    count++;
                }
            }

            abe =(double) sum / count;

            double abe2 = Math.Ceiling(abe);
            Console.WriteLine(abe2);
        }
    }
}