using System;
using System.Collections.Generic;
class Program
    {
        class Node<T>
        {
            private int m_height;
            private Node<T> m_parent;
            public T Item { get; private set; }
            private int m_size;
            public Node(T item)
            {
                m_height = 0;
                m_parent = this;
                Item = item;
                m_size = 1;
            }
            public int Size()
            {
                return Find().m_size;
            }
            public Node<T> Find()
            {
                if (m_parent == this) { return this; }
        
                Node<T> parent = m_parent.Find();
                m_parent = parent;
                return parent;
            }
            public static void Unite(Node<T> a, Node<T> b)
            {
                Node<T> p = a.Find();
                Node<T> q = b.Find();
                if (p == q) return;
                if (p.m_height < q.m_height)
                {
                    p.m_parent = q;
                    q.m_height = Math.Max(p.m_height + 1, q.m_height);
                    q.m_size = p.m_size + q.m_size;
                }
                else
                {
                    q.m_parent = p;
                    p.m_height = Math.Max(q.m_height + 1, p.m_height);
                    p.m_size = p.m_size + q.m_size;
                }
            }
        }
        static long comb2(int num)
        {
            return (long) num * (num - 1) / 2;
        }
    	static void Main(string[] args)
    	{
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]), m = int.Parse(input[1]);
            Node<int>[] nodes = new Node<int>[n];
            for (int i=0; i<n; i++) nodes[i] = new Node<int>(i);
            int[,] decayList = new int[m, 2];
            for (int i=0; i<m; i++)
            {
                string[] s = Console.ReadLine().Split(' ');
                decayList[i, 0] = int.Parse(s[0]) - 1;
                decayList[i, 1] = int.Parse(s[1]) - 1;
            }
            long[] ans = new long[m + 1];
            ans[m] = comb2(n);
            for (int i=m-1; i>=0; i--)
            {
                Node<int> n1 = nodes[decayList[i, 0]], n2 = nodes[decayList[i, 1]];
                int a = n1.Size(), b = n2.Size();
                Node<int>.Unite(n1, n2);
                int c = n1.Size();
                //Console.Error.WriteLine("c: " + c);
                if (c > a) ans[i] = ans[i + 1] - comb2(c) + comb2(a) + comb2(b);
                else ans[i] = ans[i + 1];
            }
            for (int i=1; i<=m; i++) Console.WriteLine(ans[i]);
        }
    }
    //mcs Main.cs
    //mono Main.exe