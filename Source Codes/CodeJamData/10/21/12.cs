using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace codejam10cs
{
    class Processor
    {
        public void Init()
        {
            
        }

        public void Run(string fileName, string outputFileName)
        {
            using (StreamReader sr = new StreamReader(fileName))
            {
                using (StreamWriter sw = new StreamWriter(outputFileName))
                {
                    int T = int.Parse(sr.ReadLine().Trim());
                    for (int cases = 0; cases < T; cases++)
                    {
                        string[] l = sr.ReadLine().Trim().Split(' ');
                        int M = int.Parse(l[0]);
                        int N = int.Parse(l[1]);
                        HashSet<string> list = new HashSet<string>();
                        list.Add("");
                        for (int i=0; i<M; i++)
                        {
                            string s = sr.ReadLine().Trim();
                            if (!s.EndsWith("/")) s = s + "/";
                            int p = 0;
                            int q;
                            while ((p<s.Length) && ((q = s.IndexOf('/', p)) != -1))
                            {
                                list.Add(s.Substring(0, q));
                                p = q + 1;
                            }
                        }
                        int ans = 0;
                        for (int i = 0; i < N; i++)
                        {
                            string s = sr.ReadLine().Trim();
                            if (!s.EndsWith("/")) s = s + "/";
                            int p = 0;
                            int q;
                            while ((p < s.Length) && ((q = s.IndexOf('/', p)) != -1))
                            {
                                if (list.Add(s.Substring(0, q)))
                                {
                                    ans++;
                                }
                                p = q + 1;
                            }
                        }
                        sw.WriteLine("Case #{0}: {1}", cases+1, ans);
                    }
                }
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Processor pro = new Processor();
            pro.Init();
            pro.Run("A-large.in", "r1-a.out");
        }
    }
}
