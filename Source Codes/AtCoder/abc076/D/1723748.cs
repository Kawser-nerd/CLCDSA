using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;
using System.IO;
using System.Diagnostics;

class Scanner
{
    private readonly char Separator = ' ';
    private int Index = 0;
    private string[] Line = new string[0];
    public string Next()
    {
        if (Index >= Line.Length)
        {
            Line = Console.ReadLine().Split(Separator);
            Index = 0;
        }
        var ret = Line[Index];
        Index++;
        return ret;
    }

    public int NextInt()
    {
        return int.Parse(Next());
    }

}

class Magatro
{
    private int N;
    private int[] T,V;
    private void Scan()
    {
        var sc=new Scanner();
        N=sc.NextInt();
        T=new int[N+1];
        V=new int[N+1];
        for(int i=0;i<N;i++)
        {
            T[i]=sc.NextInt();
        }
        for(int i=0;i<N;i++)
        {
            V[i]=sc.NextInt();
        }
    }
    
    private double Func(int max,int from,int to,int time)
    {
        if(from>max||to>max)
        {
            return -1;
        }
        double res=0;
        double y=(double)(from+to+time)/2;
        double x=y-from;
        if(0>x||x>time)
        {
            return -1;
        }
        res+=(from+y)*x/2;
        res+=(to+y)*(time-x)/2;
        if(max<y)
        {
            res-=(y-max)*(y-max);
        }
        return res;
    }

    public void Solve()
    {
        Scan();
        var dp=new double[101];
        for(int i=0;i<N;i++)
        {
            var next=new double[101];
            for(int j=0;j<=100;j++)
            {
                next[j]=-1;
            }
            if(i==0)
            {
                for(int to=0;to<=100;to++)
                {
                    var f=Func(V[i],0,to,T[i]);
                    next[to]=dp[0]+f;
                }
            }
            else
            {
                for(int from=0;from<=100;from++)
                {
                    for(int to=0;to<=100;to++)
                    {
                        var f=Func(V[i],from,to,T[i]);
                        if(f==-1||dp[from]==-1)continue;
                        next[to]=dp[from]+f;
                    }
                }
            }
            
            dp=next;
            //Console.WriteLine(string.Join(" ",dp));
        }
        Console.WriteLine(dp[0]);
    }

    static public void Main(string[]args)
    {
        new Magatro().Solve();
    }
}