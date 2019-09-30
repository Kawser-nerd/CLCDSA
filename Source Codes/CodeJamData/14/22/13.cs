using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj14r1b
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = System.IO.File.ReadAllLines(@"C:\GCJ\B.in");
            int idx = 0;
            int t = int.Parse(lines[idx++]);
            TextWriter tw = new StreamWriter(@"C:\GCJ\B.out");
            for (int a = 0; a < t; a++)
            {
                string[] line = lines[idx++].Split(' ');
                int aa = int.Parse(line[0]);
                int bb = int.Parse(line[1]);
                int kk = int.Parse(line[2]);
                int ans = 0;
                for (int i = 0; i < aa; i++)
                {
                    for (int j = 0; j < bb; j++)
                    {
                        if ((j & i) < kk)
                        {
                            ans++;
                        }
                    }
                }

               
                    tw.WriteLine("Case #{0}: {1}", a + 1, ans);
            }
            tw.Close();
        }

    }
}
