using System;

class ABC121_C
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(' ');
        int N = int.Parse(input[0]);
        int M = int.Parse(input[1]);

        Pair[] p = new Pair[N];

        for (int i = 0; i < N; i++)
        {
            input = Console.ReadLine().Split(' ');
            p[i] = new Pair();
            p[i].A = long.Parse(input[0]);
            p[i].B = int.Parse(input[1]);
        }

        Array.Sort(p);

        long sum = 0;
        int count = 0;

        for (int i = 0; i < N; i++)
        {
            int buy = Math.Min(p[i].B, M - count);

            sum += p[i].A * buy;
            count += buy;

            if (count >= M) break;
        }

        Console.WriteLine(sum);
    }

    class Pair : IComparable
    {
        public long A;
        public int B;

        public int CompareTo(object x)
        {
            return this.A.CompareTo(((Pair)x).A);
        }
    }
}