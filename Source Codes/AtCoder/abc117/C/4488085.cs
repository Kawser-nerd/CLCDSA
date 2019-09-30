using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using E = System.Linq.Enumerable;
class Program
{
    static void Main(string[] args)
    {
        string[] temp = System.Console.ReadLine().Split(' ');
        int N = int.Parse(temp[0]);
        int M = int.Parse(temp[1]);
        string[] temp1 = System.Console.ReadLine().Split(' ');
        int[] target = new int[M];
        for (int i = 0; i < M; i++)
        {
            target[i] = int.Parse(temp1[i]);
        }
        Array.Sort(target);
        int[] distance = new int[target.Length];
        for (int i = 1; i < target.Length; i++)
        {
            distance[i] = target[i] - target[i - 1];
        }
        var dsDesc = E.Range(0, distance.Length).ToArray();
        Array.Sort(distance.ToArray(), dsDesc);
        Array.Reverse(dsDesc);

        var k = target.Last() - target.First() - dsDesc.Take(N - 1).Sum(x => distance[x]);
        Console.WriteLine(k);
    }
}