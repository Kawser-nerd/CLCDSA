using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC118_B();
        }

        static void ABC118_B()
        {
            var NM = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var dict = new Dictionary<int, int>();

            for (var m = 1; m <= NM[1]; m++)
                dict.Add(m, 0);

            for (var n = 0; n < NM[0]; n++)
            {
                var KA = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                for (var a = 1; a <= KA[0]; a++)
                    dict[KA[a]] += 1;
            }
            Console.WriteLine(dict.Values.Count(x => x == NM[0]));
        }
    }
}