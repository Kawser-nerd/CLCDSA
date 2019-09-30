using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Problem_A____Bot_Trust
{
    class Program
    {
        static void Main(string[] args)
        {
            new Program().Run();
        }

        private void Run()
        {
            StreamReader sr = new StreamReader("..\\..\\A-large.in");
            StreamWriter sw = new StreamWriter("..\\..\\out.txt");
            int T = int.Parse(sr.ReadLine());
            for(int i=1; i<=T; i++)
            {
                string s = sr.ReadLine();
                String[] ss = s.Split((char[])null, StringSplitOptions.RemoveEmptyEntries);
                int ans = Solve(ss);
                sw.WriteLine("Case #{0}: {1}", i, ans);
            }

            sw.Flush();
            sw.Close();
        }

        private int Solve(string[] ss)
        {
            int O = 1, B = 1, Ol = 0, Bl = 0;
            string prev = string.Empty;

            for (int i = 1; i < ss.Length; i += 2)
            {
                int nb = int.Parse(ss[i + 1]), d = 0;
                if (ss[i] == "O")
                {
                    d = Math.Abs(O - nb);
                    if (prev == "B")
                    {
                        Ol = Math.Max(Ol + d + 1, Bl + 1);
                    }
                    else
                    {
                        Ol += d + 1;
                    }
                    O = nb;
                }
                else
                {
                    d = Math.Abs(B - nb);
                    if (prev == "O")
                    {
                        Bl = Math.Max(Bl + d + 1, Ol + 1);
                    }
                    else
                    {
                        Bl += d + 1;
                    }
                    B = nb;
                }

                prev = ss[i];
            }

            return Math.Max(Ol, Bl);
        }
    }
}
