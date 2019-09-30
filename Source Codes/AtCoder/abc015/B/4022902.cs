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
        int[] bugCount = 
            Console.ReadLine().Split()
            .Select(int.Parse)
            .Where(x => x != 0)
            .ToArray();
        int sum = bugCount.Sum();
        int average = sum / bugCount.Length + (sum % bugCount.Length == 0 ? 0 : 1);
        Console.WriteLine(average);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}