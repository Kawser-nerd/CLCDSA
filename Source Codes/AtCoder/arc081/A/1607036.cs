using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program
{
    private int N;
    private int[]A;
    private void Scan()
    {
        N=int.Parse(Console.ReadLine());
        A=new int[N];
        var l=Console.ReadLine().Split(' ');
        for(int i=0;i<N;i++)
        {
            {
                A[i]=int.Parse(l[i]);
            }
        }
    }
    
    
    
    public void Solve()
    {
        Scan();
        Array.Sort(A,(a,b)=>-a.CompareTo(b));
        int q=0;
        int cnt=0;
        int[] ans=new int[2];
        int j=0;
        foreach(int i in A)
        {
            if(q!=i)
            {
                q=i;
                cnt=1;
            }
            else
            {
                cnt++;
                if(cnt==2)
                {
                    if(j<2)
                    {
                        ans[j]=i;
                        j++;
                    }
                 
                    cnt=0;   
                }
            }
        }
        Console.WriteLine((long)ans[0]*ans[1]);
        
    } 
    
    static void Main()
    {
        new Program().Solve();
    }
}