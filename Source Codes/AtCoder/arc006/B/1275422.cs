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
    int N, L;
    string[] A;
    string g;
    private void Scan()
    {
        var line = Console.ReadLine().Split(' ');
        N = int.Parse(line[0]);
        L = int.Parse(line[1]);
        A = new string[L];
        for (int i = 0; i < L; i++)
        {
            A[i] = Console.ReadLine();
        }
        g = Console.ReadLine();
    }

    public void Solve()
    {
        Scan();
        int index = -1;
        for (int i = 0; i < g.Length; i++)
        {
            if (g[i] == 'o')
            {
                index = i;
                break;
            }
        }

        for (int i = L - 1; i >= 0; i--)
        {
            if (index > 0)
            {
                if (A[i][index - 1] == '-')
                {
                    index -= 2;
                    continue;
                }
            }

            if (index < N * 2 - 2)
            {
                if (A[i][index + 1] == '-')
                {
                    index += 2;
                    continue;
                }
            }
        }
        Console.WriteLine(index / 2 + 1);
    }
}