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
    int N;
    int[] X, Y;
    private void Scan()
    {
        N = int.Parse(Console.ReadLine());
        X = new int[N];
        Y = new int[N];
        for (int i = 0; i < N; i++)
        {
            string[] line = Console.ReadLine().Split(' ');
            X[i] = int.Parse(line[0]);
            Y[i] = int.Parse(line[1]);
        }
    }

    private bool C(int a, int b, int c, int d)
    {
        long aa = (long)a * d - (long)b * c;
        return aa % 2 == 0 && aa != 0;
    }

    public void Solve()
    {
        Scan();
        int cnt = 0;
        for (int i = 0; i < N - 2; i++)
        {
            for (int j = i + 1; j < N - 1; j++)
            {
                for (int k = j + 1; k < N; k++)
                {
                    int a = X[j] - X[i];
                    int b = Y[j] - Y[i];
                    int c = X[k] - X[i];
                    int d = Y[k] - Y[i];
                    if (C(a, b, c, d)) cnt++;
                }
            }
        }
        Console.WriteLine(cnt);
    }
}