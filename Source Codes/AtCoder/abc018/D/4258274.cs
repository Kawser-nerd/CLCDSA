using System;
using System.Collections.Generic;
using System.Linq;

struct Chocolate //??????
{
    public int x;
    public int y;
    public int z;

    public Chocolate(int x, int y, int z)
    {
        this.x = x;
        this.y = y;
        this.z = z;
    }
}

class Program
{
    private static int n;
    private static int m;
    private static int p;
    private static int q;
    private static int r;
    private static List<Chocolate> c;

    public static void Main()
    {
        //???????
        int[] inputs = Console.ReadLine().Split().Select(int.Parse).ToArray();
        n = inputs[0];
        m = inputs[1];
        p = inputs[2];
        q = inputs[3];
        r = inputs[4];
        c = new List<Chocolate>();
        for (int i = 0; i < r; i++)
        {
            inputs = Console.ReadLine().Split().Select(int.Parse).ToArray();
            c.Add(new Chocolate(inputs[0], inputs[1], inputs[2]));
        }

        //?????
        int ans = 0;
        for (long f = 1; f < (long)Math.Pow(2, n); f++)
        {
            int c = 0;
            for (int i = 0; i < n; i++)
                c += (int)(f >> i & 1);
            if (c != p)
                continue;
            ans = Math.Max(ans, Happiness(f));
        }

        //?????
        Console.WriteLine(ans);
    }

    //??p???????????????q???????????
    private static int Happiness(long f)
    {
        //???????????????????????????
        int[] happiness = new int[m];
        foreach (var choco in c)
        {
            if ((f >> (choco.x - 1) & 1) == 0) //choco.x?????????????
                continue;
            happiness[choco.y - 1] += choco.z;
        }

        //??????????
        Array.Sort(happiness);
        Array.Reverse(happiness);

        //???????????q??????
        int v = 0;
        for (int i = 0; i < q; i++)
            v += happiness[i];
        return v;
    }
}