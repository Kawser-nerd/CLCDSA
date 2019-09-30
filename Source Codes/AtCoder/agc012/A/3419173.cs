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

            var N = int.Parse(Console.ReadLine());
            var input = Console.ReadLine().Split(' ').Select(x =>int.Parse(x)).ToArray();
            Array.Sort(input);
            Array.Reverse(input);

            long sum = 0;

            for (int i = 0; i < 2*N; i++)
            {
                if (i % 2 == 1) sum += input[i];
            }
            Console.WriteLine(sum);
        }
    }
}