using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_C
{
    class C100
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            List<long> a = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToList();

            int counter = 0;
            foreach(long n in a)
            {
                long m = n;
                while(m % 2 == 0)
                {
                    m /= 2;
                    counter++;
                }
            }
            Console.WriteLine(counter);
        }

    }
}