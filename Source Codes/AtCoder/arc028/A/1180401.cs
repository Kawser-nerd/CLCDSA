using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc028_A
{
    class Program
    {
        static void Main(string[] args)
        {
            ulong[] a = Console.ReadLine().Split().Select(ulong.Parse).ToArray();
            ulong s = a[0] % (a[1] + a[2]);
            if (s == 0) { Console.WriteLine("Bug"); }
            else if (s <= a[1]) { Console.WriteLine("Ant"); }
            else { Console.WriteLine("Bug"); }
        }
    }
}