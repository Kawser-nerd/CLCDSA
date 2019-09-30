using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;

using Node = Node<string>;

class Node<T>
{
    public Node Parent;
    public List<Node> Child = new List<Node<string>>();
    public T Value;
    public Node(T c) { Value = c; }
}

class Problem
{
    const string inFile = "..\\..\\asmall.in";
    const string outFile = "..\\..\\asmall.out";

    const int INF = 987654321;

    public void Process()
    {
        using (StreamReader sr = new StreamReader(inFile))
        {
            using (StreamWriter sw = new StreamWriter(outFile))
            {
                int numCases = int.Parse(sr.ReadLine());
                Console.WriteLine("There are {0} test cases.", numCases);
                for (int @case = 1; @case <= numCases; @case++)
                {
                    int n = int.Parse(sr.ReadLine());
                    string[] a = new string[n];
                    for (int i = 0; i < n; i++)
                    {
                        a[i] = sr.ReadLine();
                    }

                    string res = Solve(a);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }

    string Solve(string[] a)
    {
        int n = a.Length;

        Dictionary<string, int> names = new Dictionary<string,int>();
        Node[] f = new Node<string>[n];
        for (int i = 0; i < n; i++)
        {
            string[] ss = a[i].Split(' ');
            names.Add(ss[0], i);
            f[i] = new Node<string>(ss[0]);
        }

        for (int i = 0; i < n; i++)
		{
            string[] ss = a[i].Split(' ');
            for (int j = 2; j < ss.Length; ++j)
            {
                string ing = ss[j];
                if (names.ContainsKey(ing))
                {
                    int t = names[ing];
                    f[i].Child.Add(f[t]);
                    f[t].Parent = f[i];
                }
            }
		}

        int res = n;

        int[] order = new int[n];
        for (int i = 0; i < n; i++)
        {
            order[i] = i;
        }

        do
        {
            bool[] done = new bool[n];
            bool good = true;

            int[] bow = new int[n];
            for (int i = 0; i < n; i++)
			{
                bow[i] = -1;
			}

            int[] hold = new int[n];

            int tem = 0;
            for (int i = 0; i < n; i++)
            {
                int t = order[i];
                for (int j = 0; j < f[t].Child.Count; ++j)
                {
                    int child = names[f[t].Child[j].Value];
                    if (!done[child])
                    {
                        good = false;
                        break;
                    }
                }
                if (good)
                {
                    // look for bow
                    int thisbow = -1;
                    for (int j = 0; j < tem; ++j)
                    {
                        if (bow[j] == -1)
                        {
                            bow[j] = t;
                            thisbow = j;
                            break;
                        }
                    }
                    if (thisbow == -1)
                    {
                        bow[tem] = t;
                        thisbow = tem;
                        tem++;
                    }

                    hold[t] = thisbow;
                    done[t] = true;

                    for (int j = 0; j < f[t].Child.Count; ++j)
                    {
                        int child = names[f[t].Child[j].Value];
                        int childHold = hold[child];
                        bow[childHold] = -1;
                    }
                }
                else break;
            }
            if (good) res = Math.Min(res, tem);
        }
        while (next(order));

        return res.ToString();
    }

    static bool next<T>(T[] a) where T : IComparable<T>
    {
        int n = a.Length;
        int i = n - 2;
        while (i >= 0 && a[i].CompareTo(a[i + 1]) >= 0) i--;
        if (i >= 0)
        {
            int j = n - 1; while (a[j].CompareTo(a[i]) <= 0) j--;
            T tem = a[j]; a[j] = a[i]; a[i] = tem;
            i++; j = n - 1;
            while (i < j)
            {
                tem = a[i]; a[i] = a[j]; a[j] = tem;
                i++; j--;
            }
            return true;
        }
        return false;
    }

    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}