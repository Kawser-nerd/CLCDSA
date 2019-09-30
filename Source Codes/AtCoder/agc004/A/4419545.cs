using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
class Program
{   
    
    public void Slove()
    {
        var inputs = Console.ReadLine().Split().Select(int.Parse).ToArray();
        if(inputs.Any(x => (x & 1) == 0))
        {
            Console.WriteLine(0);
        }
        else
        {
            long min = new long[]
            {
                (long)inputs[0] * inputs[1],
                (long)inputs[0] * inputs[2],
                (long)inputs[1] * inputs[2],
            }.Min();
            Console.WriteLine(min);
        }
    }
    
    static void Main(string[] args)
    {
        new Program().Slove();
    }
}