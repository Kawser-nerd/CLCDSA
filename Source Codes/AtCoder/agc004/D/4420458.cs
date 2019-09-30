using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
class Program
{       
    static void MakeDepth(int[] depth, int index, int dtemp, List<int>[] children, int maxDepth)
    {
        // depth[index] = dtemp;
        // foreach(int i in children[index])
        // {
        //     MakeDepth(depth, i, dtemp + 1, children);
        // }
        var que = new Queue<int>();
        que.Enqueue(index);
        int count = dtemp;
        while(que.Any() && maxDepth >= count)
        {
            int queCount = que.Count;
            foreach(int i in Enumerable.Range(0, queCount))
            {
                int p = que.Dequeue();
                depth[p] = count;
                foreach(int child in children[p])
                    que.Enqueue(child);
            }
            count++;
        }
    }
    static int GetParent(int[] parents, int index, int depth)
    {
        // if(depth == 0)
        //     return index;
        // return GetParent(parents, parents[index], depth - 1);
        while(depth > 0)
        {
            index = parents[index];
            depth--;
        }
        return index;
    }
    public void Slove()
    {
        var inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        int k = int.Parse(inputs[1]);
        var children =
            Enumerable.Range(0, n)
            .Select(x => new List<int>())
            .ToArray();
        var parents = Console.ReadLine().Split().Select(x => int.Parse(x) - 1).ToArray();
        int result = 0;
        if(parents[0] != 0)
        {
            parents[0] = 0;
            result++;
        }
        foreach(var item in parents.Select((x, i) => new {Parent = x, Child = i}).Skip(1))
        {
            children[item.Parent].Add(item.Child); 
        }
        int[] depth = new int[n];
        MakeDepth(depth, 0, 0, children, n);
        foreach(int i in Enumerable.Range(0, n).OrderByDescending(x => depth[x]))
        {
            if(depth[i] > k)
            {
                int parent = GetParent(parents, i, k - 1);
                MakeDepth(depth, parent, 1, children, k);
                result++;
            }
        }
        System.Console.WriteLine(result);
    }
    
    static void Main(string[] args)
    {
        new Program().Slove();
    }
}