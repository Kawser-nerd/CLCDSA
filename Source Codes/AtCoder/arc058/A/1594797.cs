using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program
{
    private int N,K;
    private bool[]D=new bool[10];
    private void Scan()
    {
        var l=Console.ReadLine().Split(' ');
        N=int.Parse(l[0]);
        K=int.Parse(l[1]);
        l=Console.ReadLine().Split();
        foreach(var i in l)
        {
            D[int.Parse(i)]=true;
        }
        
    }
    
    private bool Y(int n)
    {
        var s=n.ToString();
        foreach(var c in s)
        {
            if(D[c-'0'])return false;
        }
        return true;
    }
    
    public void Solve()
    {
        Scan();
        for(int i=N;true;i++)
        {
            if(Y(i))
            {
                Console.WriteLine(i);
                return;
            }
        }
    } 
    
    static void Main()
    {
        new Program().Solve();
    }
}