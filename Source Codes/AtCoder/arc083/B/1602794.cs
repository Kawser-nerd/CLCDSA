using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program
{
    private int N;
    private int[,]A;
    private void Scan()
    {
        N=int.Parse(Console.ReadLine());
        A=new int[N,N];
        for(int i=0;i<N;i++)
        {
            var l=Console.ReadLine().Split(' ');
            for(int j=0;j<N;j++)
            {
                A[i,j]=int.Parse(l[j]);
            }
        }
    }
    
    
    
    public void Solve()
    {
        Scan();
        var not=new bool[N,N];
        for(int k=0;k<N;k++)
        {
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    if(i==j||j==k||k==i)continue;
                    
                    if(A[i,j]==A[i,k]+A[k,j])
                    {
                        not[i,j]=true;
                    }
                    if(A[i,j]>A[i,k]+A[k,j])
                    {
                        Console.WriteLine(-1);
                        return;
                    }
                }
            }
        }
        long ans=0;
        for(int i=0;i<N-1;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                if(not[i,j])continue;
                ans+=A[i,j];
            }
        }
        Console.WriteLine(ans);
    } 
    
    static void Main()
    {
        new Program().Solve();
    }
}