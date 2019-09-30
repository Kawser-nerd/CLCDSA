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
    private long N;
    public void Solve()
    {
        N = long.Parse(Console.ReadLine());
        if (N == 1)
        {
            Console.WriteLine("Deficient");
            return;
        }
        long sum = 1;
        for (long i = 2; i * i <= N; i++)
        {
            if (N % i == 0)
            {
                sum += i;
                if (N / i != i)
                {
                    sum += N / i;
                }
            }
        }

        switch (N.CompareTo(sum))
        {
            case -1:
                Console.WriteLine("Abundant");
                break;
            case 1:
                Console.WriteLine("Deficient");
                break;
            case 0:
                Console.WriteLine("Perfect");
                break;
        }
    }
}