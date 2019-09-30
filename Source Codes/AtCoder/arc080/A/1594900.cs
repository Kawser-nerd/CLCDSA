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
        var l=Console.ReadLine().Split(' ');
        N=int.Parse(l[0]);
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
        int one=0,two=0,four=0;
        foreach(int i in A)
        {
            if(i%4==0)
            {
                four++;
            }
            else if(i%2==0)
            {
                two++;
            }
            else
            {
                one++;
            }
        }
        bool ans;
        if(two==0)
        {
            ans=four+1>=one;
            if(four==0)
            {
                ans=false;
            }
        }
        else
        {
            ans=four>=one;
        }
        Console.WriteLine(ans?"Yes":"No");
    } 
    
    static void Main()
    {
        new Program().Solve();
    }
}