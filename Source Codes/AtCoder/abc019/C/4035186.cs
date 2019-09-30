using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    public void Slove()
    {
        int n = int.Parse(Console.ReadLine());
        int result = 
            Console.ReadLine().Split()
            .Select(int.Parse)
            .Select(x => {while((x & 1) == 0 && x != 0) x >>= 1; return x; })
            .Distinct()
            .Count();

        Console.WriteLine(result);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}