using System;
using System.Collections.Generic;
using System.Linq;
//using System.Numerics;
class Program
{       
    public void Slove()
    {
        int n = int.Parse(Console.ReadLine());
        int[] array = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int odd = array.Count(x => (x & 1) == 1);
        if(odd % 2 == 0)
        {
            System.Console.WriteLine("YES");
        }
        else
        {
            System.Console.WriteLine("NO");
        }

    }
    
    static void Main(string[] args)
    {
        new Program().Slove();
    }
}