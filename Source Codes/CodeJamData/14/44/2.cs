using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class TrieSharding : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string s = Console.ReadLine();
                int M = int.Parse(s.Split(' ')[0]);
                int N = int.Parse(s.Split(' ')[1]);
                string[] s2 = new string[M];
                for (int i = 0; i < M; i++)
                {
                    s2[i] = Console.ReadLine();
                }

                int maxNodes;
                int maxNodeWays;
                CalcMaxAndWays(N, M, s2, out maxNodes, out maxNodeWays);
                //long ret = 0;

                Console.WriteLine("Case #{0}: {1} {2}", iCase, maxNodes, maxNodeWays);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1} {2}", iCase, maxNodes, maxNodeWays);

                //string[] sOut = o.ProcessMulti(roads,city);
                //Console.WriteLine("Case #{0}:", iCase);
                //System.Diagnostics.Debug.WriteLine("Case #{0}:", iCase);
                //for (int j = 0; j < sOut.Length; j++) {
                //    Console.WriteLine(sOut[j]);
                //    System.Diagnostics.Debug.WriteLine(sOut[j]);
                //}
            }

            if (bManual) Console.ReadKey();
        }

        private void CalcMaxAndWays(int N, int M, string[] words, out int maxNodes, out int maxNodeWays)
        {
            //long MOD = 1000000007;
            List<Node> allNodes = new List<Node>();

            Node[] root = new Node[26];
            Node[] curptr;
            for (int i = 0; i < M; i++)
            {
                curptr = root;
                Node parent = null;
                for (int j = 0; j < words[i].Length; j++)
                {
                    char c = words[i][j];
                    int cidx = c-'A';
                    if (curptr[cidx] == null)
                    {
                        Node newNode = new Node();
                        newNode.Let = c;
                        newNode.Parent = parent;
                        newNode.children = new Node[26];
                        curptr[cidx] = newNode;
                        allNodes.Add(newNode);
                    }

                    parent = curptr[cidx];
                    curptr = parent.children;
                }
            }


            int maxarr = (int)Math.Pow(N, M);
            int[] wordOwner = new int[M];
            maxNodes = 0;
            maxNodeWays = 0;
            for (int arr = 0; arr < maxarr; arr++)
            {
                int arr2 = arr;
                bool[] nonempty = new bool[N];
                for (int i = 0; i < M; i++)
                {
                    wordOwner[i] = arr2 % N;
                    nonempty[arr2 % N] = true;
                    arr2 /= N;
                }

                int totNodes = 0;
                for (int i = 0; i < N; i++)
                {
                    if (nonempty[i]) totNodes++;
                }


                for (int i = 0; i < M; i++)
                {
                    curptr = root;
                    Node parent = null;
                    for (int j = 0; j < words[i].Length; j++)
                    {
                        int cidx = words[i][j] - 'A';
                        parent = curptr[cidx];
                        curptr = parent.children;
                        if ((parent.Owners & 1 << wordOwner[i]) == 0)
                        {
                            totNodes++;
                            parent.Owners |= (1 << wordOwner[i]);
                        }
                    }
                }

                if (totNodes > maxNodes)
                {
                    maxNodes = totNodes;
                    maxNodeWays = 1;
                }
                else if (totNodes == maxNodes)
                {
                    maxNodeWays++;
                }

                foreach (Node node in allNodes)
                {
                    node.Owners = 0;
                }
            }
        }

        private class Node
        {
            public char Let;
            public Node Parent;
            public int Owners;
            public Node[] children;
        }
    }
}
