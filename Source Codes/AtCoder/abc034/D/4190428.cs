using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

class Build
{
    int h;
    int w;
    int r;
    int c;
    static int idGen = 1;
    public int Id { get;}
    public int Height { get { return h;} }
    public int Width { get { return w;} }
    public int DoorR { get { return r;} }
    public int DoorC { get { return c;} }
    public Build(string[] args)
    {
        h = int.Parse(args[0]);
        w = int.Parse(args[1]);
        r = int.Parse(args[2]) - 1;
        c = int.Parse(args[3]) - 1;
        Id = idGen++;
    }
}

class Program
{
    const int MOD = 1000000007;
    public void Slove()
    {    
        var inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        int k = int.Parse(inputs[1]);
        var items =
            Enumerable.Range(0, n)
            .Select(x => Console.ReadLine().Split())
            .Select((x, index) => new
            { 
                W = int.Parse(x[0]), 
                S = (double)int.Parse(x[0])/ 100 * int.Parse(x[1]),
                Per = int.Parse(x[1]), 
                Id = index
            })
            .ToArray();
        bool[] chk = new bool[n];
        double result = 0;
        long  resultW = 0;
        foreach(int i in Enumerable.Range(0, k))
        {
            double max = 0;
            int maxId = 0;
            double resultS = result / 100 * resultW;
            foreach(var item in items.Where(x => !chk[x.Id]))
            {
                double newPer = (resultS + item.S) / (resultW + item.W) * 100;
                if(max < newPer)
                {
                    max = newPer;
                    maxId = item.Id;
                }
            }
            chk[maxId] = true;
            result = max;
            resultW += items[maxId].W;
            //Console.WriteLine(result);
        }
        Console.WriteLine(result);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}