using System;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Trie_Sharding
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            const string filename = @"..\..\D-small-attempt0.in";
            //const string filename = @"..\..\B-large.in";

            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (var reader = new StreamReader(filename))
            {
                using (var writer = new StreamWriter(filename.Replace(".in", ".out"), false))
                {
                    int n = int.Parse(reader.ReadLine());
                    for (int i = 1; i <= n; i++)
                    {
                        Console.Write("N=" + i + " Time=");
                        Process(i, reader, writer);
                        Console.WriteLine((DateTime.Now - current).ToString().Substring(4));
                        current = DateTime.Now;
                    }
                }
            }

            Console.WriteLine("Time=" + (DateTime.Now - begin));
            Console.ReadLine();
        }

        private static void Process(int Case, TextReader reader, TextWriter writer)
        {
            string[] ss = reader.ReadLine().Split(' ');
            int m = int.Parse(ss[0]);
            int n = int.Parse(ss[1]);

            var mm = new string[m];
            for (int i = 0; i < m; i++)
            {
                mm[i] = reader.ReadLine();
            }

            long maxCount = 0;
            long numberOfWays = 0;
            for (int k = 0; k < Math.Pow(n, m); k++)
            {
                var tries = new Trie[n];
                for (int i = 0; i < n; i++)
                {
                    tries[i] = new Trie();
                }

                int where = k;
                for (int i = 0; i < m; i++)
                {
                    tries[where%n].add(mm[i]);
                    where /= n;
                }

                long totalCount = 0;
                for (int i = 0; i < n; i++)
                {
                    totalCount += tries[i].getCountNodes();
                }
                if (totalCount > maxCount)
                {
                    maxCount = totalCount;
                    numberOfWays = 1;
                }
                else if (totalCount == maxCount)
                {
                    numberOfWays++;
                }
            }

            Console.WriteLine("Case #{0}: {1} {2}", Case, maxCount, numberOfWays);
            writer.WriteLine("Case #{0}: {1} {2}", Case, maxCount, numberOfWays);
        }

        #region Nested type: Trie

        internal class Trie
        {
            private readonly TrieNode root = new TrieNode();
            private long countNodes;
            private int empty;

            public void add(String str)
            {
                empty = 1;
                TrieNode current = root;
                for (int i = 0; i < str.Length; i++)
                {
                    int index = str[i] - 'A';
                    if (current.nodes[index] == null)
                    {
                        current.nodes[index] = new TrieNode();
                        countNodes++;
                    }
                    current = current.nodes[index];
                }
            }

            public long getCountNodes()
            {
                return countNodes + empty;
            }
        }

        #endregion

        #region Nested type: TrieNode

        internal class TrieNode
        {
            public TrieNode[] nodes = new TrieNode[26];
        }

        #endregion
    }
}