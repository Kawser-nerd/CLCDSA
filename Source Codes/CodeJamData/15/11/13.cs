using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam_2015_R1A_1
{
    class Program
    {
        static void Main(string[] args)
        {
            var lines = File.ReadAllLines(@"Z:\Projects\Соревнования\CodeJam 2015\Round1A\Task1_input\input.txt");
            for (int i = 0; i < Int32.Parse(lines[0]); i++)
            {
                var platesCount = Int32.Parse(lines[1 + i*2]);
                var platesStr = lines[i*2 + 2];
                var plates = platesStr.Split(' ').Select(Int32.Parse).ToList();
                int min1 = 0;
                int min2 = 0;
                int maxRes = 0;
                for (int b = 0; b < platesCount-1; b++)
                {
                    int res = plates[b] - plates[b + 1];
                    if (res > 0) min1 += res;
                    if (res > maxRes) maxRes = res;
                }
                for (int b = 0; b < platesCount - 1; b++)
                {
                    int res = plates[b];
                    if (res > maxRes) { res = maxRes; }
                    min2 += res;
                }

                Console.WriteLine("Case #{0}: {1} {2}", i+1, min1, min2);
            }
//            Console.WriteLine();
        }
    }
}
