using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace CodeJamSharp
{

    class Program
    {
        [Flags]
        enum TreeItem
        {
            VAL_0 = 0,
            VAL_1 = 1,

            OR = 2,
            AND = 3,

            CHANGE = 8,
            OR_C = CHANGE+OR,
            AND_C = CHANGE + AND
        };

        const int Impossible = 20000;

        static TreeItem[] btree;


        static Dictionary<int, int> cache;
        static int search(int pos, int V)
        {
            int key = pos * 5 + V;
            int ret;
            if (cache.TryGetValue(key, out ret))
            {
                return ret;
            }

            switch (btree[pos])
            {
                case TreeItem.VAL_0:
                    if (V == 0) ret = 0; else ret = Impossible;
                    break;
                case TreeItem.VAL_1:
                    if (V == 1) ret = 0; else ret = Impossible;
                    break;
                case TreeItem.OR:
                    if (V == 0)
                    {
                        ret = search(pos * 2 + 1, 0) + search(pos * 2 + 2, 0);
                    }
                    else
                    {
                        ret = Math.Min(search(pos * 2 + 1, 1), search(pos * 2 + 2, 1));
                    }
                    break;
                case TreeItem.AND:
                    if (V == 1)
                    {
                        ret = search(pos * 2 + 1, 1) + search(pos * 2 + 2, 1);
                    }
                    else
                    {
                        ret = Math.Min(search(pos * 2 + 1, 0), search(pos * 2 + 2, 0));
                    }
                    break;
                case TreeItem.AND_C:
                    if (V == 1)
                    {
                        // No change
                        ret = search(pos * 2 + 1, 1) + search(pos * 2 + 2, 1);
                        // Change to OR
                        ret = Math.Min(ret, 1 + Math.Min(search(pos * 2 + 1, 1), search(pos * 2 + 2, 1)));
                    }
                    else
                    {
                        // No change AND = 0
                        ret = Math.Min(search(pos * 2 + 1, 0), search(pos * 2 + 2, 0));
                        // Change to OR = 0
                        ret = Math.Min(ret, 1 + search(pos * 2 + 1, 0) + search(pos * 2 + 2, 0));
                    }
                    break;
                case TreeItem.OR_C:
                    if (V == 1)
                    {
                        // No change
                        ret = Math.Min(search(pos * 2 + 1, 1), search(pos * 2 + 2, 1));
                        // Change to AND
                        ret = Math.Min(ret, 1 + search(pos * 2 + 1, 1) + search(pos * 2 + 2, 1));
                    }
                    else
                    {
                        // No change OR = 0
                        ret = search(pos * 2 + 1, 0) + search(pos * 2 + 2, 0);
                        // Change to AND = 0
                        ret = Math.Min(ret, 1 + Math.Min(search(pos * 2 + 1, 0), search(pos * 2 + 2, 0)));
                    }
                    break;
                default:
                    Debug.Assert(false, "Incorrect tree");
                    break;
            }
            cache[key] = ret;
            return ret;
        }

        static void Main(string[] args)
        {
            using (StreamReader sr = File.OpenText(@"C:\Google\A.in"))
            using (StreamWriter sout = File.CreateText(@"C:\Google\A.out"))
            {
                string line = sr.ReadLine();
                int cases = int.Parse(line);
                for (int cas = 1; cas <= cases; cas++)
                {
                    line = sr.ReadLine();
                    string[] items = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    int M = int.Parse(items[0]);
                    int V = int.Parse(items[1]);
                    btree = new TreeItem[M];
                    cache = new Dictionary<int, int>();
                    for (int i = 0; i < (M - 1) / 2; i++)
                    {
                        line = sr.ReadLine();
                        items = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                        int G = int.Parse(items[0]);
                        int C = int.Parse(items[1]);
                        if (G == 1)
                        {
                            btree[i] = TreeItem.AND;
                        }
                        else
                        {
                            btree[i] = TreeItem.OR;
                        }
                        if (C == 1)
                        {
                            btree[i] = (TreeItem)((int)btree[i] + TreeItem.CHANGE);
                        }
                    }
                    for (int i = (M-1)/2; i < M ; i++)
                    {
                        line = sr.ReadLine();
                        int IV = int.Parse(line);
                        if (IV == 1)
                        {
                            btree[i] = TreeItem.VAL_1;
                        }
                        else
                        {
                            btree[i] = TreeItem.VAL_0;
                        }
                    }
                    int min = search(0, V);
                    if (min < Impossible)
                    {
                        sout.WriteLine("Case #{0}: {1}", cas, min);
                    }
                    else
                    {
                        sout.WriteLine("Case #{0}: IMPOSSIBLE", cas);
                    }
                }
            }
        }
    }
}
