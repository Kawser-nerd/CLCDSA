using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
class Program
{    
    
    public void slove()
    {
        var inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        int l = int.Parse(inputs[1]);
        int[] rope = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int lastIndex;
        try{
            lastIndex = Enumerable.Range(0, n - 1).First(x => rope[x + 1] + rope[x] >= l);
        }
        catch(InvalidOperationException e){
            System.Console.WriteLine("Impossible");
            return;
        }
        int[] result = 
            Enumerable.Range(0, lastIndex)
            .Concat(Enumerable.Range(0, n - 1).Skip(lastIndex + 1).Reverse())
            .Concat(Enumerable.Range(lastIndex, 1))
            .Select(x => x + 1)
            .ToArray();
        System.Console.WriteLine("Possible");
        System.Console.WriteLine(string.Join("\n", result));
    }
    
    static void Main(string[] args)
    {
        new Program().slove();
    }
}