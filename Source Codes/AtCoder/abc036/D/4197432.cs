using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

class Program
{
    const int MOD = 1000000007;
    static long[] GetPattern(bool[] chk, List<int>[] node, int index)
    {
        long[] ret = Enumerable.Range(0, 2).Select(x => 1L).ToArray();
        int[] next = node[index].Where(x => !chk[x]).ToArray();
        chk[index] = true;
        foreach(int i in next)
        {
            long[] childP = GetPattern(chk, node, i);
            ret[0] *= childP.Sum();
            ret[1] *= childP[0];
            if(ret[0] >= MOD)
                ret[0] %= MOD;
            if(ret[1] >= MOD)
                ret[1] %= MOD;
        }

        return ret;
    }
    public void Slove()
    {   
        int n = int.Parse(Console.ReadLine());
        var node = 
            Enumerable.Range(0, n)
            .Select(x => new List<int>())
            .ToArray();
        foreach(int i in Enumerable.Range(0, n - 1))
        {
            string[] inputs = Console.ReadLine().Split();
            int a = int.Parse(inputs[0]) - 1;
            int b = int.Parse(inputs[1]) - 1;
            node[a].Add(b);
            node[b].Add(a);
        }
        long result = GetPattern(new bool[n], node, 0).Sum() % MOD;
        Console.WriteLine(result);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}