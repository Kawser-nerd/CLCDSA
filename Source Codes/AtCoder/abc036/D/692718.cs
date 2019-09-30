using System;
using System.Linq;
using System.Numerics;
using System.Collections.Generic;

namespace ABC036D
{
    class Program
    {
        public class Node
        {
            public ulong n;
            public BigInteger f;
            public BigInteger g;
            public LinkedList<ulong> link;
            public Node(ulong n)
            {
                this.n = n;
                f = 0;
                g = 0;
                link = new LinkedList<ulong>();
            }

            public BigInteger calcf(ulong from)
            {
                if (f > 0)
                    return f;

                f = 1;
                foreach(var v in link)
                    if (from != v)
                        f *= node[v].calcg(n);

                f += calcg(from);
                return f;
            }

            public BigInteger calcg(ulong from)
            {
                if (g > 0)
                    return g;

                g = 1;
                foreach (var v in link)
                    if (from != v)
                        g *= node[v].calcf(n);

                return g;
            }
        }

        static Node[] node;

        static void Main(string[] args)
        {
            BigInteger mod = 1000000007;

            ulong n = ulong.Parse(Console.ReadLine());
            node = new Node[n];
            for (ulong i = 0; i < n; i++)
                node[i] = new Node(i);
            for (ulong i = 0; i < n - 1; i++)
            {
                ulong[] bridge = Console.ReadLine().Split(' ').Select(ulong.Parse).ToArray();
                node[bridge[0] - 1].link.AddLast(bridge[1] - 1);
                node[bridge[1] - 1].link.AddLast(bridge[0] - 1);
            }
            Console.WriteLine(node[0].calcf(0) % mod);
#if DEBUG
            Console.ReadKey();
#endif
        }
    }
}