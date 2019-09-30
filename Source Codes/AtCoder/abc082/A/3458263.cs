using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            var ans = 0;
            if ((input[0] + input[1]) % 2 == 0)
            {
                ans = (input[0] + input[1]) / 2;
            }else
            {
                ans = (input[0] + input[1]) / 2 + 1;
            }

            Console.WriteLine(ans);
        }
    }
}