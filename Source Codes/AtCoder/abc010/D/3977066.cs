using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    static bool DinicSub(bool[] used, int next, bool[][] node, int end)
    {
        if(next == end)
            return true;
        used[next] = true;
        foreach(int i in node.Select((x , i) => i)
            .Where(i => !used[i] && node[next][i]))
        {
            bool ret = DinicSub(used, i, node, end);
            if(ret)
            {
                if(node[i][next])
                {
                    node[next][i] = false;
                }
                else
                {
                    node[i][next] = true;
                }
                return true;
            }
        }
        //used[next] = false;
        return false;
    }
    static int Dinic(bool[][] node, int[] start, int end)
    {
        return start.Count(x => DinicSub(new bool[node.Length], x, node, end));
    }
    public void Slove()
    {
        string[] inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        int g = int.Parse(inputs[1]);
        if(g == 0)
        {
            Console.WriteLine(0);
            return ;
        }
        int e = int.Parse(inputs[2]);
        int[] targetId = Console.ReadLine().Split().Select(int.Parse).ToArray();
        var conect =
            Enumerable.Range(0, n)
            .Select(x => new bool[n])
            .ToArray();
        foreach(int i in Enumerable.Range(0, e))
        {
            inputs = Console.ReadLine().Split();
            int a = int.Parse(inputs[0]);
            int b = int.Parse(inputs[1]);
            conect[a][b] = true;
            conect[b][a] = true;
        }
        Console.WriteLine(Dinic(conect, targetId, 0));
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}