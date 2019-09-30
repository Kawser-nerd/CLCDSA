using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;
using System.Diagnostics;

namespace QuestionC
{
    class Program
    {
        static void Main(string[] args)
        {
            string casename = "C-small-attempt1";
            using (StreamReader reader = new StreamReader(casename + ".in"))
            {
                IOStream input = new IOStream(reader);
                using (StreamWriter writer = new StreamWriter(casename + ".out"))
                {
                    int NumCases = input.ReadInt();
                    for (int testcase = 0; testcase != NumCases; ++testcase)
                    {
                        // parse testcase
                        int n = input.ReadInt();
                        int k = input.ReadInt();
                        List<List<int>> stocks = new List<List<int>>();
                        for (int i = 0; i != n; ++i)
                        {
                            var s = new List<int>();
                            stocks.Add(s);
                            for (int j = 0; j != k; ++j)
                            {
                                s.Add(input.ReadInt());
                            }
                        }

                        // solve testcase
                        int solution = Solve(stocks);

                        // write answer
                        Console.WriteLine("Case #{0}: {1}", testcase + 1, solution);
                        writer.WriteLine("Case #{0}: {1}", testcase + 1, solution);
                    }
                }
            }
        }

        private static bool CrossOrTouch(List<int> s, List<int> t)
        {
            if (s[0] == t[0]) return true;
            bool above = s[0] > t[0];
            for (int i = 1; i != s.Count; ++i)
            {
                if (above)
                {
                    if (s[i] <= t[i])   return true;
                }
                else
                {
                    if (s[i] >= t[i])   return true;
                }
            }
            return false;
        }

        private static int Solve(List<List<int>> stocks)
        {
            List<List<int>> colours = new List<List<int>>();
            List<bool> coloured = new List<bool>();
            for (int s = 0; s != stocks.Count; ++s)
            {
                coloured.Add(false);
            }

            for (int Stock = 0; Stock != stocks.Count; ++Stock)
            {
                // pick next stock to colour
                int maxCollisions = -1;
                int next = 0;
                for (int i = 0; i != stocks.Count; ++i)
                {
                    if (coloured[i]) continue;
                    int numCollisions = 0;
                    for (int j = 0; j != stocks.Count; ++j)
                    {
                        if (i == j) continue;
                        if (CrossOrTouch(stocks[i], stocks[j]))
                        {
                            ++numCollisions;
                        }
                    }

                    if (numCollisions > maxCollisions)
                    {
                        maxCollisions = numCollisions;
                        next = i;
                    }
                }

                // colour j
                bool done = false;
                for (int colour = 0; colour != colours.Count; ++colour)
                {
                    bool good = true;
                    for (int k = 0; k != colours[colour].Count; ++k)
                    {
                        if (CrossOrTouch(stocks[next], stocks[colours[colour][k]]))
                        {
                            good = false;
                            break;
                        }
                    }
                    if (good)
                    {
                        colours[colour].Add(next);
                        coloured[next] = true;
                        done = true;
                        break;
                    }
                }
                if (!done)
                {
                    colours.Add(new List<int> { next });
                    coloured[next] = true;
                }
            }
            return colours.Count;
        }
    }

    class IOStream
    {
        public IOStream(StreamReader reader)
        {
            this.reader = reader;
        }

        public int ReadInt()
        {
            return int.Parse(ReadString());
        }

        public long ReadLong()
        {
            return long.Parse(ReadString());
        }

        public string ReadString()
        {
            if (parts == null || partNum >= parts.Length)
            {
                ReadMore();
            }
            string rtn = parts[partNum];
            ++partNum;
            return rtn;
        }

        private void ReadMore()
        {
            parts = reader.ReadLine().Split(' ');
            partNum = 0;
        }

        StreamReader reader;
        string[] parts;
        int partNum;
    }
}
