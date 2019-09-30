using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Numerics;

namespace D
{
    public class Node
    {
        public Dictionary<char, Node> children = new Dictionary<char,Node>();
    }

    class Program
    {
        static HashSet<string>[] B;
        static int N, M;
        static string[] S;
        static int worst;
        static int c_worst;

        static int Trie(HashSet<string> ss)
        {
            int total = 1;
            Node root = new Node();
            foreach (var s in ss)
            {
                Node current = root;
                foreach (var c in s)
                {
                    if (current.children.ContainsKey(c))
                        current = current.children[c];
                    else
                    {
                        Node n = new Node();
                        current.children[c] = n;
                        current = n;
                        total++;
                    }
                }
            }

            return total;
        }

        static void Place(int s)
        {
            if (s >= M)
            {
                for (int i = 0; i < N; i++)
                    if (!B[i].Any())
                        return;

                int total = 0;
                for (int i = 0; i < N; i++)
                    total += Trie(B[i]);

                if (total > worst)
                {
                    worst = total;
                    c_worst = 1;
                }
                else if (total == worst)
                {
                    c_worst++;
                }

                return;
            }

            for (int i = 0; i < N; i++)
            {
                B[i].Add(S[s]);
                Place(s + 1);
                B[i].Remove(S[s]);
            }
        }

        static void Solve()
        {
            B = new HashSet<string>[N];
            for (int i = 0; i < N; i++)
                B[i] = new HashSet<string>();
            worst = -1;
            c_worst = 0;
            Place(0);

            Console.WriteLine("{0} {1}", worst, c_worst);
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] line = Console.ReadLine().Split();
                M = int.Parse(line[0]);
                N = int.Parse(line[1]);
                S = new string[M];

                for (int i = 0; i < M; i++)
                    S[i] = Console.ReadLine();

                Console.Write("Case #{0}: ", t);
                Solve();
            }
        }
    }
}
