using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;
using System.IO;

class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Magatro
{
    private int N, L;
    private int[] A;

    private void Scan()
    {
        var line = Console.ReadLine().Split(' ');
        N = int.Parse(line[0]);
        L = int.Parse(line[1]);
        A = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    }

    public void Solve()
    {
        Scan();

        for (int i = 1; i < N; i++)
        {

            if (A[i] + A[i - 1] >= L)
            {
                var sb = new StringBuilder();
                sb.AppendLine("Possible");
                for (int j = 1; j < i; j++)
                {
                    sb.AppendLine(j.ToString());
                }

                for (int j = N - 1; j >= i; j--)
                {
                    sb.AppendLine(j.ToString());
                }
                Console.Write(sb.ToString());
                return;
            }
        }
        Console.WriteLine("Impossible");
    }
}