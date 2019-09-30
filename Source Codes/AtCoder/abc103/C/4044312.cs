using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_C
{
    class C103
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            List<long> a = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToList();

            long sum = a.Sum(x => x - 1);  
            Console.WriteLine(sum);
        }

    }
}