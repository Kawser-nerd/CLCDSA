using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            ulong t = ulong.Parse(Console.ReadLine());
            for (ulong i = 1; i <= t; ++i)
            {
                string s = Console.ReadLine() + "+";
                int f = 0;
                char state = s[0];
                foreach (var c in s)
                    if (state != c)
                    {
                        state = c;
                        f++;
                    }
                Console.WriteLine("Case #" + i + ": " + f);
            }
        }
    }
}
