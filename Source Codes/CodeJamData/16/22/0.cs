using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class B
{
    static int n;
    static string C;
    static string J;
    static long bestC;
    static long bestJ;
    static long bestD;

    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Error.WriteLine("Case " + CASE);

            string[] ps = Console.ReadLine().Split();

            n = ps[0].Length;
            C = ps[0];
            J = ps[1];
            bestC = -1;
            bestJ = -1;
            bestD = long.MaxValue;

            makeSame(0, 0, 0);

            Console.WriteLine("Case #" + CASE + ": " + formatL(bestC, n) + " " + formatL(bestJ, n));
        }
    }

    public static void makeSame(int i, long c, long j)
    {
        if (i == n)
        {
            long diff = Math.Abs(c - j);
            if (diff < bestD || (diff == bestD && (c < bestC || (c == bestC && j < bestJ))))
            {
                bestD = diff;
                bestJ = j;
                bestC = c;
            }
        }
        else
        {
            if (C[i] == '?' && J[i] == '?')
            {
                makeSame(i + 1, c * 10, j * 10);
                maxJ(i + 1, c * 10 + 1, j * 10);
                maxC(i + 1, c * 10, j * 10 + 1);
            }
            else if (C[i] == '?')
            {
                makeSame(i + 1, c * 10 + J[i] - '0', j * 10 + J[i] - '0');
                if(J[i] > '0')
                    maxC(i + 1, c * 10 + J[i] - '0' - 1, j * 10 + J[i] - '0');
                if (J[i] < '9')
                    maxJ(i + 1, c * 10 + J[i] - '0' + 1, j * 10 + J[i] - '0');
            }
            else if (J[i] == '?')
            {
                makeSame(i + 1, c * 10 + C[i] - '0', j * 10 + C[i] - '0');
                if (C[i] > '0')
                    maxJ(i + 1, c * 10 + C[i] - '0', j * 10 + C[i] - '0' - 1);
                if (C[i] < '9')
                    maxC(i + 1, c * 10 + C[i] - '0', j * 10 + C[i] - '0' + 1);
            }
            else
            {
                long newC = c * 10 + C[i] - '0';
                long newJ = j * 10 + J[i] - '0';

                if (C[i] > J[i])
                {
                    maxJ(i + 1, newC, newJ);
                }
                else if (C[i] < J[i])
                {
                    maxC(i + 1, newC, newJ);
                }
                else
                {
                    makeSame(i + 1, newC, newJ);
                }
            }
        }
    }

    public static void maxC(int i, long c, long j)
    {
        if (i == n)
        {
            long diff = Math.Abs(c - j);
            if (diff < bestD || (diff == bestD && (c < bestC || (c == bestC && j < bestJ))))
            {
                bestD = diff;
                bestJ = j;
                bestC = c;
            }
        }
        else
        {
            long newC = c * 10;
            if (C[i] == '?') newC += 9;
            else newC += C[i] - '0';

            long newJ = j * 10;
            if (J[i] != '?') newJ += J[i] - '0';

            maxC(i + 1, newC, newJ);
        }
    }

    public static void maxJ(int i, long c, long j)
    {
        if (i == n)
        {
            long diff = Math.Abs(c - j);
            if (diff < bestD || (diff == bestD && (c < bestC || (c == bestC && j < bestJ))))
            {
                bestD = diff;
                bestJ = j;
                bestC = c;
            }
        }
        else
        {
            long newJ = j * 10;
            if (J[i] == '?') newJ += 9;
            else newJ += J[i] - '0';

            long newC = c * 10;
            if (C[i] != '?') newC += C[i] - '0';

            maxJ(i + 1, newC, newJ);
        }
    }

    public static string formatL(long x, int len)
    {
        string s = x.ToString();
        while (s.Length < len)
            s = "0" + s;
        return s;
    }
}
