using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016_0_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var s = Console.ReadLine();
                int flips = s.Last() == '+' ? 0 : 1;
                for (int i = 0; i < s.Length - 1; i++)
                    if (s[i] != s[i + 1])
                        flips++;
                Console.WriteLine("Case #{0}: {1}", testN, flips);
            }
        }
    }
}
