using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;



class Program
{
    static int FordFulkerson(int[,] G, int source, int sink)//G changes
    {
        //G[i][j] is capacity From i to j (directed)
        int N = G.GetLength(0);//there are N vertexes
        if (N != G.GetLength(1))
            throw new Exception("Dimentions must be the same");
        int flow = 0;
        Queue<int> Q = new Queue<int>();

        while (true)
        {
            Q.Clear();
            Q.Enqueue(source);

            int[] from = new int[N];

            #region BFS
            for (int i = 0; i < N; i++) from[i] = -1;
            Queue<int> BFS = new Queue<int>();
            BFS.Enqueue(source);
            from[source] = source;
            while (BFS.Count > 0)
            {
                int currentbfs = BFS.Dequeue();
                for (int i = 0; i < N; i++)
                {
                    if (from[i] == -1 && G[currentbfs, i] > 0)
                    {
                        from[i] = currentbfs;
                        BFS.Enqueue(i);
                    }
                }
            }
            #endregion

            if (from[sink] != -1)
            {
                #region Path capacity
                int t = sink;
                int min = int.MaxValue;
                while (t != source)
                {
                    min = Math.Min(min, G[from[t], t]);
                    t = from[t];
                }
                #endregion

                flow += min;//add to flow
                #region Update network
                t = sink;
                while (t != source)
                {
                    G[from[t], t] -= min;
                    G[t, from[t]] += min;
                    t = from[t];
                }
                #endregion
            }
            else break;
        }
        return flow;
    }
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader("D:\\in.in");
        StreamWriter sw = new StreamWriter("D:\\out.out");
        sw.AutoFlush = true;
        int n = int.Parse(sr.ReadLine());
        Console.WriteLine(n);
        for (int i = 0; i < n; i++)
        {
            sw.WriteLine("Case #" + (i + 1).ToString() + ": " + Solution(sr));
            Console.WriteLine(i);
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }


    static string Solution(StreamReader sr)
    {
        int[,] G = new int[3003, 3003];

        int N = int.Parse(sr.ReadLine());

        List<string> A = new List<string>();
        List<string> B = new List<string>();

        for (int i = 0; i < N; i++)
        {
            string[] t = sr.ReadLine().Split(' ');
            if (!A.Contains(t[0]))
            {
                G[3000, A.Count] = 1;
                A.Add(t[0]);
            }
            if (!B.Contains(t[1]))
            {
                G[2000 + B.Count, 3001] = 1;
                B.Add(t[1]);
            }
            int a = A.IndexOf(t[0]);
            int b = B.IndexOf(t[1]);
            G[a, 1000 + i] = 1;
            G[1000 + i, 2000 + b] = 1;
        }

        int x = FordFulkerson(G, 3000, 3001);
        return (N - A.Count-B.Count+x).ToString();
    }
}