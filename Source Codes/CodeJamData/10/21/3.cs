using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("input.txt");
            StreamWriter sw = new StreamWriter("output.txt");
            int t = Int32.Parse(sr.ReadLine());
            for (int tc = 0; tc < t; tc++)
            {
                HashSet<string> was = new HashSet<string>();
                int n, m;
                var s = sr.ReadLine().Split(' ');
                n = Int32.Parse(s[0]);
                m = Int32.Parse(s[1]);
                for (int i = 0; i < n; i++)
                {
                    var sa = sr.ReadLine().Split('/');
                    string now = "";
                    for (int j = 1; j < sa.Length; j++)
                    {
                        now += sa[j] + "/";
                        was.Add(now);
                    }
                }
                int ans = 0;
                for (int i = 0; i < m; i++)
                {
                    var sa = sr.ReadLine().Split('/');
                    string now = "";
                    for (int j = 1; j < sa.Length; j++)
                    {
                        now += sa[j] + "/";
                        if (!was.Contains(now))
                        {
                            ans++;
                            was.Add(now);
                        }
                    }
                }
                sw.Write("Case #{0}: ", tc + 1);
                sw.WriteLine(ans);
            }
            sw.Close();
        }
    }
}
