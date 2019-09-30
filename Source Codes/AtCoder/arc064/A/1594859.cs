using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program
{
    private int N,X;
    private int[]A;
    private void Scan()
    {
        var l=Console.ReadLine().Split(' ');
        N=int.Parse(l[0]);
        X=int.Parse(l[1]);
        l=Console.ReadLine().Split();
    
        A=new int[N];
        for(int i=0;i<N;i++)
        {
            A[i]=int.Parse(l[i]);
        }
    }
    
    
    public void Solve()
    {
        Scan();
        long ans=0;
        for(int i=1;i<N;i++)
        {
            int sum=A[i]+A[i-1];
            if(sum>X)
            {
                    ans+=(sum-X);
                    A[i]=Math.Max(0,A[i]-(sum-X));
                
            }
        }
        Console.WriteLine(ans);
    } 
    
    static void Main()
    {
        new Program().Solve();
    }
}