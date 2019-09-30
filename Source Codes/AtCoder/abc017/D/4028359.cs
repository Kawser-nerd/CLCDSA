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

        int[] supplement =
            Enumerable.Range(0, n)
            .Select(x => int.Parse(Console.ReadLine()))
            .ToArray();

        long[] pattern = new long[n + 1];
        long[] cSum = new long[n + 1];
        pattern[0] = 1;
        cSum[0] = 1;
        bool[] chk = new bool[m + 1];
        int start = 0;
        foreach(int i in Enumerable.Range(1, n))
        {     
            while(chk[supplement[i - 1]])
            {
                start++;
                chk[supplement[start - 1]] = false;
            }
            chk[supplement[i - 1]] = true;
            pattern[i] = cSum[i - 1];
            if(start != 0)
                pattern[i] -= cSum[start - 1];
            if(pattern[i] >= 1000000007)
                pattern[i] %= 1000000007;
            cSum[i] = cSum[i - 1] + pattern[i];
        }
        
        //Console.WriteLine(string.Join(",",supplement));
        //Console.WriteLine(string.Join(",",pattern));
        Console.WriteLine(pattern[n]);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}