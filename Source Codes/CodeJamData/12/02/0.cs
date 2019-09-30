using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class B
{
    public static void Main()
    {
        int T = ReadInt();
        for (int i = 1; i <= T; i++)
        {
            int[] args = ReadInts();
            int N = args[0], S = args[1], p = args[2];
            int[] scores = new int[N];
            Array.Copy(args, 3, scores, 0, N);
            int a = 0, b = 0;
            foreach (int j in scores)
                if (j >= 3 * p - 2) a++;
                else if (j >= 3 * p - 4 && j >= 2) b++;
            int res = a + Math.Min(b, S);
            Console.WriteLine("Case #{0}: {1}", i, res);
        }
    }

    #region Library

    static string ReadLine()
    {
        return Console.ReadLine();
    }

    static string[] ReadWords()
    {
        return ReadLine().Split();
    }

    static int ReadInt()
    {
        return int.Parse(ReadLine());
    }

    static int[] ReadInts()
    {
        return Array.ConvertAll(ReadWords(), int.Parse);
    }

    #endregion
}