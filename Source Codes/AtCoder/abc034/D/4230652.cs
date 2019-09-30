using System;
using System.Linq;
class Program
{
    private static int n;
    private static int k;
    private static int[] w;
    private static int[] p;

    public static void Main()
    {
        //???????
        int[] inputs = Console.ReadLine().Split().Select(int.Parse).ToArray();
        n = inputs[0];
        k = inputs[1];
        w = new int[n];
        p = new int[n];
        for (int i = 0; i < n; i++)
        {
            inputs = Console.ReadLine().Split().Select(int.Parse).ToArray();
            w[i] = inputs[0];
            p[i] = inputs[1];
        }
        //?????????
        Console.WriteLine(Solve());
    }

    //c%?????????????
    private static bool Judge(double c)
    {
        //??????????g????????????
        double[] dis = new double[n];
        for (int i = 0; i < n; i++)
            dis[i] = (p[i] - c) * w[i];
        //??????????
        Array.Sort(dis);
        //???????????k????0???????
        double g = 0.0;
        for (int i = n - 1; i >= n - k; i--)
            g += dis[i];
        return g >= 0.0;
    }

    //?????????????
    private static double Solve()
    {
        double l = 0.0; //??
        double r = p.Max(); //??
        while (r - l > 1e-13) //l?r??????????
        {
            double m = (l + r) / 2.0;
            if (Judge(m))
                l = m;
            else
                r = m;
        }
        return r;
    }
}