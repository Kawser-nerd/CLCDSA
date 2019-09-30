using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;

namespace ProblemA
{
    class Program
    {
        class Node
        {
            public bool word;
            public Dictionary<char, Node> nodes = new Dictionary<char, Node>();

            public void Add(string s, int index)
            {
                if (index == s.Length)
                {
                    word = true;
                }
                else
                {
                    if (!nodes.ContainsKey(s[index]))
                    {
                        nodes[s[index]] = new Node();
                    }
                    nodes[s[index]].Add(s, index + 1);
                }
            }

            public void Find(string s, int index, int cost, int last, Queue<int> queue, int[,] costs)
            {
                if (word)
                {
                    if (costs[index, last] == 0 || cost < costs[index, last])
                    {
                        costs[index, last] = cost;
                        queue.Enqueue(index);
                        queue.Enqueue(cost);
                        queue.Enqueue(last);
                    }
                }
                if (index < s.Length)
                {
                    if (nodes.ContainsKey(s[index]))
                    {
                        nodes[s[index]].Find(s, index + 1, cost, Math.Min(4, last + 1), queue, costs);
                    }
                    if (last == 4)
                    {
                        foreach (KeyValuePair<char, Node> pair in nodes)
                        {
                            if (pair.Key == s[index])
                            {
                                pair.Value.Find(s, index + 1, cost, Math.Min(4, last + 1), queue, costs);
                            }
                            else
                            {
                                pair.Value.Find(s, index + 1, cost + 1, 0, queue, costs);
                            }
                        }
                    }                    
                }
            }
        }

        class Solver
        {
            Node root = new Node();

            public Solver()
            {
                using (StreamReader reader = new StreamReader("..\\..\\garbled_email_dictionary.txt"))
                {
                    while (!reader.EndOfStream)
                    {
                        string s = reader.ReadLine();
                        root.Add(s, 0);
                    }
                }
            }

            public int Solve(string s)
            {
                int[,] costs = new int[s.Length + 1, 5];
                Queue<int> queue = new Queue<int>();
                costs[0, 4] = 1;
                queue.Enqueue(0);
                queue.Enqueue(1);
                queue.Enqueue(4);
                while (queue.Count > 0)
                {
                    int index = queue.Dequeue();
                    int cost = queue.Dequeue();
                    int last = queue.Dequeue();
                    if (cost == costs[index, last])
                    {
                        root.Find(s, index, cost, last, queue, costs);
                    }
                }

                int res = Int32.MaxValue;
                for (int i = 0; i < 5; i++)
                {
                    if (costs[s.Length, i] != 0)
                    {
                        res = Math.Min(res, costs[s.Length, i]);
                    }
                }

                return res - 1;
            }
        }

        static void GenerateTest()
        {
            List<string> strings = new List<string>();
            using (StreamReader reader = new StreamReader("..\\..\\garbled_email_dictionary.txt"))
            {
                while (!reader.EndOfStream)
                {
                    strings.Add(reader.ReadLine());
                }
            }

            Random rand = new Random(0);
            StringBuilder sb = new StringBuilder();
            while (sb.Length < 5000)
            {
                sb.Append(strings[rand.Next(strings.Count)]);
            }

            int last = -5;
            for (int i = 0; i < sb.Length; i++)
            {
                if (rand.Next(2) < 1 && i - last >= 5)
                {
                    sb[i] = (char)(rand.Next(26) + 'a');
                    last = i;
                }
            }

            Solver s = new Solver();
            Console.WriteLine(s.Solve(sb.ToString()));
        }

        static void Main(string[] args)
        {
            //string filename = "sample";
            //string filename = "C-small-attempt0";
            string filename = "C-large";
            using (StreamReader reader = new StreamReader("..\\..\\" + filename + ".in"))
            {
                using (StreamWriter writer = new StreamWriter("..\\..\\" + filename + ".out"))
                {
                    int T = Int32.Parse(reader.ReadLine());
                    Solver solver = new Solver();
                    for (int i = 0; i < T; i++)
                    {
                        Console.Error.WriteLine("Test " + i);
                        string s = reader.ReadLine();
                        writer.WriteLine("Case #" + (i + 1) + ": " + solver.Solve(s));
                    }
                }
            }
        }
    }
}
