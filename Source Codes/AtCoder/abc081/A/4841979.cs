using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC081_A
{
    class Program
    {
        static void Main(string[] args)
        {
            int s = int.Parse(Console.ReadLine());

            int count = 0;

            for (int i = 0; i < 3; ++i)
            {
                if (s % 10 == 1)
                {
                    ++count;
                }

                s /= 10;
            }

            Console.WriteLine($"{count}");
        }
    }
}