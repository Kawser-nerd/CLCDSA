using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static void Main(string[] args)
    {
        var line1 = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
        long N = line1[0];
        long D = line1[1];

        var d = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();

        long Q = long.Parse(Console.ReadLine());

        var q = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();

        long minItazuraable = 1;
        long[] minItazuraableArray = new long[d.Length + 1];
        minItazuraableArray[d.Length] = 1;

        for(long i = 0; i < d.Length; i++)
        {
            var item = d[d.Length - i - 1];  // reverse 

            if (item / 2 >= minItazuraable)
            {
                // no change
            }
            else
            {
                minItazuraable += item;
            }

            minItazuraableArray[d.Length - i - 1] = minItazuraable;
        }

        //Console.WriteLine(String.Join(", ", minItazuraableArray));

        // alice?????????

        long[] aliceDistance = new long[d.Length + 1];
        aliceDistance[0] = D;

        for (long i = 0; i < d.Length; i++)
        {
            aliceDistance[i + 1] = Math.Min(Math.Abs(aliceDistance[i] - d[i]), aliceDistance[i]);
        }

        //Console.WriteLine(String.Join(", ", aliceDistance));

        foreach (var qi in q) { 
            Console.WriteLine(minItazuraableArray[qi + 1 - 1] <= aliceDistance[qi - 1] ? "YES" : "NO");
        }
    }
}