using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class A
{
    static void Main()
    {
        int T = ReadInt();
        for (int t = 1; t <= T; t++)
        {
            int N = ReadInt();
            int[] L = ReadInts();
            int[] P = ReadInts();
            var q = from i in Enumerable.Range(0, N)
                    orderby P[i] descending, P[i] == 0 ? 0 : L[i], i
                    select i.ToString();
            Console.WriteLine("Case #{0}: {1}", t, string.Join(" ", q.ToArray()));
        }
    }

    static string ReadLine()
    {
        return Console.ReadLine();
    }

    static int ReadInt()
    {
        return int.Parse(ReadLine());
    }

    static string[] ReadWords()
    {
        return ReadLine().Split();
    }

    static int[] ReadInts()
    {
        return Array.ConvertAll(ReadWords(), int.Parse);
    }
}
