using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
class Program
{   
    
    public void Slove()
    {
        int n = int.Parse(Console.ReadLine());
        long result = 0;
        int rem = 0;
        foreach(int i in Enumerable.Range(0, n))
        {
            int count = int.Parse(Console.ReadLine());
            if(count == 0)
            {
                rem = 0;
                continue;
            }
            count += rem;
            result += count / 2;
            rem = count % 2;
        }
        System.Console.WriteLine(result);
    }
    
    static void Main(string[] args)
    {
        new Program().Slove();
    }
}