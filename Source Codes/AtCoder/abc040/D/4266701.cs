using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static int GetParent(int[] parents, int start)
    {
        if(parents[start] == start)
            return start;
        else
        {
            int parent = GetParent(parents, parents[start]);
            parents[start] = parent;
            return parent;
        }
    }
    public void slove()
    {
        var inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        int m = int.Parse(inputs[1]);
        var road =
            Enumerable.Range(0, m)
            .Select(y => 
                Console.ReadLine().Split()
                .Select(int.Parse)
                .ToArray())
            .Select(x => new {A = x[0] - 1, B = x[1] - 1, Y = x[2]})
            .OrderByDescending(x => x.Y)
            .ToArray();
        int[] parents = Enumerable.Range(0, n).ToArray();
        int[] connectCount = new int[n].Select(x => 1).ToArray();
        var q = int.Parse(Console.ReadLine());
        int[] result = new int[q];
        var people =
            Enumerable.Range(0, q)
            .Select(y => 
                Console.ReadLine().Split()
                .Select(int.Parse)
                .ToArray())
            .Select((x, i) => new {Index = i, Start = x[0] - 1, W = x[1]})
            .ToArray();
        int roadIndex = 0;
        foreach(var person in people.OrderByDescending(x => x.W))
        {
            while(roadIndex < road.Length && road[roadIndex].Y > person.W)
            {
                int parentA = GetParent(parents, road[roadIndex].A);
                int parentB = GetParent(parents, road[roadIndex].B);
                if(parentA != parentB)
                {
                    parents[parentB] = parentA;
                    connectCount[parentA] += connectCount[parentB];
                }
                roadIndex++;
            }
            result[person.Index] = connectCount[GetParent(parents, person.Start)];
        }
        System.Console.WriteLine(string.Join("\n", result));
    }
    static void Main(string[] args)
    {
        new Program().slove();
    }
}