using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    public Program()
    {
        string[] inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        int m = int.Parse(inputs[1]);
        if(n * 4 < m || n * 2 > m)
        {
            Console.WriteLine("-1 -1 -1");
        }
        else
        {
            int r = m - 3 * n;
            if(r == 0)
            {
                Console.WriteLine($"0 {n} 0");
            }
            else if(r > 0)
            {
                Console.WriteLine($"0 {n - r} {r}");
            }
            else
            {
                Console.WriteLine($"{-r} {n + r} 0");
            }
        }
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}