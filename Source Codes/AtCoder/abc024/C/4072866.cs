using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;


class Program
{ 
    public void Slove()
    {
        string[] inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        int d = int.Parse(inputs[1]);
        int k = int.Parse(inputs[2]);
        int[][] limit =
            Enumerable.Range(0, d)
            .Select(x => Console.ReadLine().Split().Select(int.Parse).ToArray())
            .ToArray();
        int[][] people =
            Enumerable.Range(0, k)
            .Select(x => Console.ReadLine().Split().Select(int.Parse).ToArray())
            .ToArray();
        foreach(int[] p in people)
        {
            int count = 0;
            if(p[0] < p[1])
            {
                foreach(int[] l in limit)
                {
                    if(p[0] >= p[1])
                        break;
                    if(l[0] <= p[0] && l[1] >= p[0])
                        p[0] = l[1];
                    count++;
                }
            }
            else
            {
                foreach(int[] l in limit)
                {
                    if(p[0] <= p[1])
                        break;
                    if(l[0] <= p[0] && l[1] >= p[0])
                        p[0] = l[0];
                    count++;
                }
            }
            Console.WriteLine(count);
        }
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}