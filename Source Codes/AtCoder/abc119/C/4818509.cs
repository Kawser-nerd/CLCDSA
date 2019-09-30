using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Program
{
    static int[] L;
    static int N;
    static int[] ABC;
    static int[] USE;

    public static void Main(string[] args)
    {
        MainModule(Console.In);
    }

    public static void MainModule(TextReader In)
    { 
        var lin = In.ReadLine().Split(' ').Select(n => int.Parse(n)).ToArray();
        N = lin[0];
        ABC = lin.Skip(1).ToArray();
        L = new int[N];
        for (int i = 0; i < N; i++)
        {
            L[i] = int.Parse(In.ReadLine());
        }

        USE = new int[N];

        CurrMinMP = int.MaxValue;
        F(0);
        Console.WriteLine(CurrMinMP);
    }

    static int CurrMinMP;

    static void F(int depth)
    {
        if (depth == N)
        {
            int[] abcLength = new int[3];
            int[] abcNum = new int[3];
            for (int i = 0; i < N; i++)
            {
                switch (USE[i])
                {
                    case 0:
                        break;
                    case 1:
                    case 2:
                    case 3:
                        abcLength[USE[i] - 1] += L[i];
                        abcNum[USE[i] - 1] += 1;
                        break;
                }
            }
            int MP = 0;
            for (int i = 0; i < 3; i++)
            {
                if (abcNum[i] == 0)
                    goto L100;
                MP += (10 * (abcNum[i] - 1));
                MP += Math.Abs(abcLength[i] - ABC[i]);
            }
            CurrMinMP = Math.Min(CurrMinMP, MP);
        L100:
            ;
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                USE[depth] = i;
                F(depth + 1);
            }
        }
    }
}