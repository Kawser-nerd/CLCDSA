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
                if (s[s.LastIndexOf('\\') + 1] != 'D') continue;
                new Program(s).run();
            }
            File.Copy("..\\..\\Program.cs", Path.Combine(dir, "D-Program.cs"), true);
        }

        private void run()
        {
            int TC = readInt();
            for (int tc = 1; tc <= TC; tc++)
            {
                int[] tmp = readInts();
                int H = tmp[0], W = tmp[1], R = tmp[2];
                int[,] ws = new int[H, W];
                for (int i = 0; i < R; i++)
                {
                    tmp = readInts();
                    ws[tmp[0] - 1, tmp[1] - 1] = -1;
                }
                ws[0, 0] = 1;
                for (int i = 0; i < H; i++)
                    for (int j = 0; j < W; j++)
                        if (ws[i, j] != -1)
                        {
                            if (i > 0 && j > 1 && ws[i - 1, j - 2] != -1)
                                ws[i, j] += ws[i - 1, j - 2];
                            if (i > 1 && j > 0 && ws[i - 2, j - 1] != -1)
                                ws[i, j] += ws[i - 2, j - 1];
                            ws[i, j] %= 10007;
                        }
                cout.WriteLine("Case #{0}: {1}", tc, ws[H - 1, W - 1]);
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