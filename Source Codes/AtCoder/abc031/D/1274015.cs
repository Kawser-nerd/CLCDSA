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
    private int K, N;
    private string[] V, W;

    private void Scan()
    {
        var line = Console.ReadLine().Split(' ');
        K = int.Parse(line[0]);
        N = int.Parse(line[1]);
        V = new string[N];
        W = new string[N];
        for (int i = 0; i < N; i++)
        {
            line = Console.ReadLine().Split(' ');
            V[i] = line[0];
            W[i] = line[1];
        }
    }

    private bool Check(int[] len)
    {
        var map = new Dictionary<int, string>();
        for (int i = 0; i < N; i++)
        {
            int ii = 0;
            foreach (char c in V[i])
            {
                int ind = c - '1';
                string ss = "";
                for(int j = 0; j < len[ind]; j++,ii++)
                {
                    if (ii >= W[i].Length)
                    {
                        return false;
                    }

                    ss += W[i][ii];
                }

                string o;
                if (map.TryGetValue(ind,out o))
                {
                    if (o != ss)
                    {
                        return false;
                    }
                }
                else
                {
                    map[ind] = ss;
                }
            }
            if (ii <= W[i].Length - 1)
            {
                return false;
            }
        }
        for (int i = 0; i < K; i++)
        {
            Console.WriteLine(map[i]);
        }

        return true;
    }

    public void Solve()
    {
        Scan();
        int loop = (int)Math.Pow(3, K);
        for (int i = 0; i < loop; i++)
        {
            int cpi = i;
            int[] len = new int[K];
            for (int j = 0; j < K; j++)
            {
                len[j] = cpi % 3 + 1;
                cpi /= 3;
            }
            if (Check(len))
            {
                return;
            }
        }
    }
}