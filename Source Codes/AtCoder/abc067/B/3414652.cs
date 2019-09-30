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
            var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            var l = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();

            l.Sort();
            l.Reverse();

            var sum = 0;

            for (int i = 0; i < input[1]; i++)
            {
                sum += l[i];
            }

            Console.WriteLine(sum);
        }
    }
}