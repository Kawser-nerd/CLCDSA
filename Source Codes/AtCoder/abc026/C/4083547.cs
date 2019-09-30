using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;


class Program
{ 
    static int Get(int id, int[][] children)
    {
        if(!children[id].Any())
            return 1;
        int[] m = children[id].Select(x => Get(x, children)).ToArray();
        return m.Max() + m.Min() + 1;
    }
    public void Slove()
    {
        int n = int.Parse(Console.ReadLine());
        var children =
            Enumerable.Range(0, n - 1)
            .Select(x => Console.ReadLine())
            .Select(int.Parse)
            .Select(x => x - 1)
            .Select((parent, index) => new { parent, index = index + 1})
            .GroupBy(x => x.parent)
            .Aggregate(new int[n][].Select(x => new int[0]).ToArray(), (ret, x) => 
            {
                ret[x.Key] = x.Select(y => y.index).ToArray();
                return ret;
            }
            );
        var money = Get(0, children);
        Console.WriteLine(money);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}