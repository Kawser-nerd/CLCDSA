using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace r1Alarge
{
    class Program
    {
        static void Main(string[] args)
        {

            int t = int.Parse(Console.In.ReadLine());

            TextWriter writer = Console.Out;
            //TextWriter writer = new StreamWriter("out.txt");

            for (int i = 0; i < t; i++)
            {
                bool ans = true;
                string[] input = Console.In.ReadLine().Split(' ');

                long n = long.Parse(input[0]);
                int pd = int.Parse(input[1]);
                int pg = int.Parse(input[2]);

                bool[] possible = new bool[101];
                Array.Clear(possible, 0, 101);
                possible[0] = true;
                possible[100] = true;

                int max = (int)Math.Min(100L, n);
                for (int j = 1; j <= max; j++)
                {
                    for (int k = j; k <= max; k++)
                    {
                        if ((j * 100) % k == 0)
                        {
                            int v = (j * 100) / k;
                            possible[v] = true;
                        }
                    }
                }

                ans = possible[pd];

                if(pg == 100 && pd < 100)ans = false;
                if (pg == 0 && pd > 0) ans = false;

                writer.WriteLine("Case #" + (i + 1) + ": " + (ans?"Possible":"Broken"));
            }
        }
    }
}
