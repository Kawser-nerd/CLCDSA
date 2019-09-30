using System;
using System.Collections.Generic;
using System.Linq;

static class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

struct Box
{
    public int H, W;

    public Box(int h, int w)
    {
        H = h;
        W = w;
    }
}

class Magatro
{
    private int N;
    private Box[] Boxes;
    private int[] Bit;
    private int[] DP;

    private void Scan()
    {
        N = int.Parse(Console.ReadLine());
        Boxes = new Box[N];
        for (int i = 0; i < N; i++)
        {
            var line = Console.ReadLine().Split(' ');
            Boxes[i] = new Box(int.Parse(line[1]), int.Parse(line[0]));
        }
    }

    private int Max(int i)
    {
        if(i == 0)
        {
            return 0;
        }
        return Math.Max(Bit[i], Max(i - (i & -i)));
    }

    void Update(int i, int x)//bit[i]?x?
    {
        if (i > 100000) return;
        Bit[i] = Math.Max(Bit[i], x);
        Update(i + (i & -i), x);
    }

    public void Solve()
    {
        Scan();
        Array.Sort(Boxes, (a, b) =>
        {
            if (a.H == b.H)
            {
                return -a.W.CompareTo(b.W);
            }
            else
            {
                return a.H.CompareTo(b.H);
            }
        });
        Bit = new int[100001];
        DP = new int[N];
        for(int i = 0; i < N; i++)
        {
            DP[i] = Max(Boxes[i].W-1) + 1;
            Update(Boxes[i].W, DP[i]);
        }
        Console.WriteLine(DP.Max());
    }
}