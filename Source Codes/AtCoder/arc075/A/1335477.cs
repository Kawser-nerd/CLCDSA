using System;
using System.Linq;
class Program
{
    static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        int[] s = new int[N];
        for (int i = 0; i < N; i++)
        {
            s[i] = int.Parse(Console.ReadLine());
        }
        int score = s.Sum();
        if (score % 10 == 0)
        {
            if (s.Any(x => x % 10 != 0))
            {
                score -= s.Where(x => x % 10 != 0).Min();
            }
            else
            {
                score = 0;
            }
        }
        Console.WriteLine(score);
    }
}