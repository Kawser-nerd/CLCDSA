using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Program
    {
        static int n;
        static Node[] nodes;
        static int[,] d;

        static void Main(string[] args)
        {
            int total = int.Parse(Console.ReadLine());
            for (int casen = 1; casen <= total; casen++)
            {
                int v;
                string s = Console.ReadLine();
                string[] buf = s.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                n = int.Parse(buf[0]);
                v = int.Parse(buf[1]);
                nodes = new Node[n + 1];
                d = new int[n + 1, 2];
                for (int i = 1; i <= (n - 1) / 2; i++)
                {
                    s = Console.ReadLine();
                    buf = s.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    nodes[i] = new Node { GateType = int.Parse(buf[0]), Changable = int.Parse(buf[1]), Value = -1 };
                    d[i,0] = d[i,1] = n+1;
                }
                for (int i = (n + 1) / 2; i <= n; i++)
                {
                    nodes[i] = new Node { Value = int.Parse(Console.ReadLine()) };
                    d[i, nodes[i].Value] = 0;
                    d[i, 1 - nodes[i].Value] = n+1;
                }

                for (int i = (n - 1) / 2; i >= 1; i--)
                {
                    int x1 = i * 2;
                    int x2 = i * 2 + 1;
                    for(int j=0; j<=1; j++)
                        if (d[x1, j] <= n)
                        {
                            for(int k=0; k<=1; k++)
                                if (d[x2, k] <= n)
                                {
                                    for (int op = 0; op <= 1; op++)
                                    {
                                        int value = Calc(op, j, k);
                                        if (op == nodes[i].GateType) d[i, value] = Math.Min(d[i, value], d[x1, j] + d[x2, k]);
                                        else if(nodes[i].Changable == 1) d[i, value] = Math.Min(d[i, value], d[x1, j] + d[x2, k] + 1);
                                    }
                                }
                        }
                }

                string output = "IMPOSSIBLE";
                if (d[1, v] <= n) output = d[1, v].ToString();
                Console.WriteLine("Case #{0}: {1}", casen, output);
            }
        }

        static int Calc(int op, int x, int y)
        {
            if (op == 1) return x & y;
            else return x | y;
        }
    }

    class Node
    {
        public int GateType;
        public int Changable;
        public int Value;
    }
}
