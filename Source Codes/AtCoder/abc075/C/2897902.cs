using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ForBlue.ABC_075
{
    class C
    {
        static int n;
        static Node[] nodes;

        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            n = int.Parse(input[0]);
            int m = int.Parse(input[1]);
            nodes = new Node[n];
            for (int i = 0; i < n; i++)
            {
                nodes[i] = new Node();
            }
            for (int i = 0; i < m; i++)
            {
                string[] inText = Console.ReadLine().Split(' ');
                int a = int.Parse(inText[0]) - 1;
                int b = int.Parse(inText[1]) - 1;
                nodes[a].to.Add(b);
                nodes[b].to.Add(a);
            }

            long cnt = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < nodes[i].to.Count; j++)
                {
                    int toTemp = nodes[i].to[0];
                    if (toTemp < i) continue;

                    for (int k = 0; k < nodes.Length; k++)
                    {
                        nodes[k].wasVisited = false;
                    }

                    nodes[i].to.RemoveAt(0);
                    nodes[toTemp].to.Remove(i);

                    nodes[0].wasVisited = true;
                    int visitCnt = 1;
                    if (!DFS(0, ref visitCnt))
                    {
                        //Console.WriteLine(i.ToString() + " " + toTemp.ToString());
                        cnt++;
                    }

                    nodes[i].to.Add(toTemp);
                    nodes[toTemp].to.Add(i);
                }
            }

            Console.WriteLine(cnt);
        }

        static bool DFS(int index, ref int visitCnt)
        {
            if (visitCnt == n)//?????
            {
                return true;
            }

            //???????
            for (int i = 0; i < nodes[index].to.Count; i++)
            {
                if (!nodes[nodes[index].to[i]].wasVisited)
                {
                    visitCnt++;
                    nodes[nodes[index].to[i]].wasVisited = true;
                    if (DFS(nodes[index].to[i], ref visitCnt))
                    {
                        return true;
                    }
                }
            }
            //Console.WriteLine(visitCnt);
            return false;
        }
    }

    class Node
    {
        public List<int> to;
        public bool wasVisited;

        public Node()
        {
            to = new List<int>();
            wasVisited = false;
        }
    }
}