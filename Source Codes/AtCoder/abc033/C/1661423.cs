using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int zeroCount = 0;
            var S = Console.ReadLine() + "+";
            var stack = new Stack<int>();


            bool hasZero=false;
            foreach (var c in S)
            {
                //0 igai suuji or kakezann musi
                if (c == '+')
                {
                    if (!hasZero)
                        zeroCount++;
                    hasZero = false;
                }
                else if (c == '0')
                {
                    hasZero = true;
                }
            }

            Console.WriteLine(zeroCount);
        }
    }
}