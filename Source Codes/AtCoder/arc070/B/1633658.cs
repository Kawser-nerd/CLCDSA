using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    private int N,K;
    private int[] A;
    
    private void Scan()
    {
        var l=Console.ReadLine().Split(' ');
        N=int.Parse(l[0]);
        K=int.Parse(l[1]);
        A=Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    }
    
    private bool Check(int n)
    {
        var dp=new bool[K+1];
        dp[0]=true;
        for(int i=0;i<N;i++)
        {
            if(i==n)continue;
            for(int j=K;j>=0;j--)
            {
                if((dp[j])&&(j+A[i]<=K))
                {
                    dp[j+A[i]]=true;
                }
            }
        }
        for(int i=Math.Max(K-A[n],0);i<K;i++)
        {
            if(dp[i])return true;
        }
        return false;
    }
    
    private int Calc()
    {
        int ok=N;
        int ng=-1;
        while(ok-ng>1)
        {
            int mid=(ok+ng)/2;
            if(Check(mid))
            {
                ok=mid;
            }
            else
            {
                ng=mid;
            }
        }
        return ng+1;
    }
    
    public void Solve()
    {
        Scan();
        Array.Sort(A);
        Console.WriteLine(Calc());
    }
    
    static void Main()
    {
        new Program().Solve();
    }
}