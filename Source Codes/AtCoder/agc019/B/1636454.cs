using System;

class Program
{
    static void Main(string[] args)
    {
        string s = Console.ReadLine();

        int[] charCounts = new int[256];
        foreach (char c in s)
        {
            int index = c - 'a';
            charCounts[index] += 1;
        }

        ulong pairs = 0;
        foreach (int x in charCounts)
        {
            if (x > 1)
            {
                pairs += (ulong)x * (ulong)(x - 1) / 2;
                Console.Error.WriteLine("Pairs is now {0} after x = {1}", pairs, x);
            }
        }

        ulong max = (ulong)s.Length * (ulong)(s.Length - 1) / 2;
        ulong answer = max - pairs + 1;

        Console.Error.WriteLine("max: {0}, pairs: {1}", max, pairs);

        Console.WriteLine(answer);
        Console.ReadLine();
    }
}