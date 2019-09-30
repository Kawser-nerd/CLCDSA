using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace B
{
        class Word
        {
                public int[] c = new int[26];
                public int[] cp = new int[26];
                public int score = 0;
        }

        class Program
        {
                public int T, N, M;
                public string[] word;
                public string[] list;
                public Word[] wInfo;

                public void Calc(List<int> a, int k, string list)
                {
                        int[] app = new int[26];
                        for (int i=0; i<a.Count; i++)
                                for (int j=0; j<word[a[i]].Length; j++)
                                        app[word[a[i]][j]-'a']++;
                        while (k<list.Length && app[list[k]-'a']==0) k++;
                        if (k >= list.Length || app[list[k] - 'a'] == 0)
                                return;
                        int guess = list[k] - 'a';
                        for (int i=0; i<a.Count; i++)
                                if (wInfo[a[i]].c[guess]==0)
                                        wInfo[a[i]].score++;

                        Dictionary<int, List<int>> aDict = new Dictionary<int,List<int>>();
                        for (int i=0; i<a.Count; i++)
                        {
                                int key = wInfo[a[i]].cp[guess];
                                if (aDict.ContainsKey(key))
                                        aDict[key].Add(a[i]);
                                else
                                {
                                        aDict[key] = new List<int>();
                                        aDict[key].Add(a[i]);
                                }
                        }
                        foreach (int i in aDict.Keys)
                                Calc(aDict[i], k + 1, list);
                }

                public string Solve(int index)
                {
                        wInfo = new Word[word.Length];
                        for (int i = 0; i < word.Length; i++)
                        {
                                wInfo[i] = new Word();
                                for (int j = 0; j < word[i].Length; j++)
                                {
                                        wInfo[i].c[word[i][j] - 'a']++;
                                        wInfo[i].cp[word[i][j] - 'a'] += (1 << j);
                                }
                        }

                        List<int>[] a = new List<int>[11];
                        for (int i = 1; i <= 10; i++)
                        {
                                a[i] = new List<int>();
                                for (int j = 0; j < word.Length; j++)
                                        if (word[j].Length == i) a[i].Add(j);
                                if (a[i].Count > 0)
                                        Calc(a[i], 0, list[index]);
                        }

                        int ret = 0;
                        for (int i = 0; i < wInfo.Length; i++)
                                if (wInfo[i].score > wInfo[ret].score)
                                        ret = i;
                        return word[ret];
                }

                static void Main(string[] args)
                {
                        Program p = new Program();

                        StreamReader sr = new StreamReader(@"D:\Train\GCJ2011\Round1\B-large.in");
                        StreamWriter sw = new StreamWriter(@"D:\Train\GCJ2011\Round1\out.txt");
                        string line = sr.ReadLine();
                        p.T = int.Parse(line);
                        for (int i = 1; i <= p.T; i++)
                        {
                                line = sr.ReadLine();
                                string[] item = line.Split(new char[] { ' ' });
                                p.N = int.Parse(item[0]);
                                p.M = int.Parse(item[1]);
                                p.word = new string[p.N];
                                p.list = new string[p.M];
                                for (int j = 0; j < p.N; j++)
                                        p.word[j] = sr.ReadLine();
                                for (int j = 0; j < p.M; j++)
                                        p.list[j] = sr.ReadLine();
                                sw.Write("Case #{0}:", i);
                                for (int j=0; j<p.M; j++)
                                        sw.Write(" {0}", p.Solve(j));
                                sw.WriteLine();
                                Console.WriteLine(i);
                        }
                        sw.Close();
                        sr.Close();
                }
        }
}
