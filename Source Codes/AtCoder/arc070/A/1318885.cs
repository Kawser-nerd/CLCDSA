using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder070_C_GoHome
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputFirstLine = long.Parse(Console.ReadLine());

            GoHome goHome = new GoHome();
            Console.WriteLine(goHome.GetEarliestTime(inputFirstLine));

            //Console.ReadKey();
        }
    }

    class GoHome
    {
        public long GetEarliestTime(long position)
        {
            long sum = 0, time = 1;
            for (; sum < position; time++)
            {
                sum += time;
            }

            return time - 1;
        }
    }
}