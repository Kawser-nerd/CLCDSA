

namespace Contest
{
    using System;
    using System.IO;

    public class Program
    {
        static void Main(string[] args)
        {
            Wrapper.Solve(new ProblemC(), Console.In, Console.Out);
        }
    }

    public class Wrapper
    {
        public static void Solve(IProblem problem, TextReader input, TextWriter output)
        {
            var parser = new InputParser(input);
            int T = parser.GetInt();

            for (int i = 0; i < T; i++)
            {
                output.WriteLine(string.Format("Case #{0}: {1}", i + 1, problem.SolveOneCase(parser)));
            }
        }
    }

    public interface IProblem
    {
        string SolveOneCase(InputParser input);
    }
}﻿

namespace Contest
{
    using System;
    using System.Collections.Generic;

    public class ProblemC : IProblem
    {
        public string SolveOneCase(InputParser input)
        {
            int N = input.GetInt();

            int[] d = new int[N];
            int[] n = new int[N];
            int[] w = new int[N];
            int[] e = new int[N];
            int[] S = new int[N];
            int[] d_d = new int[N];
            int[] d_p = new int[N];
            int[] d_s = new int[N];

            int[] a = new int[N];

            for (int i = 0; i < N; i++)
            {
                d[i] = input.GetInt();
                n[i] = input.GetInt();
                w[i] = input.GetInt();
                e[i] = input.GetInt();
                S[i] = input.GetInt();
                d_d[i] = input.GetInt();
                d_p[i] = input.GetInt();
                d_s[i] = input.GetInt();
            }

            var pq = new PriorityQueue<int>();

            for (int i = 0; i < N; i++)
            {
                pq.Enqueue(i, d[i]);
            }

            int[] wall = new int[20000];
            int ADJ = +10000;

            int count = 0;
            while(!pq.IsEmpty)
            {
                int dd = pq.GetNextPriority();

                var list = new List<int>();

                while (!pq.IsEmpty && pq.GetNextPriority() == dd)
                {
                    list.Add(pq.Dequeue());
                }

                for (int its = 0; its < 2; its++)
                {
                    for (int t = 0; t < list.Count; t++)
                    {
                        int i = list[t];



                        int ww = a[i]*d_p[i] + w[i];
                        int ee = a[i]*d_p[i] + e[i];
                        int ss = a[i]*d_s[i] + S[i];

                        for (int j = ww; j < ee; j++)
                        {
                            if( its == 0)
                            {
                                if( ss > wall[j+ADJ])
                                {


                                    count++;
                                    break;
                                }
                            }

                            if(its == 1)
                            {
                                wall[j + ADJ] = Math.Max(wall[j + ADJ], ss);
                            }
                        }

                        if( its == 1)
                        {
                            a[i]++;

                            if( a[i] < n[i])
                            {
                                pq.Enqueue(i, dd+d_d[i]);
                            }

                        }
                    }

                }
            }

            return count.ToString();
        }
    }



}

namespace Contest
{
    using System;
    using System.Collections.Generic;
    using System.Linq;

    // Had to roll my own prioirty Queue
    // inspired by: http://stackoverflow.com/questions/102398/priority-queue-in-net
    public class PriorityQueue<T>
    {
        public int Count { get; private set; }

        private SortedDictionary<int, Queue<T>> dictionary;

        public PriorityQueue()
        {
            dictionary = new SortedDictionary<int, Queue<T>>();
        }

        public bool IsEmpty
        {
            get { return Count == 0; }
        }

        public int GetNextPriority()
        {
            return dictionary.Keys.First();
        }

        public void Enqueue(T item, int priority)
        {
            if (!dictionary.ContainsKey(priority))
            {
                dictionary.Add(priority, new Queue<T>());
            }

            dictionary[priority].Enqueue(item);
            Count++;
        }


        public T Dequeue()
        {
            if (IsEmpty)
            {
                throw new InvalidOperationException("Cannot Dequeue.  The queue is empty.");
            }

            int key = dictionary.Keys.First();
            Queue<T> queue = dictionary[key];

            if (queue.Count == 1)
                dictionary.Remove(key);

            Count--;
            return queue.Dequeue();
        }
    }
}﻿

namespace Contest
{
    using System.Collections;
    using System;
    using System.IO;

    public class InputParser
    {
        private readonly TextReader _textReader;

        private IEnumerator _enumerator;

        public InputParser(TextReader textReader)
        {
            this._textReader = textReader;
            this._enumerator = (new string[0]).GetEnumerator();
        }

        public string ReadLine()
        {
            return _textReader.ReadLine();
        }

        public string[] GetStringArray()
        {
            return ReadLine().Split(new string[0], StringSplitOptions.RemoveEmptyEntries);
        }

        public int[] GetIntArray()
        {
            string[] tokens = GetStringArray();
            int length = tokens.Length;

            var values = new int[length];

            for (int i = 0; i < length; i++)
            {
                values[i] = int.Parse(tokens[i]);
            }

            return values;
        }

        public long[] GetLongArray()
        {
            string[] tokens = GetStringArray();
            int length = tokens.Length;

            var values = new long[length];

            for (int i = 0; i < length; i++)
            {
                values[i] = long.Parse(tokens[i]);
            }

            return values;
        }

        public string GetString()
        {
            while (_enumerator.MoveNext() == false)
            {
                _enumerator = GetStringArray().GetEnumerator();
            }

            return (string)_enumerator.Current;
        }

        public int GetInt()
        {
            return int.Parse(GetString());
        }

        public long GetLong()
        {
            return long.Parse(GetString());
        }
    }
}