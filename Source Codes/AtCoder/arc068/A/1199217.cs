using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc_068_A
{
    class Program
    {
        static void Main(string[] args)
        {
            ulong a = ulong.Parse(Console.ReadLine());
            ulong ans = (a / (int)11) * 2;
            ulong s = a % 11;
            if (s > 6) { ans += 2; }
            else if (s > 0) { ans += 1; }
            Console.WriteLine(ans);Console.ReadLine();
           
        }
    }
}