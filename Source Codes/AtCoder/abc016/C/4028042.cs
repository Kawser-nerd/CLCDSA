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
        string[] inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        int m = int.Parse(inputs[1]);
        List<int>[] frends = Enumerable.Range(0, n).Select(x => new List<int>()).ToArray();
        foreach(int i in Enumerable.Range(0, m))
        {
            inputs = Console.ReadLine().Split();
            int a = int.Parse(inputs[0]) - 1;
            int b = int.Parse(inputs[1]) - 1;
            frends[a].Add(b);
            frends[b].Add(a);
        }
        var frendsFrends =
            frends
            .Select((x, i) => 
                x.SelectMany(y => frends[y])
                .Distinct()
                .Except(x)
                .Where(y => y != i))
            .Select(x => x.Count());
        Console.WriteLine( string.Join("\n", frendsFrends));
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}