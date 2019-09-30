using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static int N;
    static List<int> Precisions;
    static Dictionary<int, int> Factors;

    public static void Main(string[] args)
    {
        N = Input.NextInt();

        MakePrecisions();

        Factors = new Dictionary<int, int>();
        Factors = new Dictionary<int, int>();
        foreach (var n in Precisions)
        {
            Factors[n] = 0;
        }
        for (int i = 2; i <= N; i++)
        {
            var number = i;
            foreach (var n in Precisions)
            {
                if (n > number)
                    break;
                while ((number % n) == 0)
                {
                    Factors[n] += 1;
                    number = number / n;
                }
            }
        }

        {
            int n = 0;
            for (int i = 0; i < Factors.Count - 2; i++)
            {
                for (int j = i + 1; j < Factors.Count - 1; j++)
                {
                    for (int k = j + 1; k < Factors.Count; k++)
                    {
                        // i:2
                        if (Factors.ElementAt(i).Value >= 2 && Factors.ElementAt(j).Value >= 4 && Factors.ElementAt(k).Value >= 4)
                        {
                            n += 1;
                        }
                        // j:2
                        if (Factors.ElementAt(i).Value >= 4 && Factors.ElementAt(j).Value >= 2 && Factors.ElementAt(k).Value >= 4)
                        {
                            n += 1;
                        }
                        // k:2
                        if (Factors.ElementAt(i).Value >= 4 && Factors.ElementAt(j).Value >= 4 && Factors.ElementAt(k).Value >= 2)
                        {
                            n += 1;
                        }
                    }
                }
            }
            for (int j = 0; j < Factors.Count - 1; j++)
            {
                for (int k = j + 1; k < Factors.Count; k++)
                {
                    if (Factors.ElementAt(j).Value >= 2 && Factors.ElementAt(k).Value >= 24)
                    {
                        n += 1;
                    }
                    if (Factors.ElementAt(k).Value >= 2 && Factors.ElementAt(j).Value >= 24)
                    {
                        n += 1;
                    }
                }
            }
            for (int j = 0; j < Factors.Count - 1; j++)
            {
                for (int k = j + 1; k < Factors.Count; k++)
                {
                    if (Factors.ElementAt(j).Value >= 4 && Factors.ElementAt(k).Value >= 14)
                    {
                        n += 1;
                    }
                    if (Factors.ElementAt(k).Value >= 4 && Factors.ElementAt(j).Value >= 14)
                    {
                        n += 1;
                    }
                }
            }
            for (int k = 0; k < Factors.Count; k++)
            {
                if (Factors.ElementAt(k).Value >= 74)
                {
                    n += 1;
                }
            }
            Console.WriteLine(n);
        }
    }

    private static void MakePrecisions()
    {
        Precisions = new List<int>();
        Precisions.Add(2);
        for (int i = 3; i <= N; i++)
        {
            foreach (var a in Precisions)
            {
                if ((i % a) == 0)
                    goto continue_next_i;
            }
            Precisions.Add(i);
        continue_next_i:
            ;
        }
    }
}

public static class Input
{
    private static Queue<string> q = new Queue<string>();
    private static void Confirm() { if (q.Count == 0) foreach (var s in Console.ReadLine().Split(' ')) q.Enqueue(s); }
    public static int NextInt() { Confirm(); return int.Parse(q.Dequeue()); }
    public static long NextLong() { Confirm(); return long.Parse(q.Dequeue()); }
    public static string NextString() { Confirm(); return q.Dequeue(); }
    public static double NextDouble() { Confirm(); return double.Parse(q.Dequeue()); }
    public static int[] LineInt() { return Console.ReadLine().Split(' ').Select(int.Parse).ToArray(); }
    public static long[] LineLong() { return Console.ReadLine().Split(' ').Select(long.Parse).ToArray(); }
    public static string[] LineString() { return Console.ReadLine().Split(' ').ToArray(); }
    public static double[] LineDouble() { return Console.ReadLine().Split(' ').Select(double.Parse).ToArray(); }
}