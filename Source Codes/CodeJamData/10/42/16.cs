using System;
using System.IO;

namespace ProblemB
{
    class Program
    {
        class Node
        {
            Node l;
            Node r;
            bool b;

            public void Add(int val, int len, int cnt)
            {
                if (len > 0)
                {
                    if (cnt > 0)
                    {
                        b = true;
                    }
                    if (((val >> (len - 1)) & 1) == 0)
                    {
                        if (l == null)
                        {
                            l = new Node();
                        }
                        l.Add(val, len - 1, cnt - 1);
                    }
                    else
                    {
                        if (r == null)
                        {
                            r = new Node();
                        }
                        r.Add(val, len - 1, cnt - 1);
                    }
                }
            }

            public int Count()
            {
                int res = b ? 1 : 0;
                if (l != null)
                {
                    res += l.Count();
                }
                if (r != null)
                {
                    res += r.Count();
                }
                return res;
            }
        }

        static int Solve(int p, int[] miss)
        {
            Node root = new Node();
            for (int i = 0; i < (1 << p); i++)
            {
                root.Add(i, p, p - miss[i]);
            }
            return root.Count();
        }

        static void Main(string[] args)
        {
            using (StreamWriter writer = new StreamWriter("..\\..\\output.txt"))
            {
                using (StreamReader reader = new StreamReader("..\\..\\input.txt"))
                {
                    int total = Int32.Parse(reader.ReadLine());
                    for (int i = 0; i < total; i++)
                    {
                        int p = Int32.Parse(reader.ReadLine());
                        string[] temp = reader.ReadLine().Split();
                        int[] miss = new int[1 << p];
                        for (int j = 0; j < miss.Length; j++)
                        {
                            miss[j] = Int32.Parse(temp[j]);
                        }
                        for (int j = 0; j < p; j++)
                        {
                            reader.ReadLine();
                        }
                        int ans = Solve(p, miss);
                        writer.WriteLine("Case #" + (i + 1) + ": " + ans);
                    }
                }
            }
        }
    }
}