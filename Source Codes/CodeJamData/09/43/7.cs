using System;
using System.Collections.Generic;
using System.Text;
using System.IO;


namespace Round2ProblemC
{
    class Program
    {
        static int N;
        static int K;
        static int[][] lines;
        static bool IsCompatible(int[] a1, int[] a2)
        {
            if (a1[0] > a2[0])
            {
                for (int i = 0; i < K; ++i)
                    if (a1[i] <= a2[i])
                        return false;
            }
            else
            {
                for (int i = 0; i < K; ++i)
                    if (a1[i] >= a2[i])
                        return false;
            }
            return true;
        }

        static bool IsMaskOk(int mask)
        { 
            for (int i = 0; i < N; ++i)
            {
                if ((mask & (1 << i))!= 0)
                {
                    for (int j = i + 1; j < N; ++j)
                        if ((mask & (1 << j)) != 0)
                            if (!IsCompatible(lines[i], lines[j]))
                                return false;
                }
            }
            return true;
        }
        static int SimpleSol()
        { 
            int[] posMasks = new int[1 << N];
            int cnt = 0;
            for (int i = 1; i < posMasks.Length; ++i)
                if (IsMaskOk(i))
                    posMasks[cnt++] = i;
            int[] dist = new int[1 << N];
            dist[0] = 0;
            Queue<int> q = new Queue<int>(1 << N);
            q.Enqueue(0);
            while (q.Count > 0)
            {
                int st = q.Dequeue();
                int sm = 1 << dist[st];
                for (int i = 0; i < cnt; ++i)
                {
                    int m = posMasks[i];
                    if ((((st | m) & sm) != 0)&& (st & m) == 0 && dist[st | m] == 0)
                    {
                        dist[st | m] = dist[st] + 1;
                        if ((st | m) + 1 == (1 << N))
                            return dist[st] + 1;
                        q.Enqueue(st | m);
                    }
                }
            }
            return dist[(1 << N) - 1];
        }

        static void Main(string[] args)
        {
            //const string fileName = "test";
            const string fileName = "C-small-attempt1";
            //const string fileName = "C-large";

            string DataFolder = @"C:\Projects\CSharp\CodeJam2009\Round2ProblemC\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    string[] s = sr.ReadLine().Split(' ');
                    N = int.Parse(s[0]);
                    K = int.Parse(s[1]);
                    lines = new int[N][];
                    for (int i = 0; i < N; ++i)
                    {
                        s = sr.ReadLine().Split(' ');
                        int[] item = new int[K];
                        for (int j = 0; j < K; ++j)
                            item[j] = int.Parse(s[j]);
                        lines[i] = item;
                    }
                    int res = SimpleSol();
                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + res.ToString());
                }
            }
        }
    }
}
