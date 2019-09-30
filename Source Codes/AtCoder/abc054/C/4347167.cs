using System;
using System.Collections.Generic;
using System.Linq;
//using System.Numerics;
class Program
{     
    static int AllPathThroughCount(List<int>[] node, int index, bool[] through)
    {
        if(through[index])
            return 0;
        through[index] = true;
        if(through.All(x => x))
        {
            through[index] = false;
            return 1;
        }
        int total = node[index]
            .Where(x => !through[x])
            .Select(x => AllPathThroughCount(node, x, through))
            .Sum();
        through[index] = false;
        return total;
    }
    public void Slove()
    {
        var inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        int m = int.Parse(inputs[1]);
        var node = 
            Enumerable.Range(0, n)
            .Select(x => new List<int>())
            .ToArray();
        foreach(int i in Enumerable.Range(0, m))
        {
            inputs = Console.ReadLine().Split();
            int a = int.Parse(inputs[0]) - 1;
            int b = int.Parse(inputs[1]) - 1;
            node[a].Add(b);
            node[b].Add(a);
        }
        int result = AllPathThroughCount(node, 0, new bool[n]);
        System.Console.WriteLine(result);        
    }
    
    static void Main(string[] args)
    {
        new Program().Slove();
    }
}