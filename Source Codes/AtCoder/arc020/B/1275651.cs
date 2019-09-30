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
    static void Main(string[] args)
    {
        new Magatro().Solve();
    }
}

public class Magatro
{
    int N, C;
    int[] A;

    private void Scan()
    {
        string[] line = Console.ReadLine().Split(' ');
        N = int.Parse(line[0]);
        C = int.Parse(line[1]);
        A = new int[N];
        for (int i = 0; i < N; i++)
        {
            A[i] = int.Parse(Console.ReadLine());
        }
    }

    public void Solve()
    {
        Scan();
        var mp1 = new Dictionary<int, int>();
        var mp2 = new Dictionary<int, int>();
        for (int i = 1; i <= 10; i++)
        {
            mp1[i] = 0;
            mp2[i] = 0;
        }
        for (int i = 0; i < N; i++)
        {
            if (i % 2 == 0)
            {
                mp1[A[i]]++;
            }
            else
            {
                mp2[A[i]]++;
            }
        }

        var AA = mp1.ToArray();
        var BB = mp2.ToArray();
        Array.Sort(AA, (a, b) => -a.Value.CompareTo(b.Value));
        Array.Sort(BB, (a, b) => -a.Value.CompareTo(b.Value));
        int ans = 0;
        if (AA[0].Key == BB[0].Key)
        {
            int aaa = AA[1].Value + BB[0].Value;
            int bbb = AA[0].Value + BB[1].Value;
            ans = Math.Max(aaa, bbb);
        }
        else
        {
            ans = AA[0].Value + BB[0].Value;
        }
        Console.WriteLine((N - ans)*C);
    }
}