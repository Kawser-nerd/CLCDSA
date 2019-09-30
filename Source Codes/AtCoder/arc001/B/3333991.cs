using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC001_A
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();

            int now = int.Parse(input.Split(' ')[0]);
            int goal = int.Parse(input.Split(' ')[1]);

            int diff = Math.Abs(now - goal);
            int opeCount = 0;
            for (; diff != 0; opeCount++)
            {
                if (diff % 10 > 7)
                {
                    // +1?+2??10??????????
                    opeCount += (10 - (diff % 10));
                    diff += (10 - (diff % 10));
                    diff -= 10;
                }
                else if (diff % 5 > 2)
                {
                    // +1?+2??5??????????
                    opeCount += (5 - (diff % 5));
                    diff += (5 - (diff % 5));
                    diff -= 5;
                }
                else if (diff >= 10)
                    // 10????10??
                    diff -= 10;
                else if (diff >= 5)
                    // 5???5??
                    diff -= 5;
                else
                    // 5????1??
                    diff--;
            }

            Console.WriteLine("{0}", opeCount);
        }
    }
}