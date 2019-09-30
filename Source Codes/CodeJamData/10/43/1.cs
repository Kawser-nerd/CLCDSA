using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;

namespace GoogleCodeJam
{
    class Program
    {
        readonly StreamReader reader = new StreamReader("../../Input.txt");
        readonly StreamWriter writer = new StreamWriter("../../Output.txt");
        string bufferedLine;
        int bufferedLineIndex;

        static IEnumerable<int> ReadInts(string data)
        {
            return data.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(s => int.Parse(s));
        }

        string ReadToken()
        {
            if (bufferedLine == null)
                bufferedLine = reader.ReadLine();
            while (bufferedLineIndex < bufferedLine.Length && char.IsWhiteSpace(bufferedLine, bufferedLineIndex))
                bufferedLineIndex++;
            while (bufferedLineIndex >= bufferedLine.Length)
            {
                bufferedLine = reader.ReadLine();
                bufferedLineIndex = 0;
                while (bufferedLineIndex < bufferedLine.Length && char.IsWhiteSpace(bufferedLine, bufferedLineIndex))
                    bufferedLineIndex++;
            }
            int index = bufferedLineIndex;
            while (bufferedLineIndex < bufferedLine.Length && !char.IsWhiteSpace(bufferedLine, bufferedLineIndex))
                bufferedLineIndex++;
            return bufferedLine.Substring(index, bufferedLineIndex - index);
        }

        int ReadInt()
        {
            return int.Parse(ReadToken());
        }

        static void Main(string[] args)
        {
            Stopwatch stopwatch = new Stopwatch();
            var program = new Program();
            stopwatch.Start();
            program.Run();
            stopwatch.Stop();
            program.reader.Close();
            program.writer.Close();
            Console.WriteLine("Elapsed: " + stopwatch.Elapsed);
        }

        void Run()
        {
            int testCount = ReadInt();
            for (int i = 1; i < testCount + 1; i++)
            {
                var stopwatch = new Stopwatch();
                int R = ReadInt();
                int[] X1 = new int[R], Y1 = new int[R], X2 = new int[R], Y2 = new int[R];
                for (int j = 0; j < R; j++)
                {
                    X1[j] = ReadInt();
                    Y1[j] = ReadInt();
                    X2[j] = ReadInt();
                    Y2[j] = ReadInt();
                }
                stopwatch.Start();
                var res = Calc(R, X1, Y1, X2, Y2);
                stopwatch.Stop();
                Console.WriteLine("Done in {0}", stopwatch.Elapsed);
                writer.WriteLine("Case #{0}: {1}", i, res);
            }
        }

        void Traverse(bool[,] connected, int k, int[] color, int c, bool[] was)
        {
            if (was[k]) return;
            was[k] = true;
            color[k] = c;
            for (int i = 0; i < was.Length; i++)
            {
                if (connected[k, i])
                {
                    Traverse(connected, i, color, c, was);
                }
            }
        }

        int Calc(int R, int[] X1, int[] Y1, int[] X2, int[] Y2)
        {
            bool[,] connected = new bool[R,R];
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < R; j++)
                {
                    if (i == j)
                        continue;
                    int xleft = Math.Max(X1[i], X1[j]), xright = Math.Min(X2[i], X2[j]), yup = Math.Max(Y1[i], Y1[j]),
                        ydown = Math.Min(Y2[i], Y2[j]);
                    if (xleft < xright + 1 && yup <= ydown + 1)
                        connected[i, j] = true;
                    if (xleft <= xright + 1 && yup < ydown + 1)
                        connected[i, j] = true;
                    if (xleft == xright + 1 && yup == ydown + 1 && (X2[i] + 1 == X1[j] && Y1[i] == Y2[j] + 1) ||
                        (X2[j] + 1 == X1[i] && Y1[j] == Y2[i] + 1))
                    {
                        connected[i, j] = true;
                    }
                    
                }
            }
            bool[] was = new bool[R];
            int[] color = new int[R];
            int c = 0;
            for (int i = 0; i < R; i++)
            {
                if (!was[i])
                    Traverse(connected, i, color, c++, was);
            }
            List<int>[] unions = new List<int>[c];
            for (int i = 0; i < c; i++)
            {
                unions[i] = new List<int>();
            }
            for (int i = 0; i < R; i++)
            {
                unions[color[i]].Add(i);
            }
            int res = 0;
            foreach (List<int> list in unions)
            {
                int right = 0, down = 0;
                foreach (int i in list)
                {
                    right = Math.Max(right, X2[i]);
                    down = Math.Max(down, Y2[i]);
                }
                foreach (int i in list)
                {
                    res = Math.Max(res, right - X1[i] + down - Y1[i] + 1);
                }
            }
            return res;
        }
    }
}