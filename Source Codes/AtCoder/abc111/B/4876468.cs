using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC111_B();
        }

        static void ABC111_B()
        {
            var N = Console.ReadLine();
            while (true)
            {
                if (N.All(x => x == N[0]))
                    break;

                N = (int.Parse(N) + 1).ToString();
            }
            Console.WriteLine(N);
        }
    }
}