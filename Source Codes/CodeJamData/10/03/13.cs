using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

class ProblemC
{
    static StreamReader input;
    static StreamWriter output;

    static void Main(string[] args)
    {
        string testSet = "C-large";
        using (input = new StreamReader(testSet + ".in"))
        {
            using (output = new StreamWriter(testSet + ".out"))
            {
                run();
            }
        }
    }

    private static void run()
    {
        int T = readInt();
        for (int i = 1; i <= T; i++)
        {
            run(i);
        }
    }

    private static void run(int caseNum)
    {
        int[] groups = readInts();
        int R = groups[0], K = groups[1], N = groups[2];
        groups = readInts();

        int[] next = new int[N];
        int[] value = new int[N];
        for (int i = 0; i < N; i++)
        {
            value[i] = 0;
            for (int j = 0; j < N; j++)
            {
                if (value[i] + groups[(i + j) % N] <= K)
                {
                    value[i] += groups[(i + j) % N];
                    next[i] = (i + j + 1) % N;
                }
                else
                    break;
            }
        }

        int?[] step = new int?[N];
        long?[] stepVal = new long?[N];
        int cur = 0;
        long val = 0;
        for (int i = 0; i < R; i++)
        {
            if (step[cur].HasValue)
            {
                int steps = i - step[cur].Value;
                int loops = (R - i) / steps;
                val += (val - stepVal[cur].Value) * loops;
                i += steps * loops;
                if (i >= R) break;
            }
            step[cur] = i;
            stepVal[cur] = val;
            val += value[cur];
            cur = next[cur];
        }

        output.WriteLine("Case #{0}: {1}", caseNum, val);
    }

    private static int readInt()
    {
        string line = input.ReadLine();
        return int.Parse(line);
    }

    private static int[] readInts()
    {
        string line = input.ReadLine();
        return Array.ConvertAll(line.Split(), int.Parse);
    }
}
