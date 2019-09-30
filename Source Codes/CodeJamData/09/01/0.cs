using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace C
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            string[] tokens = s.Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            int L = int.Parse(tokens[0]);
            int D = int.Parse(tokens[1]);
            int N = int.Parse(tokens[2]);
            string[] inputs = new string[D];
            for (int i = 0; i < D; i++)
            {
                inputs[i] = Console.ReadLine();
            }
            for (int i = 0; i < N; i++)
            {
                s = Console.ReadLine();
                List<string> ls = new List<string>();
                while (s.Length>0)
                {
                    if (s[0]=='(')
                    {
                        int t1 = s.IndexOf(')');
                        ls.Add(s.Substring(1,t1-1));
                        s = s.Substring(t1 + 1);
                    }
                    else
                    {
                        ls.Add(s.Substring(0,1));
                        s = s.Substring(1);
                    }
                }
                string[] ss = ls.ToArray();
                int[] cur = new int[D];
                for (int j = 0; j < D; j++)
                {
                    cur[j] = j;
                }
                for (int j = 0; j < L; j++)
                {
                    List<int> l = new List<int>();
                    bool[] flag = new bool[26];
                    foreach (var c in ss[j])
                    {
                        flag[c - 'a'] = true;
                    }
                    foreach (var i1 in cur)
                    {
                        if (flag[inputs[i1][j]-'a'])
                        {
                            l.Add(i1);
                        }
                    }
                    cur = l.ToArray();
                }
                Console.WriteLine("Case #" + (i + 1) + ": "+cur.Length);
                
            }

        }
    }
}
