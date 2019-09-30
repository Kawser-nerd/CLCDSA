using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;
using System.Threading;

namespace C
{
    [TestFixture]
    public class Program
    {
        public void TestCase(int testCase, TextReader inputStream, TextWriter outputStream)
        {
            string[] tmp = inputStream.ReadLine().Split(' ');

            int N = Convert.ToInt32(tmp[0]);
            int M = Convert.ToInt32(tmp[1]);

            string[] codes = new string[N];
            List<int>[] edges = new List<int>[N];

            for (int i = 0; i < N; i++)
            {
                codes[i] = inputStream.ReadLine();
                edges[i] = new List<int>();
            }

            for (int i = 0; i < M; i++)
            {
                tmp = inputStream.ReadLine().Split(' ');

                int a = Convert.ToInt32(tmp[0]) - 1;
                int b = Convert.ToInt32(tmp[1]) - 1;

                edges[a].Add(b);
                edges[b].Add(a);
            }

            string res = new string('9', N * 5 + 1);

            for (int start = 0; start < N; start++)
            {
                Stack<State> Q = new Stack<State>();

                State s = new State();
                s.Current = 0;
                s.Visited = new bool[N];
                s.Visited[start] = true;
                s.Path = new int[N];
                s.Path[s.Current++] = start;
                s.Result = codes[start];

                Q.Push(s);

                while (Q.Count > 0)
                {
                    State cur = Q.Pop();

                    if (cur.Current == 0)
                    {
                        bool ok = true;

                        for (int i = 0; i < N; i++)
                        {
                            if (!cur.Visited[i])
                            {
                                ok = false;
                                break;
                            }
                        }

                        if (ok && cur.Result.CompareTo(res) < 0)
                            res = cur.Result;
                    }
                    else
                    {
                        int curCity = cur.Path[cur.Current - 1];

                        State newState = new State();
                        newState.Current = cur.Current - 1;
                        newState.Visited = new bool[N];
                        Array.Copy(cur.Visited, newState.Visited, N);
                        newState.Path = new int[N];
                        Array.Copy(cur.Path, newState.Path, N);
                        newState.Result = cur.Result;

                        Q.Push(newState);

                        for (int i = 0; i < edges[curCity].Count; i++)
                        {
                            if (!cur.Visited[edges[curCity][i]])
                            {
                                newState = new State();
                                newState.Current = cur.Current;
                                newState.Visited = new bool[N];
                                Array.Copy(cur.Visited, newState.Visited, N);
                                newState.Visited[edges[curCity][i]] = true;
                                newState.Path = new int[N];
                                Array.Copy(cur.Path, newState.Path, N);
                                newState.Path[newState.Current++] = edges[curCity][i];
                                newState.Result = cur.Result + codes[edges[curCity][i]];

                                Q.Push(newState);
                            }
                        }
                    }
                }
            }

            outputStream.WriteLine("Case #{0}: {1}", testCase, res);
        }

        public class State
        {
            public bool[] Visited;
            public int[] Path;
            public int Current;
            public string Result;
        }

        #region Tests

        [TestCase]
        public void TestSmallInput()
        {
            TestInput("..\\..\\Input\\C-small.in", "..\\..\\Output\\C-small.out");
        }

        [TestCase]
        public void TestLargeInput()
        {
            TestInput("..\\..\\Input\\C-large.in", "..\\..\\Output\\C-large.out");
        }

        private void TestInput(string inputFile, string outputFile)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("");

            FileInfo input = new FileInfo(inputFile);
            TextReader inputStream = input.OpenText();

            FileInfo output = new FileInfo(outputFile);
            TextWriter outputStream = output.CreateText();

            int testCase = Convert.ToInt32(inputStream.ReadLine());

            for (int i = 1; i <= testCase; i++)
            {
                TestCase(i, inputStream, outputStream);
            }

            outputStream.Close();
            inputStream.Close();
        }

        #endregion
    }
}
