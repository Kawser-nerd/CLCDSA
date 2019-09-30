using System;
class Search
{
    public long[,,] GetMin(long[,] a)
    {
        int n = a.Length;
        n = (int)Math.Pow(n, 0.5);
        long[,,] b = new long[n - 1, n, n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                b[0, i, j] = a[i, j];
        for (int g = 0; g < n; g++)
        {
            for (int k = 1; k < n - 1; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    long min = long.MaxValue;
                    for (int i = 0; i < n; i++)
                    {
                        if (i != l && a[l, i] != -1 && b[k - 1, i, g] != -1)
                        {
                            min = Math.Min(min, a[l, i] + b[k - 1, i, g]);
                        }
                        if (b[k - 1, l, g] != -1)
                            b[k, l, g] = Math.Min(b[k - 1, l, g], min);
                        else if (min != long.MaxValue)
                            b[k, l, g] = min;
                        else
                            b[k, l, g] = -1;
                    }
                }
            }
        }
        return b; //b[k,l,g]?l????k????????g????????
    }
}
class Program
{
    public static void Main()
    {
        Search s = new Search();
        string[] str = Console.ReadLine().Split(' ');
        int h = int.Parse(str[0]);
        int w = int.Parse(str[1]);
        long[,] c = new long[10, 10];
        for (int i = 0; i < 10; i++)
        {
            str = Console.ReadLine().Split(' ');
            for (int j = 0; j < 10; j++)
                c[i, j] = long.Parse(str[j]);
        }
        long[,,] b = s.GetMin(c);
        long sum = 0;
        for (int i = 0; i < h; i++)
        {
            str = Console.ReadLine().Split(' ');
            for (int j = 0; j < w; j++)
                if (int.Parse(str[j]) != -1)
                    sum += b[8, int.Parse(str[j]), 1];
        }
        Console.WriteLine(sum);
    }
}