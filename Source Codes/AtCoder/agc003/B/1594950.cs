using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program
{
    private int N;
    private int[]A;
    
    
    public void Solve()
    {
        N=int.Parse(Console.ReadLine());
        A=new int[N];
        for(int i=0;i<N;i++)
        {
            A[i]=int.Parse(Console.ReadLine());
            
        }
        
        long ans=0;
        long sum=0;
        
        for(int i=0;i<N;i++)
        {
            if(A[i]==0)
            {
                ans+=sum/2;
                sum=0;
            }
            else
            {
                sum+=A[i];
            }
        }
        ans+=sum/2;
        Console.WriteLine(ans);
    } 
    
    static void Main()
    {
        new Program().Solve();
    }
}