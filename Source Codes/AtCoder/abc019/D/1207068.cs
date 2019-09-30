using System;

class Program
{
    static void Main(string[] args)
    {
        new Magatro().Solve();
    }
}

public class Magatro
{
    private int N;
    public void Solve()
    {
        N = int.Parse(Console.ReadLine());
        int fMax = -1;
        int f = -1; ;
        for (int i = 2; i <= N; i++)
        {
            Console.WriteLine($"? 1 {i}");
            int dist = int.Parse(Console.ReadLine());
            if (fMax < dist)
            {
                fMax = dist;
                f = i;
            }
        }
        int ans = fMax;
        for (int i = 2; i <= N; i++)
        {
            if (f == i) continue;
            Console.WriteLine($"? {f} {i}");
            ans = Math.Max(int.Parse(Console.ReadLine()), ans);
        }
        Console.WriteLine($"! {ans}");
    }
}