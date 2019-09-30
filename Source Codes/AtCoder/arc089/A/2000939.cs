using System;

class MainClass
{
    public static void Main(string[] args)
    {
        long N = long.Parse(Console.ReadLine());
        long[] t = new long[N];
        long[] x = new long[N];
        long[] y = new long[N];

        for (int i = 0; i < N;i++)
        {
            string[] s = Console.ReadLine().Split(' ');

            t[i] = int.Parse(s[0]);
            x[i] = int.Parse(s[1]);
            y[i] = int.Parse(s[2]);
        }

        if (((x[0] + y[0]) > t[0]) || (t[0] - x[0]-y[0]) % 2 == 1)
        {
            Console.WriteLine("No");
            return;
        }

        for (int i = 1; i < N; i++)
        {
            long time = t[i] - t[i - 1];
            long delta = (x[i] - x[i - 1]) + (y[i] - y[i - 1]);

            if((delta > time)||(time-delta) %2 == 1)
            {
                Console.WriteLine("No");
                return;
            }

        }

        Console.WriteLine("Yes");
        return;

    }
}