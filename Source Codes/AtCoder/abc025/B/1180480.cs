using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace abc_025_B
{
    class Program
    {
        static void Main(string[] args)
        { int basho = 0;
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            for(int i = 0; i < a[0]; i++)
            {
                string[] y = Console.ReadLine().Split();
                int s = int.Parse(y[1]);
                // int hikitasumono = s;
                if (s < a[1]) { s = a[1]; }
                if (s > a[2]) { s = a[2]; }
                if (y[0] == "West") { basho -= s; }
                else if (y[0] == "East") { basho += s; }
                
            }
            if (basho > 0) { Console.WriteLine("East "+basho); }
            else if (basho < 0) { Console.WriteLine("West "+(basho)*(-1)); }
            else { Console.WriteLine("0"); }
        }
    }
}