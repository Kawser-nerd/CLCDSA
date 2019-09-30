using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace GCJ
{
    class Program
    {
        TextReader cin = Console.In;
        TextWriter cout = Console.Out;
        static string dir = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Desktop), "GCJ");

        public Program(string s)
        {
            cin = new StreamReader(s);
            s = s.Substring(0, s.Length - 2) + "out";
            cout = new StreamWriter(s);
        }

        public static void Main(string[] args)
        {
            foreach (string s in Directory.GetFiles(dir, "*.in"))
            {
                if (s[s.LastIndexOf('\\') + 1] != 'A') continue;
                new Program(s).run();
            }
            File.Copy("..\\..\\Program.cs", Path.Combine(dir, "A-Program.cs"), true);
        }

        private void run()
        {
            int TC = readInt();
            for (int tc = 1; tc <= TC; tc++)
            {
                int L = readInt();
                string s = cin.ReadLine();
                string[] ss = s.Split();
                while (ss.Length < 2 * L)
                {
                    s = s.Trim() + " " + cin.ReadLine().Trim();
                    ss = s.Split();
                }
                int dir = 0, x = 150, y = 150;
                bool[,] rt = new bool[300, 300];
                bool[,] bt = new bool[300, 300];
                for (int i = 0; i < L; i++)
                {
                    int n = int.Parse(ss[i * 2 + 1]);
                    string p = ss[i * 2];
                    for (int j = 0; j < n; j++)
                    {
                        foreach (char c in p)
                        {
                            if (c == 'R') dir = (dir + 1) % 4;
                            else if (c == 'L') dir = (dir + 3) % 4;
                            else
                            {
                                if (dir == 0) rt[x-1, y++] = true;
                                else if (dir == 1) bt[x++, y] = true;
                                else if (dir == 2) rt[x - 1, --y] = true;
                                else if (dir == 3) bt[--x, y] = true;
                            }
                        }
                    }
                }
                Console.WriteLine((x == 150) + " " + (y == 150));
                int[] ff = new int[300 * 300];
                Queue<int> q = new Queue<int>();
                q.Enqueue(0);
                int?[] xmx = new int?[300], xmn = new int?[300], ymx = new int?[300], ymn = new int?[300];
                while (q.Count > 0)
                {
                    int v = q.Dequeue();
                    if (ff[v] == 1)
                        continue;
                    ff[v] = 1;
                    if ((v % 300) != 0 && ff[v - 1] == 0 && !bt[v / 300, v % 300])
                        q.Enqueue(v - 1);
                    if ((v % 300) != 299 && ff[v + 1] == 0 && !bt[v / 300, 1 + (v % 300)])
                        q.Enqueue(v + 1);
                    if ((v / 300) != 0 && ff[v - 300] == 0 && !rt[(v / 300) - 1, v % 300])
                        q.Enqueue(v - 300);
                    if ((v / 300) != 299 && ff[v + 300] == 0 && !rt[v / 300, v % 300])
                        q.Enqueue(v + 300);
                }
                int res = 0;
                for (int i = 0; i < 300; i++)
                    for (int j = 0; j < 300; j++)
                    {
                        if (ff[i * 300 + j] == 1) continue;
                        if (!xmx[i].HasValue) xmx[i] = j; else xmx[i] = Math.Max(xmx[i].Value, j);
                        if (!xmn[i].HasValue) xmn[i] = j; else xmn[i] = Math.Min(xmn[i].Value, j);
                        if (!ymx[j].HasValue) ymx[j] = i; else ymx[j] = Math.Max(ymx[j].Value, i);
                        if (!ymn[j].HasValue) ymn[j] = i; else ymn[j] = Math.Min(ymn[j].Value, i);
                    }
                for (int i = 0; i < 300; i++)
                    for (int j = 0; j < 300; j++)
                        if (ff[i * 300 + j] == 1 && xmx[i].HasValue && ymx[j].HasValue)
                            if ((ymn[j].Value < i && i < ymx[j].Value) || (xmn[i].Value < j && j < xmx[i].Value))
                                res++;
                cout.WriteLine("Case #{0}: {1}", tc, res);
            }
            cout.Close();
        }

        int readInt()
        {
            return int.Parse(cin.ReadLine().Trim());
        }

        int[] readInts()
        {
            return Array.ConvertAll<string, int>(cin.ReadLine().Split(), int.Parse);
        }

        double readDouble()
        {
            return double.Parse(cin.ReadLine().Trim());
        }

        double[] readDoubles()
        {
            return Array.ConvertAll<string, double>(cin.ReadLine().Split(), double.Parse);
        }
    }
}