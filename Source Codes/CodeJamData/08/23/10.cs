using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;

class Problem
{
    const string inFile = "..\\..\\c-small.in";
    const string outFile = "..\\..\\c-small.out";

    public void Process()
    {
        using (StreamReader sr = new StreamReader(inFile))
        {
            using (StreamWriter sw = new StreamWriter(outFile))
            {
                int numCases = int.Parse(sr.ReadLine());
                for (int cas = 1; cas <= numCases; cas++)
                {
                    int k = int.Parse(sr.ReadLine());
                    int[] ss = Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), int.Parse);
                    string res = Solve(k, ss);
                    sw.WriteLine("Case #{0}:{1}", cas, res);
                }
            }
        }
    }

    string Solve(int k, int[] _a)
    {
        int n = _a[0];
        int[] a = new int[_a.Length - 1];
        Array.Copy(_a, 1, a, 0, a.Length);
        
        int[] b = new int[k];

        LinkedList<int> f = new LinkedList<int>();
        for (int i = 0; i < k; i++)
        {
            f.AddLast(i);
        }

        LinkedListNode<int> index = f.First;

        for (int need = 0; need < k; ++need)
        {
            int left = f.Count;
            int iter = need % left;
            for (int i = 0; i < iter; i++)
            {
                if (index.Next == null)
                    index = f.First;
                else
                    index = index.Next;
            }

            int t = index.Value;
            b[t] = need + 1;

            if (index == f.First)
            {
                index = index.Next;
                f.RemoveFirst();
            }
            else if (index == f.Last)
            {
                index = f.First;
                f.RemoveLast();
            }
            else
            {
                LinkedListNode<int> prev = index;
                index = index.Next;
                f.Remove(prev);
            }
        }

        int[] res = new int[n];
        string s = "";
        for (int i = 0; i < n; i++)
        {
            res[i] = b[a[i]-1];
            s += " " + res[i];
        }

        return s;
    }

    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}