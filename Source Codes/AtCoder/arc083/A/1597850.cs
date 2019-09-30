using System;
using System.Collections.Generic;
using System.Linq;

public struct State
{
    public int Water;
    public int Sugar;
    public int Weight { get { return Water + Sugar; } }
    public double Density
    {
        get
        {
            if (Weight == 0)
            {
                return -1;
            }
            return Sugar * 100 / (double)Weight;
        }
    }

    public State(int w, int s)
    {
        Water = w;
        Sugar = s;
    }
}

class Solution
{
    static void Main()
    {
        var vals = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var a = vals[0] * 100;
        var b = vals[1] * 100;
        var c = vals[2];
        var d = vals[3];
        var e = vals[4];
        var f = vals[5];

        var visited = new HashSet<State>();
        var currents = new HashSet<State>() { new State(0, 0) };
        var best = currents.First();

        while (currents.Count > 0)
        {
            var nexts = new HashSet<State>();
            foreach (var cur in currents)
            {
                if (cur.Density > best.Density)
                {
                    best = cur;
                }

                if (cur.Weight + a <= f)
                {
                    nexts.Add(new State(cur.Water + a, cur.Sugar));
                }
                if (cur.Weight + b <= f)
                {
                    nexts.Add(new State(cur.Water + b, cur.Sugar));
                }
                if (cur.Weight + c <= f && (cur.Sugar + c) * 100 <= e * cur.Water)
                {
                    nexts.Add(new State(cur.Water, cur.Sugar + c));
                }
                if (cur.Weight + d <= f && (cur.Sugar + d) * 100 <= e * cur.Water)
                {
                    nexts.Add(new State(cur.Water, cur.Sugar + d));
                }
            }
            currents = nexts;
        }

        Console.WriteLine($"{best.Weight} {best.Sugar}");
    }
}