using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string filename = "C-large";
            //string filename = "C-small-attempt0";
            //string filename = "test";

            string[] inLine = File.ReadAllLines(filename + ".in");
            int T = Convert.ToInt32(inLine[0]);
            string[] outLine = new String[T];

            for (int t = 1; t <= T; t++)
            {
                int result = 0;
                string[] tmp = inLine[t].Split(' ');
                int A = Convert.ToInt32(tmp[0]);
                int B = Convert.ToInt32(tmp[1]);
                
                for (int n = A; n < B; n++)
                {
                    string sn = n.ToString();
                    List<int> appeardm = new List<int>();

                    for (int i = 0; i < sn.Length; i++)
                    {
                        string sm = sn.Substring(i) + sn.Substring(0, i);
                        int m = Convert.ToInt32(sm);
                        if (n < m && m <= B && !appeardm.Contains(m))
                        {
                            result++;
                            appeardm.Add(m);
                            //Console.WriteLine("(" + n.ToString() + ", " + m.ToString() + ")");
                        }
                    }
  
                }

                Console.WriteLine("Case #" + t.ToString() + ": " + result.ToString());
                outLine[t - 1] = "Case #" + t.ToString() + ": " + result.ToString();
            }

            File.WriteAllLines(filename + ".out", outLine);

        }
    }
}
